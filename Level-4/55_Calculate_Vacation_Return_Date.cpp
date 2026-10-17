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

short ReadVacationDays()
{
    short VacationDays = 0;

    cout << "\nPlease Enter vacation days : ";
    cin >> VacationDays;

    return VacationDays;
}

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

string DayShortName(short DayOfWeekOrder)
{
    string arrWeekDays[7] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

    return arrWeekDays[DayOfWeekOrder];
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

bool IsLastDayInMonth(stDate Date)
{
    return Date.Day == NumberOfDaysInAMonth(Date.Year, Date.Month);
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

stDate ClculateEndVacationDate(stDate Date, short VacationDays)
{
    short BusinessDaysCounter = 0;

    while (BusinessDaysCounter < VacationDays)
    {
        if (IsBusinessDay(Date))
        {
            BusinessDaysCounter++;
        }
        Date = IncreaseDateByOneDay(Date);
    }

    return Date;
}

/*stDate ClculateEndVacationDate(stDate DateFrom, short VacationDays) // 1/1/2022
{
    short WeekEndCounter = 0;

    while (IsWeekEnd(DateFrom))
    {
        DateFrom = IncreaseDateByOneDay(DateFrom);
    }

    // ما بوصل لهون الا وانا واصل لاول بزنس داي
    for (short i = 1; i <= VacationDays + WeekEndCounter; i++)
    {
        if (IsWeekEnd(DateFrom))
        {
            WeekEndCounter++; // 1 2 3 4 5 6 7 8
        }

        DateFrom = IncreaseDateByOneDay(DateFrom);
    }

    while (IsWeekEnd(DateFrom))
    {
        DateFrom = IncreaseDateByOneDay(DateFrom);
    }

    return DateFrom;
}*/

int main()
{
    stDate Date;
    short VacationDays = 0;

    cout << "\nVacation Starts :\n";
    Date = ReadFullDate();
    VacationDays = ReadVacationDays();

    Date = ClculateEndVacationDate(Date, VacationDays);

    cout << "\n\nReturn date is : " << DayShortName(DayOfWeekOrder(Date)) << " , " << Date.Day << "/" << Date.Month << "/" << Date.Year;
}