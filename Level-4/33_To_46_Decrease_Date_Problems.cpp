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

bool IsFirstDayInMonth(stDate Date)
{
    return Date.Day == 1;
}

bool IsFirstMonthInYear(short Month)
{
    return Month == 1;
}

stDate DecreaseDateByOneDay(stDate Date)
{
    // short MonthDays=NumberOfDaysInAMonth(Date.Year,Date.Month);

    if (IsFirstDayInMonth(Date))
    {
        if (IsFirstMonthInYear(Date.Month))
        {
            Date.Day = 31;
            Date.Month = 12;
            Date.Year--;
        }
        else
        {
            // Date.Month--;
            // Date.Day=NumberOfDaysInAMonth(Date.Year,Date.Month);
            Date.Day = NumberOfDaysInAMonth(Date.Year, Date.Month - 1);
            Date.Month--;
        }
    }
    else
    {
        Date.Day--;
    }

    return Date;
}

stDate DecreaseDateByXDays(stDate Date, short Days) // 1/1/2023  10
{
    for (short i = 1; i <= Days; i++)
    {
        Date = DecreaseDateByOneDay(Date);
    }

    return Date;
}

stDate DecreaseDateByOneWeek(stDate Date) // 11/1/2023 -> 18/1/2023
{
    /*for (short i = 1; i <= 7; i++)
    {
        Date = DecreaseDateByOneDay(Date);
    }

    return Date;*/

    return DecreaseDateByXDays(Date, 7);
}

stDate DecreaseDateByXWeeks(stDate Date, short Weeks) // 18/1/2023 -> 29/3/2023
{
    for (short i = 1; i <= Weeks; i++)
    {
        Date = DecreaseDateByOneWeek(Date);
    }

    return Date;
}

stDate DecreaseDateByOneMonth(stDate Date)
{
    if (Date.Month == 1) // اذا انا بالشهر الاول وبدي انقص شهر فبرجع للشهر 12 من السنة اللي قبلها 
    {
        Date.Month = 12;
        Date.Year--;
    }

    else
    {
        Date.Month--;
    } // 31/4/2022

    short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date.Year, Date.Month); // 30

    if (Date.Day > NumberOfDaysInCurrentMonth) // 31>30
    {
        Date.Day = NumberOfDaysInCurrentMonth;
    }

    return Date;
}

stDate DecreaseDateByXMonths(stDate Date, short Months) // 29/4/2023 -> 29/9/2023
{
    for (short i = 1; i <= Months; i++)
    {
        Date = DecreaseDateByOneMonth(Date);
    }

    return Date;
}

stDate DecreaseDateByOneYear(stDate Date) // 29/9/2023 -> 29/9/2024
{
    Date.Year--;

    return Date;

    // return IncreaseDateByXMonths(Date, 12);
}

stDate DecreaseDateByXYears(stDate Date, short Years) // 29/9/2024 -> 29/9/2034
{
    for (short i = 1; i <= Years; i++)
    {
        Date = DecreaseDateByOneYear(Date);
    }

    return Date;
}

stDate DecreaseDateByXYearsFaster(stDate Date, short Years) // 29/9/2024 -> 29/9/2034
{
    Date.Year -= Years;

    return Date;
}

stDate DecreaseDateByOneDecade(stDate Date) // 29/9/2044 -> 29/9/2054
{
    // return DecreaseDateByXYears(Date, 10);
    // return DecreaseDateByXYearsFaster(Date, 10);
    Date.Year = Date.Year - 10;
    return Date;
}

stDate DecreaseDateByXDecade(stDate Date, short Decades) // 29/9/2054 -> 29/9/2154
{
    for (short i = 1; i <= Decades; i++)
    {
        Date = DecreaseDateByOneDecade(Date);
    }

    /*
    for (short i = 1; i <= Decades*10; i++)
    {
        Date=DecreaseDateByOneYear(Date);
    }*/
    
    return Date;
}

stDate DecreaseDateByXDecadeFaster(stDate Date, short Decade)
{
    Date.Year = Date.Year - (Decade * 10);

    return Date;
}

stDate DecreaseDateByOneCentury(stDate Date)
{
    Date.Year = Date.Year - 100;
    return Date;

    // return IncreaseDateByXDecadeFaster(Date,10);
    // return IncreaseDateByXDecade(Date,10);
}

stDate DecreaseDateByOneMillennium(stDate Date)
{
    Date.Year = Date.Year - 1000;
    return Date;

    // return DecreaseDateByXDecade(Date,100);
    // return DecreaseDateByXDecadeFaster(Date,100);
}

int main()
{
    stDate Date = ReadFullDate(); // 31/12/2022
    Date = DecreaseDateByOneDay(Date);

    cout << "\n\nDate After:\n\n";

    cout << "01-Substracting One Day is : " << Date.Day << "/" << Date.Month << "/" << Date.Year;

    Date = DecreaseDateByXDays(Date, 10);
    cout << "\n02-Substracting 10 Days is : " << Date.Day << "/" << Date.Month << "/" << Date.Year;

    Date = DecreaseDateByOneWeek(Date);
    cout << "\n03-Substracting One Week is : " << Date.Day << "/" << Date.Month << "/" << Date.Year;

    Date = DecreaseDateByXWeeks(Date, 10);
    cout << "\n04-Substracting 10 Weeks is : " << Date.Day << "/" << Date.Month << "/" << Date.Year;

    Date = DecreaseDateByOneMonth(Date);
    cout << "\n05-Substracting One Month is : " << Date.Day << "/" << Date.Month << "/" << Date.Year;

    Date = DecreaseDateByXMonths(Date, 5);
    cout << "\n06-Substracting 5 Months is : " << Date.Day << "/" << Date.Month << "/" << Date.Year;

    Date = DecreaseDateByOneYear(Date);
    cout << "\n07-Substracting One Year is : " << Date.Day << "/" << Date.Month << "/" << Date.Year;

    Date = DecreaseDateByXYears(Date, 10);
    cout << "\n08-Substracting 10 Years is : " << Date.Day << "/" << Date.Month << "/" << Date.Year;

    Date = DecreaseDateByXYearsFaster(Date, 10);
    cout << "\n09-Substracting 10 Years (faster) is : " << Date.Day << "/" << Date.Month << "/" << Date.Year;

    Date = DecreaseDateByOneDecade(Date);
    cout << "\n10-Substracting One Decade is : " << Date.Day << "/" << Date.Month << "/" << Date.Year;

    Date = DecreaseDateByXDecade(Date, 10);
    cout << "\n11-Substracting 10 Decades is : " << Date.Day << "/" << Date.Month << "/" << Date.Year;

    Date = DecreaseDateByXDecadeFaster(Date, 10);
    cout << "\n12-Substracting 10 Decades (Faster) is : " << Date.Day << "/" << Date.Month << "/" << Date.Year;

    Date = DecreaseDateByOneCentury(Date);
    cout << "\n13-Substracting One Century is : " << Date.Day << "/" << Date.Month << "/" << Date.Year;

    Date = DecreaseDateByOneMillennium(Date);
    cout << "\n14-Substracting One Millennium is : " << Date.Day << "/" << Date.Month << "/" << Date.Year;
}