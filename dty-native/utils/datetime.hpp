/**
 * @file datetime.hpp(utils)
 * @author senyun.yao
 * @brief
 * @version 0.1
 * @date 2021-12-05
 *
 * @copyright aitianyu.cn Copyright (c) 2021
 *
 */

#ifndef __DTY_NATIVE_UTILS_DATETIME_H_PLUS_PLUS__
#define __DTY_NATIVE_UTILS_DATETIME_H_PLUS_PLUS__

#include"../utilize.h"

#define __DTY_NATIVE_DATETIME_MILLISECOND_TICKS__ 1
#define __DTY_NATIVE_DATETIME_SECOND_TICKS__      1000
#define __DTY_NATIVE_DATETIME_MINUTE_TICKS__      60000
#define __DTY_NATIVE_DATETIME_HOUR_TICKS__        3600000
#define __DTY_NATIVE_DATETIME_DAY_TICKS__         86400000

#ifdef __cplusplus
__CMODE__
{
#endif // !__cplusplus

    // =========================================
    // Tianyu DateTime C mode
    // =========================================
    typedef struct dty_native_c_datetime
    {
        uint64 __VARIABLE__ _Date;
        bool   __VARIABLE__ _Local;
    }CDateTime;

    typedef struct dty_native_c_timespan
    {
        uint64 __VARIABLE__ _Span;
    }CTimeSpan;

    CDateTime __VARIABLE__ dty_datetime_now();
    CDateTime __VARIABLE__ dty_datetime_nowUTC();

    CDateTime __VARIABLE__ dty_datetime_parseSpan(CTimeSpan __VARIABLE__ span);
    CDateTime __VARIABLE__ dty_datetime_parseDate(int32 __VARIABLE__ year, int32 __VARIABLE__ month, int32 __VARIABLE__ day);
    CDateTime __VARIABLE__ dty_datetime_parseDateTime
    (
        int32 __VARIABLE__ year,
        int32 __VARIABLE__ month,
        int32 __VARIABLE__ day,
        int32 __VARIABLE__ hour,
        int32 __VARIABLE__ minute,
        int32 __VARIABLE__ second
    );
    CDateTime __VARIABLE__ dty_datetime_parse
    (
        int32 __VARIABLE__ year,
        int32 __VARIABLE__ month,
        int32 __VARIABLE__ day,
        int32 __VARIABLE__ hour,
        int32 __VARIABLE__ minute,
        int32 __VARIABLE__ second,
        int32 __VARIABLE__ millisecond
    );
    CDateTime __VARIABLE__ dty_datetime_parseString(const string __VARIABLE__ str);

    uint64    __VARIABLE__ dty_datetime_getTotalTicks(CDateTime __VARIABLE__ dateTime);
    CTimeSpan __VARIABLE__ dty_datetime_getSpan(CDateTime __VARIABLE__ dateTime);

    int32 __VARIABLE__ dty_datetime_getYear(CDateTime __VARIABLE__ dateTime);
    int32 __VARIABLE__ dty_datetime_getMonth(CDateTime __VARIABLE__ dateTime);
    int32 __VARIABLE__ dty_datetime_getDay(CDateTime __VARIABLE__ dateTime);
    int32 __VARIABLE__ dty_datetime_getHour(CDateTime __VARIABLE__ dateTime);
    int32 __VARIABLE__ dty_datetime_getMinute(CDateTime __VARIABLE__ dateTime);
    int32 __VARIABLE__ dty_datetime_getSecond(CDateTime __VARIABLE__ dateTime);
    int32 __VARIABLE__ dty_datetime_getMillisecond(CDateTime __VARIABLE__ dateTime);
    CDateTime __VARIABLE__ dty_datetime_getDate(CDateTime __VARIABLE__ dateTime);
    CDateTime __VARIABLE__ dty_datetime_getTime(CDateTime __VARIABLE__ dateTime);

    int32 __VARIABLE__ dty_datetime_getYearUTC(CDateTime __VARIABLE__ dateTime);
    int32 __VARIABLE__ dty_datetime_getMonthUTC(CDateTime __VARIABLE__ dateTime);
    int32 __VARIABLE__ dty_datetime_getDayUTC(CDateTime __VARIABLE__ dateTime);
    int32 __VARIABLE__ dty_datetime_getHourUTC(CDateTime __VARIABLE__ dateTime);
    int32 __VARIABLE__ dty_datetime_getMinuteUTC(CDateTime __VARIABLE__ dateTime);
    int32 __VARIABLE__ dty_datetime_getSecondUTC(CDateTime __VARIABLE__ dateTime);
    int32 __VARIABLE__ dty_datetime_getMillisecondUTC(CDateTime __VARIABLE__ dateTime);
    CDateTime __VARIABLE__ dty_datetime_getDateUTC(CDateTime __VARIABLE__ dateTime);
    CDateTime __VARIABLE__ dty_datetime_getTimeUTC(CDateTime __VARIABLE__ dateTime);

    CDateTime __VARIABLE__ dty_datetime_addTicks(CDateTime __VARIABLE__ dateTime, uint64 __VARIABLE__ ticks);
    CDateTime __VARIABLE__ dty_datetime_addSpan(CDateTime __VARIABLE__ dateTime, CTimeSpan __VARIABLE__ span);
    CDateTime __VARIABLE__ dty_datetime_addYear(CDateTime __VARIABLE__ dateTime, int32 __VARIABLE__ addYear);
    CDateTime __VARIABLE__ dty_datetime_addMonth(CDateTime __VARIABLE__ dateTime, int32 __VARIABLE__ addMonth);
    CDateTime __VARIABLE__ dty_datetime_addDay(CDateTime __VARIABLE__ dateTime, int32 __VARIABLE__ addDay);
    CDateTime __VARIABLE__ dty_datetime_addHour(CDateTime __VARIABLE__ dateTime, int32 __VARIABLE__ addHour);
    CDateTime __VARIABLE__ dty_datetime_addMinute(CDateTime __VARIABLE__ dateTime, int32 __VARIABLE__ addMinute);
    CDateTime __VARIABLE__ dty_datetime_addSecond(CDateTime __VARIABLE__ dateTime, int32 __VARIABLE__ addSecond);
    CDateTime __VARIABLE__ dty_datetime_addMillisecond(CDateTime __VARIABLE__ dateTime, int32 __VARIABLE__ addMillisecond);

    CTimeSpan __VARIABLE__ dty_datetime_operator_sub(CDateTime __VARIABLE__ date1, CDateTime __VARIABLE__ date2);
    CTimeSpan __VARIABLE__ dty_datetime_operator_subSpan(CDateTime __VARIABLE__ date, CTimeSpan __VARIABLE__ span);

    CTimeSpan __VARIABLE__ dty_timespan_prase(uint64 __VARIABLE__ ticks);
    CTimeSpan __VARIABLE__ dty_timespan_praseDate(CDateTime __VARIABLE__ date);
    CDateTime __VARIABLE__ dty_timespan_getDate(CTimeSpan __VARIABLE__ span);

    CTimeSpan __VARIABLE__ dty_timespan_operator_addTicks(CTimeSpan __VARIABLE__ span, uint64 __VARIABLE__ ticks);
    CTimeSpan __VARIABLE__ dty_timespan_operator_addSpan(CTimeSpan __VARIABLE__ span1, CTimeSpan __VARIABLE__ span2);
    CTimeSpan __VARIABLE__ dty_timespan_operator_subTicks(CTimeSpan __VARIABLE__ span, uint64 __VARIABLE__ ticks);
    CTimeSpan __VARIABLE__ dty_timespan_operator_subSpan(CTimeSpan __VARIABLE__ span1, CTimeSpan __VARIABLE__ span2);

    const string __VARIABLE__ dty_datetime_toString(CDateTime __VARIABLE__ date);
    const string __VARIABLE__ dty_datetime_toFormatString(CDateTime __VARIABLE__ date, const string __VARIABLE__ formatStr);
    const string __VARIABLE__ dty_timespan_toString(CTimeSpan __VARIABLE__ span);
    const string __VARIABLE__ dty_timespan_toFormatString(CTimeSpan __VARIABLE__ span, const string __VARIABLE__ formatStr);

#ifdef __cplusplus
}
#endif // !__cplusplus

