#include <iostream>
using namespace std;

short ReadYear()
{
    short Year = 0;

    cout << "Enter a Year : ";
    cin >> Year;

    return Year;
}

short ReadMonth()
{
    short Month = 0;

    do
    {
        cout << "Enter a Month : ";
        cin >> Month;

    } while (Month < 1 || Month > 12);

    return Month;
}

bool IsLeapYear(short Year)
{
    return ((Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0));
}

short ReadDay()
{
    short Day = 0;

    cout << "Enter a Day : ";
    cin >> Day;

    return Day;
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

short NumberOfDaysFromTheBeginingOfYear(short Year, short Month, short Day)
{
    short TotalDays = 0;

    for (short i = 1; i <= Month - 1; i++)
    {
        TotalDays += NumberOfDaysInAMonth(Year, i);
    }

    TotalDays += Day;

    return TotalDays;
}

int main()
{
    short Day = ReadDay();
    short Month = ReadMonth();
    short Year = ReadYear();

    cout << "\nNumber Of Days From The Begining of the year is " << NumberOfDaysFromTheBeginingOfYear(Year, Month, Day);
}

/*
حلي اقوى من حلو من حيث الفاليدايشن

#include <iostream>
using namespace std;

short ReadYear()
{
    short Year = 0;

    cout << "Enter a Year : ";
    cin >> Year;

    return Year;
}

short ReadMonth()
{
    short Month = 0;

    do
    {
        cout << "Enter a Month : ";
        cin >> Month;

    } while (Month < 1 || Month > 12);

    return Month;
}

bool IsLeapYear(short Year)
{
    return ((Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0));
}

short ReadDay(short Year, short Month)
{
    short Day = 0;

    if (Month == 2)
    {
        if (IsLeapYear(Year))
        {
            do
            {
                cout << "Enter a Day between 1->29 : ";
                cin >> Day;

            } while (Day < 1 || Day > 29);
        }
        else

            do
            {
                cout << "Enter a Day between 1->28 : ";
                cin >> Day;

            } while (Day < 1 || Day > 28);
    }

    else if (Month == 1 || Month == 3 || Month == 5 || Month == 7 || Month == 8 || Month == 10 || Month == 12)
    {
        do
        {
            cout << "Enter a Day between 1->31 : ";
            cin >> Day;

        } while (Day < 1 || Day > 31);
    }

    else
    {
        do
        {
            cout << "Enter a Day between 1->30 : ";
            cin >> Day;

        } while (Day < 1 || Day > 30);
    }

    return Day;
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

short NumberOfDaysFromTheBeggingOfYear(short Year, short Month, short Day)
{
    short NumberOfDays = 0;

    for (short i = 1; i <= 12; i++)
    {
        if (i == Month)
        {
            NumberOfDays = NumberOfDays + Day;
            return NumberOfDays;
        }

        NumberOfDays = NumberOfDays + NumberOfDaysInAMonth(Year, i);
    }


}

int main()
{
    short Year = ReadYear();
    short Month = ReadMonth();
    short Day = ReadDay(Year, Month);

    cout << "\nNumber Of Days From The Begining of the year is " << NumberOfDaysFromTheBeggingOfYear(Year, Month, Day);
}

*/
