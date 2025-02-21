#pragma once

#include "Time.hpp"

#include <string>

namespace timeUtils
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

        static int utcHourOffset;
        static unsigned int utcMinOffset;

    public:
        /// Time - Constructor
        /// Set the ID of the `Time` object
        /// @param ID
        Time(std::string ID);

        /// Set UTC offset - Function
        /// Set the offset of UTC according to your current timezone
        /// @param hour
        /// @param min
        void setUTCOffset(int hour, unsigned int min);

        /// Update - Function
        /// Set the Time information and return if it was a success (0) or not (-1)
        /// @param info
        int update(TimeInfo &info);

        /// Update - Function - Overload
        /// Set the Timezone information and return if it was a success (0) or not (-1)
        /// @param info
        int update(TimeZoneInfo &info);

        /// Update - Function - Overload
        /// Set the Date information and return if it was a success (0) or not (-1)
        /// @param info
        /// @return int
        int update(DateInfo &info);

        /// Set 12 Hour Format - Function
        /// Set if it should use the 12 hour format
        /// @return bool
        bool set12hFormat(bool set12hFormat);

        /// Get ID - Function
        /// Get the ID for the `Time` object
        /// @return std::string
        std::string getID();
    };
}

