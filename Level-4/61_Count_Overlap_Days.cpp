#include <iostream>
using namespace std;

struct stDate
{
    short Day = 0;
    short Month = 0;
    short Year = 0;
};

struct stPeriod
{
    stDate StartDate;
    stDate EndDate;
};

short ReadDay()
{
    short Day = 0;

    cout << "Enter a Day : ";
    cin >> Day;

    return Day;
}

short ReadMonth()
{
    short Month = 0;

    cout << "Enter a Month : ";
    cin >> Month;

    return Month;
}

short ReadYear()
{
    short Year = 0;

    cout << "Enter a Year : ";
    cin >> Year;

    return Year;
}

stDate ReadFullDate()
{
    stDate Date;

    Date.Day = ReadDay();
    Date.Month = ReadMonth();
    Date.Year = ReadYear();

    return Date;
}

stPeriod ReadPeriod()
{
    stPeriod Period;

    cout << "Enter Start Date :\n\n";
    Period.StartDate = ReadFullDate();

    cout << "\n\nEnter End Date :\n\n";
    Period.EndDate = ReadFullDate();

    return Period;
}

bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{
    return (Date1.Year < Date2.Year) ? true : (Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month) ? true : (Date1.Month == Date2.Month) ? (Date1.Day < Date2.Day)
                                                                                                                                             : false
                                                                         : false;
}

bool IsDate1EqualDate2(stDate Date1, stDate Date2)
{
    return (Date1.Year == Date2.Year) ? (Date1.Month == Date2.Month) ? (Date1.Day == Date2.Day) : false : false;
}

bool IsDate1AfterDate2(stDate Date1, stDate Date2)
{
    return !IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2);
}

enum enCompareDates
{
    Before = -1,
    Equal = 0,
    After = 1
};

enCompareDates CompareDates(stDate Date1, stDate Date2)
{
    if (IsDate1BeforeDate2(Date1, Date2))
    {
        return enCompareDates::Before;
    }

    else if (IsDate1EqualDate2(Date1, Date2))
    {
        return enCompareDates::Equal;
    }

    else
        return enCompareDates::After;
}

bool IsOverlapPeriods(stPeriod Period1, stPeriod Period2)
{
    if (CompareDates(Period1.EndDate, Period2.StartDate) == enCompareDates::After || CompareDates(Period1.StartDate, Period2.EndDate) == enCompareDates::Before)
    {
        return false;
    }
    else
        return true;
}

bool IsLeapYear(short Year)
{
    return ((Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0));
}

short NumberOfDaysInAMonth(short Year, short Month)
{
    if (Month < 1 || Month > 12)
    {
        return 0;
    }

    short arrMonthsDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    return (Month == 2) ? IsLeapYear(Year) ? 29 : 28 : arrMonthsDays[Month - 1];
}

bool IsLastDayInMonth(stDate Date)
{
    return (Date.Day == NumberOfDaysInAMonth(Date.Year, Date.Month));
}

bool IsLastMonthInYear(short Month)
{
    return Month == 12;
}

stDate IncreaseDateByOneDay(stDate Date)
{
    if (IsLastDayInMonth(Date))
    {
        if (IsLastMonthInYear(Date.Month))
        {
            Date.Day = 1;
            Date.Month = 1;
            Date.Year++;
        }
        else
        {
            Date.Day = 1;
            Date.Month++;
        }
    }
    else
    {
        Date.Day++;
    }

    return Date;
}

int GetDifferenceBetweenTwoDates(stDate Date1, stDate Date2, bool IncludeEndDate = false)
{
    int Days = 0;
    while (IsDate1BeforeDate2(Date1, Date2))
    {
        Days++;
        IncreaseDateByOneDay(Date1);
    }

    return IncludeEndDate ? ++Days : Days;
}

int PeriodLength(stPeriod Period, bool IncludeEndDate)
{
    return GetDifferenceBetweenTwoDates(Period.StartDate, Period.EndDate, IncludeEndDate);
}

bool IsDateInPeriod(stDate Date, stPeriod Period)
{
    // while (IsDate1BeforeDate2(Period.StartDate,Period.EndDate))
    // {
    //     if (IsDate1EqualDate2(Period.StartDate,Date))
    //     {
    //         return true;
    //     }

    //     Period.StartDate=IncreaseDateByOneDay(Period.StartDate);
    // }
    // return false;

    return !(CompareDates(Date, Period.StartDate) == enCompareDates::Before || CompareDates(Date, Period.EndDate) == enCompareDates::After);
}

int CountOverlapDatesBetweenTwoPeriods(stPeriod Period1, stPeriod Period2)
{
    int Period1Length = PeriodLength(Period1, true);
    int Period2Length = PeriodLength(Period2, true);
    int OverlapCount = 0;

    if (!IsOverlapPeriods(Period1, Period2))
    {
        return 0;
    }

    if (Period1Length < Period2Length)
    {
        while (IsDate1BeforeDate2(Period1.StartDate, Period1.EndDate))
        {
            if (IsDateInPeriod(Period1.StartDate, Period2))
            {
                OverlapCount++;
            }

            Period1.StartDate = IncreaseDateByOneDay(Period1.StartDate);
        }
    }
    else
    {
        while (IsDate1BeforeDate2(Period2.StartDate, Period2.EndDate))
        {
            if (IsDateInPeriod(Period2.StartDate, Period1))
            {
                OverlapCount++;
            }

            Period2.StartDate = IncreaseDateByOneDay(Period2.StartDate);
        }
    }

    return OverlapCount;
}

int main()
{
    stPeriod Period1, Period2;

    cout << "Enter Period 1 :\n";
    Period1 = ReadPeriod();

    cout << "Enter Period 2 :\n";
    Period2 = ReadPeriod();

    cout << "\n\nOverlap Days Count is : " << CountOverlapDatesBetweenTwoPeriods(Period1, Period2);
}