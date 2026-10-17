#include <iostream>
using namespace std;

short ReadYear()
{
    short Year;

    cout << "Enter a Year :\n";
    cin >> Year;

    return Year;
}

bool IsLeapYear(short Year)
{
    if (Year % 400 == 0)
    {
        return true;
    }

    else if (Year % 100 == 0)
    {
        return false;
    }
    else if (Year % 4 == 0)
    {
        return true;
    }
    else
        return false;
}

int main()
{
    short Year = ReadYear();

    if (IsLeapYear(Year))
    {
        cout << " Yes, year [" << Year << "] is a leap year";
    }
    else
        cout << "No, year [" << Year << "] is NOT a leap year";
}

/*
my solution
#include <iostream>
using namespace std;

short ReadYear()
{
    short Year;

    cout << "Enter a Year :\n";
    cin >> Year;

    return Year;
}

bool IsLeapYear(short Year)
{
    if (Year % 400 == 0)
    {
        return true;
    }
    else if (Year % 4 == 0 && Year % 100 != 0)
    {
        return true;
    }
    else
        return false;
}

int main()
{
    short Year = ReadYear();

    if (IsLeapYear(Year))
    {
        cout << "[" << Year << "] is a leap year";
    }
    else
        cout << "[" << Year << "] is NOT a leap year";
}

*/
