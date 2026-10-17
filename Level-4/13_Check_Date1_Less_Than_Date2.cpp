// روح بسسسرررعة لااتفكرر شووف حلي
#include <iostream>
using namespace std;

struct stDate
{
    short Year = 0;
    short Month = 0;
    short Day = 0;
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

bool IsDate1LessThanDate2(stDate Date1, stDate Date2)
{
    return (Date1.Year < Date2.Year) ? true : (Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month) ? true : (Date1.Month == Date2.Month) ? (Date1.Day < Date2.Day) : false
                                                                                                                                             : false;
}

int main()
{
    stDate Date1 = ReadFullDate();
    cout << endl;
    stDate Date2 = ReadFullDate();

    if (IsDate1LessThanDate2(Date1, Date2))
    {
        cout << "\nYes, Date 1 is less than date 2";
    }
    else
        cout << "\nNo, Date 1 is NOT Less than Date 2";
}