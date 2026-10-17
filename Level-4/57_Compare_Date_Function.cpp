#include <iostream>
using namespace std;

enum enCompareDates
{
    Before = -1,
    Equal = 0,
    After = 1
};

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

bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{
    return (Date1.Year < Date2.Year) ? true : (Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month) ? true : (Date1.Month == Date2.Month) ? (Date1.Day < Date2.Day)
                                                                                                                                             : false
                                                                         : false;
}

bool IsDate1EqualDate2(stDate Date1, stDate Date2)
{
    return (Date1.Year == Date2.Year) ? (Date1.Month == Date2.Month) ? (Date1.Day == Date2.Day) : false : false;
}

bool IsDate1AfterDate2(stDate Date1, stDate Date2)
{
    return !IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2);
}

enCompareDates CompareDates(stDate Date1, stDate Date2)
{
    if (IsDate1BeforeDate2(Date1, Date2))
    {
        return enCompareDates::Before;
    }

    else if (IsDate1EqualDate2(Date1, Date2))
    {
        return enCompareDates::Equal;
    }

    else
        return enCompareDates::After;
}

int main()
{
    cout << "\nEnter Date1 :\n";
    stDate Date1 = ReadFullDate();

    cout << "\nEnter Date2 :\n";
    stDate Date2 = ReadFullDate();

    cout << "\nCompare Result : " << CompareDates(Date1, Date2);
}