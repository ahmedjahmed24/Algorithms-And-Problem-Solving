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

// bool IsValidDate(stDate Date)
// {
//     if (Date.Day < 1 || Date.Day > 31)
//     {
//         return false;
//     }

//     if (Date.Month < 1 || Date.Month > 12)
//     {
//         return false;
//     }

//     if (Date.Month == 2)
//     {
//         if (IsLeapYear(Date.Year))
//         {
//             if (Date.Day > 29)
//             {
//                 return false;
//             }
//         }
//         else
//         {
//             if (Date.Day > 28)
//             {
//                 return false;
//             }
//         }
//     }

//     short DaysInMonth = NumberOfDaysInAMonth(Date.Year, Date.Month);

//     if (Date.Day > DaysInMonth)
//     {
//         return false;
//     }

//     return true;
// }

bool IsValidDate(stDate Date)
{
    if (Date.Month < 1 || Date.Month > 12 || Date.Day < 1 || Date.Day > 31)
    {
        return false;
    }

    short DaysInMonth = NumberOfDaysInAMonth(Date.Year, Date.Month); // بيعطيني عدد الايام الصحيحة في الشهر

    return Date.Day <= DaysInMonth;
}

int main()
{
    stDate Date = ReadFullDate();

    if (IsValidDate(Date))
    {
        cout << "\nYes, Date is valid";
    }
    else
        cout << "\nNo, Date is NOT valid";
}