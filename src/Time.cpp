#include <string>
#include <ctime>
#include <chrono>

#include "../inc/Time.hpp"

namespace timeUtils
{
    std::string Time::id;

    int Time::utcHourOffset;
    unsigned int Time::utcMinOffset;

    Time::Time(std::string ID)
    { this->id = ID; }

    // TIME
    int Time::update(DateInfo &info)
    {
        std::time_t now = std::time(nullptr);
        std::tm *local = std::localtime(&now);

        if (local)
        {
            info.year = local->tm_year + 1900;
            info.month = local->tm_mon + 1;
            info.day = local->tm_mday;
            info.weekDay = local->tm_wday;
            info.yearDay = local->tm_yday;

            return 0;
        }

        return -1;
    }

    // TIME ZONE
    int Time::update(TimeZoneInfo &info)
    {
        std::time_t now = std::time(nullptr);
        std::tm *local = std::localtime(&now);
        std::tm *utc = std::gmtime(&now);

        if (local && utc)
        {
            int  utcOffsetSecs = std::difftime(std::mktime(local), std::mktime(utc));

            int hours = (utcOffsetSecs) / 3600;
            int mins = (utcOffsetSecs % 3600) / 60;

            info.timezone = local->tm_zone;
            info.isDST = local->tm_isdst;
            info.gmtOff = local->tm_gmtoff;

            info.utcTimezone = {std::to_string(hours), std::to_string(mins)};

            return 0;
        }

        return -1;
    }

    // DATE
    int Time::update(TimeInfo &info)
    {
        std::time_t now = std::time(nullptr);
        std::tm *local = std::localtime(&now);

        if (local)
        {
            auto now = std::chrono::system_clock::now();

            auto duration = now.time_since_epoch();
            auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(duration) % 1000;

            int adjHour = local->tm_hour + this->utcHourOffset;
            int adjMin = local->tm_min + this->utcMinOffset;

            if (adjMin >= 60)
            {
                adjHour += adjMin / 60;
                adjMin %= 60;
            }

            if (adjHour >= 24)
            { adjHour %= 24; }

            else if (adjHour < 0)
            { adjHour += 24; }

            info.hour = (info.is12hFormat) ? 
                        ((adjHour == 0 || adjHour == 12) ? 12 : adjHour % 12)
                      : adjHour;
                      
            info.min = adjMin;
            info.sec = local->tm_sec;
            info.ms = ms.count();
            info.isAm = (adjHour < 12);

            return 0;
        }

        return -1;
    }

    void Time::setUTCOffset(int hour, unsigned int min)
    {
        this->utcHourOffset = hour;
        this->utcMinOffset = min;
    }

    bool Time::set12hFormat(bool set12hFormat)
    { return set12hFormat; }

    std::string Time::getID()
    { return this->id; }
}

