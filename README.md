# Time Utils
# Version 1.0.0 build

---

**Time Utils**, Sleep for an amount of time, get date and time information, stopwatch and timer

# Function references
## Sleep
**Last updated in version _1.0.0_**

```cpp
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
```

## Timer
**Last updated in version _1.0.0_**

```cpp

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
```

## Time
**Last updated in version _1.0.0_**

```cpp
/// Time - Constructor
/// Set the ID of the `Time` object
/// @param ID
Time(std::string ID);

/// Set UTC offset - Function
/// Set the offset of UTC according to your current timezone
/// @param hour
/// @param min
void setUTCOffset(int hour, unsigned int min);

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
```

## Stopwatch
**Last updated in version _1.0.0_**

```cpp
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
```

## General types

```cpp
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
```

