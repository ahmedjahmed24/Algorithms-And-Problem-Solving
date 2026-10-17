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

short ReadDay()
{
    short Day = 0;

    cout << "Enter a Day : ";
    cin >> Day;

    return Day;
}

short DayOfWeekOrdre(short Year, short Month, short Day)
{
    short a, y, m;
    a = (14 - Month) / 12;
    y = Year - a;
    m = Month + (12 * a) - 2;

    return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

string DayName(short DayOfWeekOrdre)
{
    string arrDayName[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

    return arrDayName[DayOfWeekOrdre];
}

int main()
{
    short Year = ReadYear();
    short Month = ReadMonth();
    short Day = ReadDay();

    cout << "\n\nDate    : " << Day << "/" << Month << "/" << Year;
    cout << "\nDay Order : " << DayOfWeekOrdre(Year, Month, Day);
    cout << "\nDay Name  : " << DayName(DayOfWeekOrdre(Year, Month, Day));
}

/*
حلي اقوى من حل الاستاذ في validation

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

short ReadDay(short Year,short Month)
{
    short Day=0;

    if(Month==2)
    {
        if(IsLeapYear(Year))
        {
            do
            {
                cout<<"Enter a Day between 1->29 : ";
                cin>>Day;
            }
            while(Day<1 || Day>29);
        }

        else
        {
           do
            {
                cout<<"Enter a Day between 1->28 : ";
                cin>>Day;
            }
            while(Day<1 || Day>28);
        }


    }

    else if(Month==1 || Month==3 || Month==5 || Month==7 || Month==8 || Month==10 || Month==12)
    {
        do
            {
                cout<<"Enter a Day between 1->31 : ";
                cin>>Day;
            }
            while(Day<1 || Day>31);
    }

    else
    {
        do
            {
                cout<<"Enter a Day between 1->30 : ";
                cin>>Day;
            }
            while(Day<1 || Day>30);
    }

    return Day;
}

short DayOrdre(short Year, short Month, short Day)
{
    short a = 0;
    a = (14 - Month) / 12;

    short y = 0;
    y = Year - a;

    short m = 0;
    m = Month + (12 * a - 2);

    short d = 0;
    d = (Day + y + (y / 4) - (y / 100) + (y / 400) + ( (31 * m) / 12 ) ) % 7;

    return d;
}

string DayName(short d)
{
    string arrDayName[7] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

    return arrDayName[d];
}

int main()
{
    short Year = ReadYear();
    short Month = ReadMonth();
    short Day = ReadDay(Year,Month);

    cout << "\n\nDate    : " << Day << "/" << Month << "/" << Year;
    cout << "\nDay Order : " << DayOrdre(Year, Month, Day);
    cout << "\nDay Name  : " << DayName(DayOrdre(Year, Month, Day));
}
*/
