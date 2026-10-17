#include <iostream>
#include <ctime>
using namespace std;

struct stDate
{
    short Year = 0;
    short Month = 0;
    short Day = 0;
};

short ReadDay()
{
    short Day = 0;

    cout << "\nEnter a Day : ";
    cin >> Day;

    return Day;
}

short ReadMonth()
{
    short Month = 0;

    cout << "\nEnter a Month : ";
    cin >> Month;

    return Month;
}

short ReadYear()
{
    short Year = 0;

    cout << "\nEnter a Year : ";
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

bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{
    return (Date1.Year < Date2.Year) ? true : (Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month) ? true : (Date1.Month == Date2.Month) ? (Date1.Day < Date2.Day)
                                                                                                                                             : false
                                                                         : false;
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

bool IsLastMonthInYear(short Month)
{
    return Month == 12;
}

bool IsLastDayInMonth(stDate Date)
{
    return (Date.Day == NumberOfDaysInAMonth(Date.Year, Date.Month));
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

void SwapDates(stDate &Date1, stDate &Date2)
{
    stDate TempDate;

    TempDate.Day = Date1.Day;
    TempDate.Month = Date1.Month;
    TempDate.Year = Date1.Year;

    Date1.Day = Date2.Day;
    Date1.Month = Date2.Month;
    Date1.Year = Date2.Year;

    Date2.Day = TempDate.Day;
    Date2.Month = TempDate.Month;
    Date2.Year = TempDate.Year;

}

int GitDifferenceBetweenTwoDates(stDate Date1, stDate Date2, bool IncludeEndDay = false)
{
    int Days = 0;
    short SwapFlagValue = 1;

    if (!IsDate1BeforeDate2(Date1, Date2))
    {
        SwapDates(Date1, Date2);
        SwapFlagValue = -1;
    }

    while (IsDate1BeforeDate2(Date1, Date2))
    {
        Days++;
        Date1 = IncreaseDateByOneDay(Date1);
    }

    return IncludeEndDay ? SwapFlagValue * ++Days : Days * SwapFlagValue;
}

int main()
{
    stDate Date1 = ReadFullDate(); // 1/1/2000
    stDate Date2 = ReadFullDate(); // 1/1/2022

    cout << "\n\nDifference between two dates is : " << GitDifferenceBetweenTwoDates(Date1, Date2) << " Day(s).";
    cout << "\n\nDifference between two dates (Include End Day) is : " << GitDifferenceBetweenTwoDates(Date1, Date2, true) << " Day(s).";
}