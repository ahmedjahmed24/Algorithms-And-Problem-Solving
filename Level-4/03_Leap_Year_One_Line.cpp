#include <iostream>
using namespace std;

short ReadYear()
{
    short Year = 0;

    cout << "Enter a year :\n";
    cin >> Year;

    return Year;
}

bool IsLeapYear(short Year)
{
    // اذا كانت السنة تقبل القسمة على 400 معناها خلص هية ليب يير من دون ماتختبر اي شي تاني مافي شرط تاني او لازم تكون بتقبل القسمة على 4 وبنفس الوقت يعني في شرط تاني انو ماتقبل القسمة على 100
    return ((Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0));
}

int main()
{
    short Year = ReadYear();

    if (IsLeapYear(Year))
    {
        cout << "Yes, Year [" << Year << "] is a leap year";
    }
    else
        cout << "No, Year [" << Year << "] is NOT a leap year";
}