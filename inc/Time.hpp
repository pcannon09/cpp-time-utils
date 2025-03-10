#pragma once

#include "../inc/macros.hpp"

// #if __cplusplus >= 201103L
#if __cplusplus >= 199711L

#include <string>

#include "../inc/types.hpp"

namespace timeUtils
{
    class Time
    {
    private:
        static std::string id;

        static int utcHourOffset;
        static unsigned int utcMinOffset;

        static int addHourOffset;
        static unsigned int addMinOffset;

        static DateInfo dateInfo;

    public:
        /// Time - Constructor
        /// Set the ID of the `Time` object
        /// @param ID
        Time(std::string ID);

        /// Set UTC offset - Function
        /// Set the offset of UTC
        /// @param hour
        /// @param min
        void setUTCOffset(int hour, unsigned int min);

        /// Set UTC offset - Function
        /// Set the offset according to your current timezone
        /// @param hour
        /// @param min
        void addOffset(int hour, unsigned int min);

        /// Get UTC Offset - Function
        /// Get the previously added UTC offset
        TimeOffset getUTCOffset();

        /// Get Add Offset - Function
        /// Get the previously added offset
        TimeOffset getAddOffset();

        /// Get Days In Month
        /// @brief Get the days in the current month
        unsigned int getDaysInMonth();

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

#else
namespace timeUtils
{
    class Time
    { };
}

#   warning "Current CXX standard not fully supported"
#   pragma message("CXX Standard: " TOSTRING(__cplusplus))

#endif

