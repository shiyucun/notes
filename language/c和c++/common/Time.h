
#pragma once

#include <chrono>

struct Calendar {
    Calendar() = default;

    Calendar(int32_t year, int32_t month, int32_t day, int32_t hour, int32_t minute, int32_t second)
        : m_year(year), m_month(month), m_day(day),
          m_hour(hour), m_minute(minute), m_second(second) {}

    int32_t m_year{0};
    int32_t m_month{0};
    int32_t m_day{0};
    int32_t m_hour{0};
    int32_t m_minute{0};
    int32_t m_second{0};
    int32_t m_dayOfWeek{0};
    int32_t m_dayOfYear{0};
};

int64_t GetNowMillisecond() {
    auto time_point = std::chrono::system_clock::now();
    auto time_duration = time_point.time_since_epoch();

    return std::chrono::duration_cast<std::chrono::milliseconds>(time_duration).count();
}

int64_t GetNowMicrosecond() {
    auto time_point = std::chrono::system_clock::now();
    auto time_duration = time_point.time_since_epoch();

    return std::chrono::duration_cast<std::chrono::microseconds>(time_duration).count();
}

Calendar TimeToLocalCalendar(int64_t ms) {
    auto td = std::chrono::milliseconds(ms);
    auto tp = std::chrono::time_point<std::chrono::system_clock,
                                      std::chrono::milliseconds>(td);
    auto tt = std::chrono::system_clock::to_time_t(tp);
    auto lt = localtime(&tt);

    Calendar calendar;
    calendar.m_year = lt->tm_year + 1900;
    calendar.m_month = lt->tm_mon + 1;
    calendar.m_day = lt->tm_mday;
    calendar.m_hour = lt->tm_hour;
    calendar.m_minute = lt->tm_min;
    calendar.m_second = lt->tm_sec;
    calendar.m_dayOfWeek = lt->tm_wday;
    calendar.m_dayOfYear = lt->tm_yday;

    return calendar;
}

int64_t CalendarToLocalTime(Calendar &calendar) {
    tm lt{};
    lt.tm_year = calendar.m_year - 1900;
    lt.tm_mon = calendar.m_month - 1;
    lt.tm_mday = calendar.m_day;
    lt.tm_hour = calendar.m_hour;
    lt.tm_min = calendar.m_minute;
    lt.tm_sec = calendar.m_second;

    auto tt = mktime(&lt);
    auto tp = std::chrono::system_clock::from_time_t(tt);
    auto td = tp.time_since_epoch();
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(td).count();

    return ms;
}
