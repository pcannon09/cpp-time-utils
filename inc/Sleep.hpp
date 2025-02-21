#pragma once

#include "Sleep.hpp"

#include <string>

namespace timeUtils
{
    class Sleep
    {
    private:
        static std::string id;

    public:
        /// Sleep - Constructor
        /// @brief Create the `Sleep` object
        /// @param ID
        Sleep(std::string ID);

        /// Hours - Function
        /// @brief Sleep for (x) hours
        /// @param duration
        void hours(unsigned int duration);

        /// Hours - Function
        /// @brief Sleep for (x) minutes
        /// @param duration
        void minutes(unsigned int duration);

        /// Hours - Function
        /// @brief Sleep for (x) seconds
        /// @param duration
        void seconds(unsigned int duration);

        /// Hours - Function - Overload
        /// @brief Sleep for (x) decimal seconds
        /// @param duration
        void seconds(double duration);

        /// Hours - Function
        /// @brief Sleep for (x) milliseconds
        /// @param duration
        void milliseconds(unsigned int duration);

        /// Hours - Function
        /// @brief Sleep for (x) nanoseconds
        /// @param duration
        void nanoseconds(unsigned int duration);

        /// Get ID - Function
        /// Get the ID from this object
        /// @return std::string
        std::string getID();
    };
}
