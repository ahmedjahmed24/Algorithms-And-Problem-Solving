#pragma warning(disable 4996)
#include <iostream>
#include <ctime>
using namespace std;

struct stDate
{
    short Year = 0;
    short Month = 0;
    short Day = 0;
};

short DayOfWeekOrdre(short Year, short Month, short Day)
{
    short a, y, m;
    a = (14 - Month) / 12;
    y = Year - a;
    m = Month + (12 * a) - 2;
    return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

short DayOfWeekOrder(stDate Date)
{
    return DayOfWeekOrdre(Date.Year, Date.Month, Date.Day);

    /*
    short a, y, m;
    a = (14 - Date.Month) / 12;
    y = Date.Year - a;
    m = Date.Month + (12 * a) - 2;
    return (Date.Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
    */
}

stDate GetSystemDate()
{
    stDate SystemDate;

    time_t t = time(0);
    tm *now = localtime(&t);

    SystemDate.Year = now->tm_year + 1900;
    SystemDate.Month = now->tm_mon + 1;
    SystemDate.Day = now->tm_mday;

    return SystemDate;
}

string DayShortName(short DayOfWeekOrder) // 0
{
    string arrWeekDays[7] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

    return arrWeekDays[DayOfWeekOrder]; // Sun
}

bool IsEndOfWeek(stDate Date)
{
    return DayOfWeekOrder(Date) == 6;
}

bool IsWeekEnd(stDate Date)
{
    return DayOfWeekOrder(Date) == 5 || DayOfWeekOrder(Date) == 6;
}

bool IsBusinessDay(stDate Date)
{
    return !IsWeekEnd(Date);

    // return DayOfWeekOrder(Date) != 5 && DayOfWeekOrder(Date) != 6;
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

short DaysUntilEndOfWeek(stDate Date)
{
    return 6 - DayOfWeekOrder(Date);
}

bool IsLastMonthInYear(short Month)
{
    return Month == 12;
}

bool IsLastDayInMonth(stDate Date)
{
    return (Date.Day == NumberOfDaysInAMonth(Date.Year, Date.Month));
}

bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{
    return (Date1.Year < Date2.Year) ? true : (Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month) ? true : (Date1.Month == Date2.Month) ? (Date1.Day < Date2.Day)
                                                                                                                                             : false
                                                                         : false;
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

short GetDifferenceBetweenTwoDates(stDate Date1, stDate Date2, bool IncludeEndDay = false)
{
    int Days = 0;

    while (IsDate1BeforeDate2(Date1, Date2))
    {
        Days++;
        Date1 = IncreaseDateByOneDay(Date1);
    }

    return IncludeEndDay ? ++Days : Days;
}

short DaysUntilEndOfMonth(stDate Date)
{
    stDate EndOfMonthDate;

    EndOfMonthDate.Day = NumberOfDaysInAMonth(Date.Year, Date.Month);
    EndOfMonthDate.Month = Date.Month;
    EndOfMonthDate.Year = Date.Year;

    return GetDifferenceBetweenTwoDates(Date, EndOfMonthDate);

    // short MonthDays=NumberOfDaysInAMonth(Date.Year,Date.Month);

    // return MonthDays-Date.Day;
}

short NumberOfDaysFromTheBeginingOfTheYear(short Year, short Month, short Day)
{
    short TotalDays = 0;

    for (short i = 1; i <= Month - 1; i++)
    {
        TotalDays += NumberOfDaysInAMonth(Year, i);
    }

    TotalDays += Day;

    return TotalDays;
}

short DaysUntilEndOfYear(stDate Date)
{
    stDate EndOfYearDate;

    EndOfYearDate.Day = 31;
    EndOfYearDate.Month = 12;
    EndOfYearDate.Year = Date.Year;

    return GetDifferenceBetweenTwoDates(Date, EndOfYearDate);

    // short TotalDays = NumberOfDaysFromTheBeginingOfTheYear(Date.Year, Date.Month, Date.Day);
    // return IsLeapYear(Date.Year) ? 366 - TotalDays : 365 - TotalDays;
}

int main()
{
    stDate Date = GetSystemDate();

    cout << "\n\nToday is " << DayShortName(DayOfWeekOrder(Date)) << " , " << Date.Day << "/" << Date.Month << "/" << Date.Year;

    cout << "\n\nIs it end of week ?";
    if (IsEndOfWeek(Date))
    {
        cout << "\nYes, it is Satrday , It's end of week";
    }
    else
    {
        cout << "\nNo, It's NOT end of week";
    }

    cout << "\n\nIs it week end ?";
    if (IsWeekEnd(Date))
    {
        cout << "\nYes, it is a week end";
    }
    else
    {
        cout << "\nNo, It's " << DayShortName(DayOfWeekOrder(Date)) << " NOT a Week end";
    }

    cout << "\n\nIs it a Business Day ?";
    if (IsBusinessDay(Date))
    {
        cout << "\nYes, it is a Business Day";
    }
    else
    {
        cout << "\nNo, It's NOT a Business Day";
    }

    cout << "\n\nDays Until End Of Week : " << DaysUntilEndOfWeek(Date);
    cout << "\nDays Until End Of Month : " << DaysUntilEndOfMonth(Date);
    cout << "\nDays Until End Of Year : " << DaysUntilEndOfYear(Date);
}