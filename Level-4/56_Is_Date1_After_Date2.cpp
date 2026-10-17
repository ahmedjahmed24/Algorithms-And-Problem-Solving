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

bool IsDate1AfterDate2(stDate Date1, stDate Date2) // 1/1/2022   1/1/2000
{
    // return (Date1.Year > Date2.Year) ? true : (Date1.Year == Date2.Year) ? (Date1.Month > Date2.Month) ? true : (Date1.Month == Date2.Month) ? (Date1.Day > Date2.Day)
    //                                                                                                                                          : false
    //                                                                     : false;

    return !IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2);
}

int main()
{
    cout << "\nEnter Date1 :\n";
    stDate Date1 = ReadFullDate();

    cout << "\nEnter Date2 :\n";
    stDate Date2 = ReadFullDate();

    if (IsDate1AfterDate2(Date1, Date2))
    {
        cout << "\nYes, Date 1 After Date 2";
    }
    else
        cout << "\nNo, Date 1 is NOT After Date2";
}