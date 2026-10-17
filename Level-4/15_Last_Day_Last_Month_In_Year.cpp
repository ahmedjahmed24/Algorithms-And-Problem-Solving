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
    return ((Year % 400 == 0) || (Year % 100 != 0 && Year % 4 == 0));
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

bool IsLastDayInMonth(stDate Date) // 12/4/2023
{
    return (Date.Day==NumberOfDaysInAMonth(Date.Year,Date.Month));
}

bool IsLastMonthInYear(short Month)
{
    return (Month == 12);
}

int main()
{
    stDate Date = ReadFullDate();

    if (IsLastDayInMonth(Date))
    {
        cout << "\nYes, Day is last day in month";
    }
    else
    {
        cout << "\nNo, Day is NOT last day in month";
    }

    if (IsLastMonthInYear(Date.Month))
    {
        cout << "\nYes, Month is last Month in year";
    }
    else
        cout << "\nNo, Month is NOt last Month in year";
}

/*

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
    return ((Year % 400 == 0) || (Year % 100 != 0 && Year % 4 == 0));
}

bool IsLastDayInMonth(stDate Date)
{
    return (Date.Month == 2)                                                                                                                       ? (IsLeapYear(Date.Year)) ? (Date.Day == 29) ? true : false : (Date.Day == 28) ? true
                                                                                                                                                                                                                                  : false
           : (Date.Month == 1 || Date.Month == 3 || Date.Month == 5 || Date.Month == 7 || Date.Month == 8 || Date.Month == 10 || Date.Month == 12) ? (Date.Day == 31) ? true : false
           : (Date.Day == 30)                                                                                                                      ? true
                                                                                                                                                   : false;

    /*if (Date.Month == 2)
    {
        if(IsLeapYear(Year))
        {
            if(Date.Day==29)
            {
                return true;
            }
            return false;
        }

        if(Date.Day==28)
        {
            return true;
        }
        else
            return fasle;
    }

    if (Date.Month == 1 || Date.Month == 3 || Date.Month == 5 || Date.Month == 7 || Date.Month == 8 || Date.Month == 10 || Date.Month == 12)
    {
        if (Date.Day == 31)
        {
            return true;
        }
        else
            return false;
    }

    if (Date.Day == 30)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool IsLastMonthInYear(stDate Date)
{
    return (Date.Month == 12) ? true : false;
}

int main()
{
    stDate Date = ReadFullDate();

    if (IsLastDayInMonth(Date))
    {
        cout << "\nYes, Day is last day in month";
    }
    else
    {
        cout << "\nNo, Day is NOT last day in month";
    }

    if (IsLastMonthInYear(Date))
    {
        cout << "\nYes, Month is last Month in year";
    }
    else
        cout << "\nNo, Month is NOt last Month in year";
}
*/