#include <chrono>
#include <thread>

#include <iostream>

#include "../../inc/Stopwatch.hpp"

namespace tests
{
    int stopwatch()
    {
        std::cout << "Starting at 1min, 9secs\n";

        stt::Stopwatch watch("main");

        watch.setThread(true);
        watch.set({0, 1, 9, 0});
        watch.start();

        std::thread watchT([&watch]() {
            while (1)
            {
                std::cout << watch.get().hour;
                std::cout << " : " << watch.get().min;
                std::cout << " : " << watch.get().sec;
                std::cout << " : " << watch.get().ms << "\r" << std::flush;
            }
        });

        watchT.detach();

        std::this_thread::sleep_for(std::chrono::seconds(2));

        std::cout << "STOP\n";

        watch.stop();

        std::this_thread::sleep_for(std::chrono::seconds(2));

        std::cout << "START\n";

        watch.start();

        std::this_thread::sleep_for(std::chrono::seconds(1));

        return 0;
    }
}

