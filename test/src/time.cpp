#include <iostream>
#include <unistd.h>
#include <chrono>
#include <thread>

#include "../../inc/Time.hpp"

namespace tests
{
    int time()
    {
        timeUtils::Time time("main");

        timeUtils::TimeZoneInfo tzInfo;
        timeUtils::DateInfo dateInfo;
        timeUtils::TimeInfo timeInfo;

        time.setUTCOffset(5, 30);

        while (1)
        {
            time.update(tzInfo);
            time.update(dateInfo);
            time.update(timeInfo);

            timeInfo.is12hFormat = time.set12hFormat(true);

            std::cout
                << "- TIME ZONE INFO -\n"
                << "GMT Off? : " << tzInfo.gmtOff << "\n"
                << "Is DST? : " << tzInfo.isDST << "\n"
                << "Current timezone : " << tzInfo.timezone << "\n"
                << "Current UTC timezone : " << tzInfo.utcTimezone << "\n"

                << "- TIME INFO -\n"
                << "Hour: " << timeInfo.hour <<  "\n"
                << "Min : " << timeInfo.min << "\n"
                << "Sec : " << timeInfo.sec << "\n"
                << "MS : " << timeInfo.ms << "\n"
                << "Is AM? : " << timeInfo.isAm << "\n"
                << "Is 12 hour format? : " << timeInfo.is12hFormat << "\n"

                << "- DATE INFO -\n"
                << "Year : " << dateInfo.year << "\n"
                << "Month : " << dateInfo.month << "\n"
                << "Day : " << dateInfo.day << "\n"
                << "Week day : " << dateInfo.weekDay << "\n"
                << "Year day : " << dateInfo.yearDay << "\n"

                << "\r" << std::flush;

                std::this_thread::sleep_for(std::chrono::milliseconds(10));

                system("clear");
        }

        return 0;
    }
}
