#include <iostream>
using namespace std;

struct stDate
{
    short Day = 0;
    short Month = 0;
    short Year = 0;
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

stDate IncreaseDateByXDays(stDate Date, short X) // 1/1/2023  10
{
    for (short i = 1; i <= X; i++)
    {
        Date = IncreaseDateByOneDay(Date);
    }

    return Date;
}

stDate IncreaseDateByOneWeek(stDate Date) // 11/1/2023 -> 18/1/2023
{
    for (short i = 1; i <= 7; i++)
    {
        Date = IncreaseDateByOneDay(Date);
    }

    return Date;

    // return IncreaseDateByXDays(Date, 7);
}

stDate IncreaseDateByXWeeks(stDate Date, short Weeks) // 18/1/2023 -> 29/3/2023
{
    for (short i = 1; i <= Weeks; i++)
    {
        Date = IncreaseDateByOneWeek(Date);
    }

    return Date;
}

stDate IncreaseDateByOneMonth(stDate Date)
{
    if (Date.Month == 12)
    {
        Date.Month = 1;
        Date.Year++;
    }

    else
    {
        Date.Month++;
    } // 31/4/2022

    short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date.Year, Date.Month); // 30

    if (Date.Day > NumberOfDaysInCurrentMonth) // 31>30
    {
        Date.Day = NumberOfDaysInCurrentMonth;
    }

    return Date;
}

stDate IncreaseDateByXMonths(stDate Date, short Months) // 29/4/2023 -> 29/9/2023
{
    for (short i = 1; i <= Months; i++)
    {
        Date = IncreaseDateByOneMonth(Date);
    }

    return Date;
}

stDate IncreaseDateByOneYear(stDate Date) // 29/9/2023 -> 29/9/2024
{
    Date.Year++;

    return Date;

    // return IncreaseDateByXMonths(Date, 12);
}

stDate IncreaseDateByXYears(stDate Date, short Years) // 29/9/2024 -> 29/9/2034
{
    for (short i = 1; i <= Years; i++)
    {
        Date = IncreaseDateByOneYear(Date);
    }

    return Date;
}

stDate IncreaseDateByXYearsFaster(stDate Date, short Years) // 29/9/2024 -> 29/9/2034
{
    Date.Year = Date.Year + Years;

    return Date;
}

stDate IncreaseDateByOneDecade(stDate Date) // 29/9/2044 -> 29/9/2054
{
    // return IncreaseDateByXYears(Date, 10);
    // return IncreaseDateByXYearsFaster(Date, 10);
    Date.Year = Date.Year + 10;
    return Date;
}

stDate IncreaseDateByXDecade(stDate Date, short Decades) // 29/9/2054 -> 29/9/2154
{
    for (short i = 1; i <= Decades; i++)
    {
        Date = IncreaseDateByOneDecade(Date);
    }

    return Date;
}

stDate IncreaseDateByXDecadeFaster(stDate Date, short Decade)
{
    Date.Year = Date.Year + (Decade * 10);

    return Date;
}

stDate IncreaseDateByOneCentury(stDate Date)
{
    Date.Year = Date.Year + 100;
    return Date;

    // return IncreaseDateByXDecadeFaster(Date,10);
    // return IncreaseDateByXDecade(Date,10);

}

stDate IncreaseDateByOneMillennium(stDate Date)
{
    Date.Year = Date.Year + 1000;
    return Date;

    // return IncreaseDateByXDecadeFaster(Date,100);
    // return IncreaseDateByXDecadeFaster(Date,100);
}

int main()
{
    stDate Date = ReadFullDate(); // 31/12/2022
    Date = IncreaseDateByOneDay(Date);

    cout << "\n\nDate After:\n\n";

    cout << "01-Adding One Day is : " << Date.Day << "/" << Date.Month << "/" << Date.Year;

    Date = IncreaseDateByXDays(Date, 10);
    cout << "\n02-Adding 10 Days is : " << Date.Day << "/" << Date.Month << "/" << Date.Year;

    Date = IncreaseDateByOneWeek(Date);
    cout << "\n03-Adding One Week is : " << Date.Day << "/" << Date.Month << "/" << Date.Year;

    Date = IncreaseDateByXWeeks(Date, 10);
    cout << "\n04-Adding 10 Weeks is : " << Date.Day << "/" << Date.Month << "/" << Date.Year;

    Date = IncreaseDateByOneMonth(Date);
    cout << "\n05-Adding One Month is : " << Date.Day << "/" << Date.Month << "/" << Date.Year;

    Date = IncreaseDateByXMonths(Date, 5);
    cout << "\n06-Adding 5 Months is : " << Date.Day << "/" << Date.Month << "/" << Date.Year;

    Date = IncreaseDateByOneYear(Date);
    cout << "\n07-Adding One Year is : " << Date.Day << "/" << Date.Month << "/" << Date.Year;

    Date = IncreaseDateByXYears(Date, 10);
    cout << "\n08-Adding 10 Years is : " << Date.Day << "/" << Date.Month << "/" << Date.Year;

    Date = IncreaseDateByXYearsFaster(Date, 10);
    cout << "\n09-Adding 10 Years (faster) is : " << Date.Day << "/" << Date.Month << "/" << Date.Year;

    Date = IncreaseDateByOneDecade(Date);
    cout << "\n10-Adding One Decade is : " << Date.Day << "/" << Date.Month << "/" << Date.Year;

    Date = IncreaseDateByXDecade(Date, 10);
    cout << "\n11-Adding 10 Decades is : " << Date.Day << "/" << Date.Month << "/" << Date.Year;

    Date = IncreaseDateByXDecadeFaster(Date, 10);
    cout << "\n12-Adding 10 Decades (Faster) is : " << Date.Day << "/" << Date.Month << "/" << Date.Year;

    Date = IncreaseDateByOneCentury(Date);
    cout << "\n13-Adding One Century is : " << Date.Day << "/" << Date.Month << "/" << Date.Year;

    Date = IncreaseDateByOneMillennium(Date);
    cout << "\n14-Adding One Millennium is : " << Date.Day << "/" << Date.Month << "/" << Date.Year;
}