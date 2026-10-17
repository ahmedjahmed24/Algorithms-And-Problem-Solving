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

short NumberOfDaysFromTheBeginingOfTheYear(short Year, short Month, short Day)
{
    short TotalDays = 0;

    for (short i = 1; i <= Month - 1; i++)
    {
        TotalDays = TotalDays + NumberOfDaysInAMonth(Year, i);
    }

    TotalDays = TotalDays + Day;

    return TotalDays;
}

stDate ConvertTotalDaysToDate(short NumberOfDays, short Year)
{
    stDate Date;

    Date.Year = Year;
    short MonthDays = 0;
    Date.Month = 1;

    while (true)
    {
        MonthDays = NumberOfDaysInAMonth(Year, Date.Month);

        if (NumberOfDays > MonthDays)
        {
            NumberOfDays = NumberOfDays - MonthDays;
            Date.Month++;
        }
        else
        {
            Date.Day = NumberOfDays;
            break;
        }
    }

    return Date;
}

int main()
{
    short Day = ReadDay();
    short Month = ReadMonth();
    short Year = ReadYear();
    short NumberOfDays = NumberOfDaysFromTheBeginingOfTheYear(Year, Month, Day);
    stDate Date = ConvertTotalDaysToDate(NumberOfDays, Year);

    cout << "\nNumber of days from the begining of the year is : " << NumberOfDays;
    cout << "\nDate for [" << NumberOfDays << "] is : ";
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year;
}