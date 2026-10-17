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

bool IsWeekEnd(stDate Date)
{
    return DayOfWeekOrder(Date) == 5 || DayOfWeekOrder(Date) == 6;
}

bool IsBusinessDay(stDate Date)
{
    return !IsWeekEnd(Date);
    //return DayOfWeekOrder(Date) != 5 && DayOfWeekOrder(Date) != 6;
}

short CalculateActualVacationDays(stDate Date1, stDate Date2)
{
    short BusinessDaysCounter = 0;
    while (IsDate1BeforeDate2(Date1, Date2))
    {
        if (IsBusinessDay(Date1))
        {
            BusinessDaysCounter++; // 1 2
        }

        Date1 = IncreaseDateByOneDay(Date1);
    }

    return BusinessDaysCounter;
}

int main()
{
    cout << "\nVacation Starts :\n";
    stDate Date1 = ReadFullDate();

    cout << "\n\nVacation Ends :\n";
    stDate Date2 = ReadFullDate();

    short DayOrderOfDate1 = DayOfWeekOrder(Date1);
    short DayOrderOfDate2 = DayOfWeekOrder(Date2);

    cout << "\nVacation From : " << DayShortName(DayOrderOfDate1) << " , " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;
    cout << "\nVacation To : " << DayShortName(DayOrderOfDate2) << " , " << Date2.Day << "/" << Date2.Month << "/" << Date2.Year;

    cout << "\n\nActual Vacation is : " << CalculateActualVacationDays(Date1, Date2) << " Day(s).";
}