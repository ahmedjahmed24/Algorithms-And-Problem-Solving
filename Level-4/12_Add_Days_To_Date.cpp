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

short ReadMoreDays()
{
    short MoreDays = 0;

    cout << "\nHow many days do you want to add ? ";
    cin >> MoreDays;

    return MoreDays;
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

stDate ReadFullDate()
{
    stDate Date;

    Date.Day = ReadDay();
    Date.Month = ReadMonth();
    Date.Year = ReadYear();

    return Date;
}

stDate NewDate(stDate Date, short MoreDays)
{
    // Date.Month = 1; ماااابصييييرررررررر لييييشششش
    short RemainingDays = MoreDays + NumberOfDaysFromTheBeginingOfTheYear(Date.Year, Date.Month, Date.Day);
    short MonthDays = 0;
    Date.Month = 1;

    while (true)
    {
        MonthDays = NumberOfDaysInAMonth(Date.Year, Date.Month);
        if (RemainingDays > MonthDays)
        {
            RemainingDays = RemainingDays - MonthDays;
            Date.Month++;

            if (Date.Month > 12)
            {
                Date.Year++;
                Date.Month = 1;
            }
        }
        else
        {
            Date.Day = RemainingDays;
            break;
        }
    }

    return Date;
}

int main()
{
    stDate Date = ReadFullDate();
    short MoreDays = ReadMoreDays();

    Date = NewDate(Date, MoreDays);

    cout << "\nNew date after adding [" << MoreDays << "] is : ";
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year;
}