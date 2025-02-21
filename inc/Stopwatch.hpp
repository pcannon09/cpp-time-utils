#pragma once

#include "Stopwatch.hpp"

#include <string>
#include <chrono>
#include <atomic>

#include "../inc/types.hpp"

namespace timeUtils
{
    class Stopwatch
    {
    private:
        static std::string id;
        
        static bool hasThread;

        static std::atomic<TimerStopwatchState> isRunning;

        static Timestamp progress;
        static Timestamp addProgress;

        static std::atomic<bool> threadActive;

        static std::chrono::high_resolution_clock::time_point startTime;
        std::chrono::milliseconds elapsedTime;

        void counter();

    public:
        /// Stopwatch - Constructor
        /// @brief Set the ID of the stopwatch
        /// @param id
        Stopwatch(std::string id);
        
        /// Stopwatch - Deconstructor
        /// @brief Call the `Stopwatch::deleteWatch()` function to stop the stopwatch
        ~Stopwatch();

        /// Get ID - Function
        /// @brief Get the ID of the Stopwatch
        /// @return std::string
        std::string getID();

        /// Set Thread - Function
        /// @brief Set if it should use a separate thread when running the stopwatch
        /// @param toCreate
        void setThread(bool toCreate);

        /// Start - Function
        /// @brief Start the stopwatch
        void start();

        /// Stop - Function
        /// @brief Stop ( Pause ) the stopwatch
        void stop();

        /// Reset - Function
        /// @brief Reset the timer to its starting value
        void reset();

        /// Reset - Function
        /// @brief Delete the watch and reset everything
        void deleteWatch();

        /// Set - Function
        /// @brief Set the time according to the `Timestamp`
        /// @param time
        void set(Timestamp time);

        /// Get - Function
        /// @brief Get the current timestamp from this watch
        /// @return timestamp
        Timestamp get();

        /// Get Is Running - Function
        /// @brief Get if the timer is running
        /// @return TimerStopwatchState 
        TimerStopwatchState getIsRunning();
    };
}
