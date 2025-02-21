#pragma once

#include "types.hpp"

#include <string>
#include <vector>

namespace timeUtils
{
    /// TimerStopwatchState
    /// Get if the watch or stopwatch is paused, running or stopped
    /// Includes:
    /// FALSE, TRUE, PAUSED
    enum TimerStopwatchState
    {
        FALSE = 0,
        TRUE = 1,
        PAUSED = 2
    };

    /// Timestamp - typedef struct
    /// Timestamp datatype
    /// Includes:
    /// hour, min, sec, ms
    typedef struct Timestamp
    {
        unsigned int hour, min, sec, ms;
    } Timestamp;

    /// DateInfo - typedef struct
    /// Shows date information
    /// Includes:
    /// year, month, day, weekDay, yearDay
    typedef struct DateInfo
    {
        unsigned int year, month, day, weekDay, yearDay;
    } DateInfo;

    /// TimeZoneInfo - typedef struct
    /// Shows time zone information
    /// Includes
    /// isDST (Is Daylight Saving Time)
    /// gmtOff
    /// timezone (Ex: Spain, India, England, ...)
    /// utcTimezone (Timezone hour and min for utc ({hour, min}))
    typedef struct TimeZoneInfo
    {
        bool isDST;
        bool gmtOff;

        std::string timezone;

        std::vector<std::string> utcTimezone;
    } TimeZoneInfo;

    /// TimeInfo - typedef struct
    /// Shows time information
    /// Includes:
    /// Hour, min, sec, ms
    /// isAm (Is time < 12PM) and is12hFormat (Is format not 24 hour)
    typedef struct TimeInfo
    {
        unsigned int hour, min, sec, ms;

        bool isAm;
        bool is12hFormat;
    } TimeInfo;
}