#ifdef __cplusplus

#include "../utilize.hh"
#include "./string.hpp"
#include "iostream"

namespace dty
{
    enum class WeekType : int32
    {
        Monday = 0,
        Tuesday = 1,
        Wednesday = 2,
        Thursday = 3,
        Firday = 4,
        Saturday = 5,
        Sunday = 6
    };
    enum class MonthType : int32
    {
        January = 0,
        February = 1,
        March = 2,
        April = 3,
        May = 4,
        June = 5,
        July = 6,
        August = 7,
        September = 8,
        October = 9,
        November = 10,
        December = 11
    };
    enum class TimeLocal : int32
    {
        UTC,
        Local
    };
    class TimeSpan final : dty::collection::IEquatable<TimeSpan>,
        dty::collection::ICompareable<TimeSpan>
    {
        __PUB__ TimeSpan();
        __PUB__ TimeSpan(uint64 __VARIABLE__ ticks);
        __PUB__ TimeSpan(const TimeSpan __REFERENCE__ span);
        __PUB__ TimeSpan(int32 __VARIABLE__ hours, int32 __VARIABLE__ minutes, int32 __VARIABLE__ seconds);
        __PUB__ TimeSpan(int32 __VARIABLE__ hours, int32 __VARIABLE__ minutes, int32 __VARIABLE__ seconds, int32 __VARIABLE__ milliseconds);
        __PUB__ TimeSpan(int32 __VARIABLE__ days, int32 __VARIABLE__ hours, int32 __VARIABLE__ minutes, int32 __VARIABLE__ seconds, int32 __VARIABLE__ milliseconds);

        __PUB__ virtual ~TimeSpan() override;

        __PUB__ uint64 __VARIABLE__ TotalTicks();

        __PUB__ int32 __VARIABLE__ GetTotalDays();
        __PUB__ int32 __VARIABLE__ GetTotalHours();
        __PUB__ int32 __VARIABLE__ GetTotalMinutes();
        __PUB__ int32 __VARIABLE__ GetTotalSeconds();
        __PUB__ int32 __VARIABLE__ GetTotalMilliseconds();

        __PUB__ int32 __VARIABLE__ Days();
        __PUB__ int32 __VARIABLE__ Hours();
        __PUB__ int32 __VARIABLE__ Minutes();
        __PUB__ int32 __VARIABLE__ Seconds();
        __PUB__ int32 __VARIABLE__ Milliseconds();

        __PUB__ TimeSpan __REFERENCE__ AddTicks(uint64 __VARIABLE__ ticks);
        __PUB__ TimeSpan __REFERENCE__ AddDays(int32 __VARIABLE__ ticks);
        __PUB__ TimeSpan __REFERENCE__ AddHours(int32 __VARIABLE__ ticks);
        __PUB__ TimeSpan __REFERENCE__ AddMinutes(int32 __VARIABLE__ ticks);
        __PUB__ TimeSpan __REFERENCE__ AddSeconds(int32 __VARIABLE__ ticks);
        __PUB__ TimeSpan __REFERENCE__ AddMilliseconds(int32 __VARIABLE__ ticks);
        __PUB__ TimeSpan __REFERENCE__ AddSpan(TimeSpan __REFERENCE__ span);

        __PUB__ TimeSpan __REFERENCE__ operator+(TimeSpan __REFERENCE__ span);
        __PUB__ TimeSpan __REFERENCE__ operator+(uint64 __VARIABLE__ ticks);
        __PUB__ TimeSpan __REFERENCE__ operator-(TimeSpan __REFERENCE__ span);
        __PUB__ TimeSpan __REFERENCE__ operator-(uint64 __VARIABLE__ ticks);

        __PUB__ String __VARIABLE__ ToString() const;
        __PUB__ String __VARIABLE__ ToString(const string __VARIABLE__ formatter) const;
        __PUB__ String __VARIABLE__ ToString(String __VARIABLE__ formatter) const;

        __PUB__ CTimeSpan __VARIABLE__ ToCTimeSpan();

        __PUB__ static TimeSpan __VARIABLE__ Parse(String __VARIABLE__ source);
        __PUB__ static TimeSpan __VARIABLE__ Parse(const string __VARIABLE__ source);

        __PUB__ static bool __VARIABLE__ TryParse(String __VARIABLE__ source, TimeSpan __REFERENCE__ outSpan);
        __PUB__ static bool __VARIABLE__ TryParse(const string __VARIABLE__ source, TimeSpan __REFERENCE__ outSpan);

        __PUB__ static CTimeSpan __VARIABLE__ ToCTimeSpan(TimeSpan __REFERENCE__ span);

#pragma region collection::ICompareable & collection::IEquatable interfaces
        __PUB__ virtual bool __VARIABLE__ Equals(TimeSpan __REFERENCE__ other) override;
        __PUB__ virtual bool __VARIABLE__ operator ==(TimeSpan __REFERENCE__ other) override;
        __PUB__ virtual bool __VARIABLE__ operator !=(TimeSpan __REFERENCE__ other) override;
        __PUB__ virtual bool __VARIABLE__ operator <(TimeSpan __REFERENCE__ other) override;
        __PUB__ virtual bool __VARIABLE__ operator >(TimeSpan __REFERENCE__ other) override;
        __PUB__ virtual bool __VARIABLE__ operator <=(TimeSpan __REFERENCE__ other) override;
        __PUB__ virtual bool __VARIABLE__ operator >=(TimeSpan __REFERENCE__ other) override;

        __PUB__ virtual collection::CompareResult __VARIABLE__ CompareTo(TimeSpan __REFERENCE__ other) override;
#pragma endregion

        friend std::ostream __REFERENCE__ operator<<(std::ostream __REFERENCE__ os, TimeSpan __REFERENCE__ span);
    };
    class DateTime final : dty::collection::IEquatable<DateTime>,
        dty::collection::ICompareable<DateTime>
    {
        __PUB__ DateTime();
        __PUB__ virtual ~DateTime() override;

#pragma region collection::ICompareable & collection::IEquatable interfaces
        __PUB__ virtual bool __VARIABLE__ Equals(DateTime __REFERENCE__ other) override;
        __PUB__ virtual bool __VARIABLE__ operator ==(DateTime __REFERENCE__ other) override;
        __PUB__ virtual bool __VARIABLE__ operator !=(DateTime __REFERENCE__ other) override;
        __PUB__ virtual bool __VARIABLE__ operator <(DateTime __REFERENCE__ other) override;
        __PUB__ virtual bool __VARIABLE__ operator >(DateTime __REFERENCE__ other) override;
        __PUB__ virtual bool __VARIABLE__ operator <=(DateTime __REFERENCE__ other) override;
        __PUB__ virtual bool __VARIABLE__ operator >=(DateTime __REFERENCE__ other) override;

        __PUB__ virtual collection::CompareResult __VARIABLE__ CompareTo(DateTime __REFERENCE__ other) override;
#pragma endregion

        friend std::ostream __REFERENCE__ operator<<(std::ostream __REFERENCE__ os, DateTime __REFERENCE__ date);
    };

    std::ostream __REFERENCE__ operator<<(std::ostream __REFERENCE__ os, TimeSpan __REFERENCE__ span);
    std::ostream __REFERENCE__ operator<<(std::ostream __REFERENCE__ os, DateTime __REFERENCE__ date);
}

#endif // !__cplusplus

#endif // !__DTY_NATIVE_UTILS_DATETIME_H_PLUS_PLUS__