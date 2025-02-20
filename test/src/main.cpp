#include <iostream>

#include "../../test/inc/stopwatch.hpp"

int main()
{
    std::string answer;

    std::cout << "What test do you want to run? Timer (timer), time (time) or stopwatch (stopwatch)\n>>> ";
    std::cin >> answer;
    
    if (answer == "stopwatch")
    {
        std::cout << "Starting **Stopwatch** test\n";

        return tests::stopwatch();
    }

    else if (answer == "timer")
    {

    }

    else if (answer == "time")
    {
        
    }

    else 
    {
        std::cerr << "Unknown test\n";

        return -1;
    }

    return 0;
}

