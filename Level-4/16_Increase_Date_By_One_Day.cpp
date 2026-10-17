#include <iostream>
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

bool IsDayLastDayInMonth(stDate Date)
{
    return (Date.Day == NumberOfDaysInAMonth(Date.Year, Date.Month));
}

bool IsMonthLastMonthInYear(short Month)
{
    return (Month == 12);
}

stDate IncreaseDateByOneDay(stDate Date) // 31/12/2020  1/1/2021  |  31/8/2022    1/9/2022  |  30/12/2024  31/12/2024  |  31/5/2020
{

    if (IsDayLastDayInMonth(Date))
    {
        if (IsMonthLastMonthInYear(Date.Month))
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

    /*
    if (IsDayLastDayInMonth(Date))
    {
        if (IsMonthLastMonthInYear(Date.Month))
        {
            Date.Day = 1;
            Date.Month = 1;
            Date.Year++;

            return Date;
        }

        Date.Day = 1;
        Date.Month++;

        return Date;
    }

    else
    {
        Date.Day++;
        return Date;
    }
    */
}

int main()
{
    stDate Date = ReadFullDate();
    Date = IncreaseDateByOneDay(Date);

    cout << "\n\nDate after adding one day is : ";
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year;
}