#include <iostream>
using namespace std;

short ReadYear()
{
    short Year = 0;

    cout << "Enter a Year to check : ";
    cin >> Year;

    return Year;
}

short ReadMonth()
{
    short Month = 0;

    cout << "Enter a Month to check : ";
    cin >> Month;

    return Month;
}

bool IsLeapYear(short Year)
{
    return ((Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0));
}

short NumberOfDaysInMonth(short Year, short Month)
{
    if (Month == 2)
    {
        return IsLeapYear(Year) ? 29 : 28;
    }

    short arr31Days[7] = {1, 3, 5, 7, 8, 10, 12};

    for (short i = 1; i <= 7; i++)
    {
        if (arr31Days[i] == Month)
        {
            return 31;
        }
    }

    // if (Month == 1 || Month == 3 || Month == 5 || Month == 7 || Month == 8 || Month == 10 || Month == 12)
    //{
    //   return 31;
    // }

    return 30;
}

short NumberOfHoursInMonth(short Year, short Month)
{
    return NumberOfDaysInMonth(Year, Month) * 24;
}

int NumberOfMinutesInMonth(short Year, short Month)
{
    return NumberOfHoursInMonth(Year, Month) * 60;
}

int NumberOfSecondsInMonth(short Year, short Month)
{
    return NumberOfMinutesInMonth(Year, Month) * 60;
}

int main()
{
    short Year = ReadYear();
    short Month = ReadMonth();

    cout << "\nNumber of Days in Month [" << Month << "] is " << NumberOfDaysInMonth(Year, Month);
    cout << "\nNumber of Hours in Month [" << Month << "] is " << NumberOfHoursInMonth(Year, Month);
    cout << "\nNumber of Minutes in Month [" << Month << "] is " << NumberOfMinutesInMonth(Year, Month);
    cout << "\nNumber of Seconds in Month [" << Month << "] is " << NumberOfSecondsInMonth(Year, Month);
}