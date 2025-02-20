#include <string>
#include <ctime>
#include <chrono>
#include <iomanip>
#include <sstream>

#include "../inc/Time.hpp"

namespace stt
{
    std::string Time::id;

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

            std::ostringstream oss;

            oss << (hours >= 0 ? "+" : "") << hours
                << ":" << std::setw(2) << std::setfill('0') << mins;

            info.utcTimezone = oss.str();

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

            info.hour = (info.is12hFormat) ? 
                    (local->tm_hour >= 12) ? local->tm_hour - 12 : local->tm_hour
                : local->tm_hour;

            info.min = local->tm_min;
            info.sec = local->tm_sec;
            info.isAm = (local->tm_hour < 12) ? true : false;
            info.ms = ms.count();

            return 0;
        }

        return -1;
    }

    bool Time::set12hFormat(bool set12hFormat)
    { return set12hFormat; }

    std::string Time::getID()
    { return this->id; }
}

