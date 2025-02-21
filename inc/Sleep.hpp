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
        Sleep(std::string ID);

        void hours(unsigned int duration);
        void minutes(unsigned int duration);
        void seconds(unsigned int duration);
        void seconds(double duration);
        void milliseconds(unsigned int duration);
        void nanoseconds(unsigned int duration);

        std::string getID();
    };
}
