#include <iostream>
using namespace std;

float ReadPositiveNumber(string Message)
{
    float Number = 0;

    do
    {
        cout << Message << endl;
        cin >> Number;

    } while (Number <= 0);

    return Number;
}

float HoursToDays(float NumberOfHours)
{
    return (float)NumberOfHours / 24;
}

float HoursToWeeks(float NumberOfHours)
{
    return (float)NumberOfHours / 24 / 7;
}

float DaysToWeeks(float NumberOfDays)
{
    return (float)NumberOfDays / 7;
}

int main()
{
    float NumberOfHours = ReadPositiveNumber("Enter Number Of Hours : ");
    float NumberOfDays = HoursToDays(NumberOfHours);

    cout << "Total Hours : " << NumberOfHours << endl;
    cout << "Number Of Days : " << NumberOfDays << endl;
    cout << "Number Of Weeks : " << HoursToWeeks(NumberOfHours) << endl;
    cout << "Number Of Weeks (Days To Weeks) : " << DaysToWeeks(NumberOfDays) << endl;
}

/*#include <iostream>
using namespace std;

float ReadPositiveNumber(string Message)
{
    float Number = 0;

    do
    {
        cout << Message << endl;
        cin >> Number;

    } while (Number <= 0);

    return Number;
}

float HoursToDays(float NumberOfHours)
{
    return (float)NumberOfHours / 24;
}

float HoursToWeeks(float NumberOfHours)
{
    return (float)NumberOfHours / 24 / 7;
}

float DaysToWeeks(float NumberOfDays)
{
    return (float)NumberOfDays / 7;
}

int main()
{
    float NumberOfHours = ReadPositiveNumber("Enter Number Of Hours :");

    float NumberOfDays = HoursToDays(NumberOfHours);
    float NumberOffWeeks = HoursToWeeks(NumberOfHours);
    float NumberOfWeeks = DaysToWeeks(NumberOfDays);

    cout<<"Total Hours : "<<NumberOfHours<<endl;
    cout << "Number Of Days : " << NumberOfDays << endl;
    cout << "Number Of Weeks : " << NumberOffWeeks << endl;
    cout << "Number Of Weeks : " << NumberOfWeeks << endl;
}*/