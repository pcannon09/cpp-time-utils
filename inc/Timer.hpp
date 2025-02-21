#pragma once

#include "Timer.hpp"

#include <string>
#include <chrono>
#include <atomic>

#include "../inc/types.hpp"

namespace timeUtils
{
    typedef struct Timestamp
    {
        unsigned int hour, min, sec, ms;
    } Timestamp;

    class Timer
    {
    private:
        static std::string id;
        
        static bool hasThread;
        static bool finished;

        static std::atomic<TimerStopwatchState> isRunning;

        static Timestamp progress;
        static Timestamp addProgress;
        static Timestamp duration;

        static unsigned long long targetDurationMs;

        static std::atomic<bool> threadActive;

        static std::chrono::high_resolution_clock::time_point startTime;
        std::chrono::milliseconds elapsedTime;

        /// Counter - Function
        /// @brief Count the timer
        void counter();

        /// Timestamp to Milliseconds - Function
        /// @brief `Timestamp` datatype to milliseconds
        unsigned long long timestampToMS(Timestamp ts);

    public:
        /// Timer - Constructor
        /// @brief Set the ID of the timer
        /// @param id
        /// @param duration
        Timer(std::string id, Timestamp duration);
        
        /// Timer - Deconstructor
        /// @brief Call the `Timer::deleteTimer()` function to stop the timer
        ~Timer();

        /// Set Duration - Function
        /// Set the duration of the timer
        void setDuration(Timestamp timer);

        /// Get ID - Function
        /// @brief Get the ID of the Timer
        /// @return std::string
        std::string getID();

        /// Set Thread - Function
        /// @brief Set if it should use a separate thread when running the timer
        /// @param toCreate
        void setThread(bool toCreate);

        /// Start - Function
        /// @brief Start the timer
        void start();

        /// Stop - Function
        /// @brief Stop ( Pause ) the timer
        void stop();

        /// Reset - Function
        /// @brief Reset the timer to its starting value
        void reset();

        /// Reset - Function
        /// @brief Delete the timer and reset everything
        void deleteTimer();

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

        /// Is Finished - Function
        /// @brief Get if the timer is finished
        /// @return bool
        bool isFinished();
    };
}
