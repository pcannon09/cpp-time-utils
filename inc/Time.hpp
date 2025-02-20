#pragma once

#include "Time.hpp"

#include <string>

namespace stt
{
    typedef struct DateInfo
    {
        unsigned int year, month, day, weekDay, yearDay;
    } DateInfo;

    typedef struct TimeZoneInfo
    {
        bool isDST;
        bool gmtOff;

        std::string timezone;
        std::string utcTimezone;
    } TimeZoneInfo;

    typedef struct TimeInfo
    {
        unsigned int hour, min, sec, ms;

        bool isAm;
        bool is12hFormat;
    } TimeInfo;

    class Time
    {
    private:
        static std::string id;

    public:
        Time(std::string ID);

        int update(TimeInfo &info);
        int update(TimeZoneInfo &info);
        int update(DateInfo &info);

        bool set12hFormat(bool set12hFormat);

        std::string getID();
    };
}

