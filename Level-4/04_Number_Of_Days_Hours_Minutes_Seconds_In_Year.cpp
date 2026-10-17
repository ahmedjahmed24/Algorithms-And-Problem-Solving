/*
my solution

#include <iostream>
using namespace std;

short ReadYear()
{
    short Year = 0;

    cout << "Enter a year :\n";
    cin >> Year;

    return Year;
}

bool IsLeapYear(short Year) // 2004
{
    return ((Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0));
}

short NumberOfDays(short Year) // 2004
{
    return IsLeapYear(Year) ? 366 : 365;
}

int NumberOfHours(short NumberOfDays)
{
    return NumberOfDays * 24;
}

int NumberOfMinutes(int NumberOfHours)
{
    return NumberOfHours * 60;
}

int NumberOfSeconds(int NumberOfMinutes)
{
    return NumberOfMinutes * 60;
}

int main()
{
    short Year = ReadYear();

    short NumOfDays = NumberOfDays(Year);
    int NumOfHours = NumberOfHours(NumOfDays);
    int NumOfMinutes = NumberOfMinutes(NumOfHours);
    int NumOfSeconds = NumberOfSeconds(NumOfMinutes);

    cout << "\nNumber of days in Year [" << Year << "] is : " << NumOfDays << endl;   // 366
    cout << "\nNumber of hours in Year [" << Year << "] is : " << NumOfHours << endl; //
    cout << "\nNumber of minutes in Year [" << Year << "] is : " << NumOfMinutes << endl;
    cout << "\nNumber of seconds in Year [" << Year << "] is : " << NumOfSeconds;
}

*/

#include <iostream>
using namespace std;

short ReadYear()
{
    short Year = 0;

    cout << "Enter a Year to check : ";
    cin >> Year;

    return Year;
}

bool IsLeapYear(short Year)
{
    return ((Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0));
}

short NumberOfDaysInAYear(short Year)
{
    return IsLeapYear(Year) ? 366 : 365;
}

short NumberOfHoursInAYear(short Year)
{
    return NumberOfDaysInAYear(Year) * 24;
}

int NumberOfMinutesInAYear(short Year)
{
    return NumberOfHoursInAYear(Year) * 60;
}

int NumberOfSecondsInAYear(short Year)
{
    return NumberOfMinutesInAYear(Year) * 60;
}

int main()
{
    short Year = ReadYear();

    cout << "\nNumber of Days in Year [" << Year << "] is "
         << NumberOfDaysInAYear(Year);
    cout << "\nNumber of Hours in Year [" << Year << "] is "
         << NumberOfHoursInAYear(Year);
    cout << "\nNumber of Minutes in Year [" << Year << "] is "
         << NumberOfMinutesInAYear(Year);
    cout << "\nNumber of Seconds in Year [" << Year << "] is "
         << NumberOfSecondsInAYear(Year);
}
