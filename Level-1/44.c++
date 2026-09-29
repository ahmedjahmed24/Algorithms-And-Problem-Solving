#include <iostream>
using namespace std;

enum enDayNumber
{
    Sun = 1,
    Mon = 2,
    Tue = 3,
    Wed = 4,
    Thu = 5,
    Fri = 6,
    Sat = 7
};

int ReadNumberInRange(string Message, int From, int To)
{
    int Number = 0;

    do
    {
        cout << Message << endl;
        cin >> Number;
    } while (Number < From || Number > To);

    return Number;
}

enDayNumber ReadDayOfWeek()
{
    return (enDayNumber)ReadNumberInRange("Enter Day Number Between 1 and 7",1,7);
}

string GetDayNumber(enDayNumber DayNumber)
{
    switch (DayNumber)
    {
    case enDayNumber::Sun:
        return "Sunday";
    case enDayNumber::Mon:
        return "Monday";
    case enDayNumber::Tue:
        return "Tuesday";
    case enDayNumber::Wed:
        return "Wedensday";
    case enDayNumber::Thu:
        return "Thursday";
    case enDayNumber::Fri:
        return "Friday";
    case enDayNumber::Sat:
        return "Satrday";

    default:
        return "Wrong Day Number !";
    }
}

int main()
{
    cout<<GetDayNumber(ReadDayOfWeek());
}