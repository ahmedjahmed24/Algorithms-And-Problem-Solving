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

    cout << "Enter End Date :\n\n";
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

bool IsOverLapDates(stPeriod Period1, stPeriod Period2)
{
    if (CompareDates(Period2.EndDate,Period1.StartDate) == enCompareDates::Before || CompareDates(Period2.StartDate, Period1.EndDate) == enCompareDates::After)
    {
        return false;
    }
    else
        return true;
}

int main()
{
    stPeriod Period1;
    stPeriod Period2;

    cout << "Enter Period 1 :\n";
    Period1 = ReadPeriod();

    cout << "Enter Period 2 :\n";
    Period2 = ReadPeriod();

    if (IsOverLapDates(Period1, Period2))
    {
        cout << "Yes, Periods OverLap";
    }
    else
        cout << "No, Periods do not OverLap";
}