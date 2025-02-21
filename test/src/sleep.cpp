#include <iostream>

#include "../../inc/Sleep.hpp"

namespace tests
{
    int sleep()
    {
        timeUtils::Sleep sleep("main");

        std::cout << "Sleeping for 1 sec\n";

        sleep.seconds(1u);

        std::cout << "Sleeping for 0.5 sec\n";

        sleep.seconds(0.5);

        std::cout << "Sleeping for 5 nanoseconds \n";

        sleep.nanoseconds(5);

        std::cout << "Sleeping for 1 minute\n";

        sleep.minutes(1);

        std::cout << "Sleeping for 1 hour\n";

        sleep.hours(1);

        return 0;
    }
}

