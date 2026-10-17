#include <iostream>
using namespace std;

short ReadYear()
{
    short Year = 0;
    cout << "Enter a Year: ";
    cin >> Year;
    return Year;
}

string MonthName(short Month)
{
    string arrMonthName[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    return arrMonthName[Month - 1];
}

short DayOfWeekOrdre(short Year, short Month, short Day)
{
    short a, y, m;
    a = (14 - Month) / 12;
    y = Year - a;
    m = Month + (12 * a) - 2;
    return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

bool IsLeapYear(short Year)
{
    return (Year % 400 == 0 || (Year % 4 == 0 && Year % 100 != 0)); // استخدم || للتحقق من القيم الصحيحة
}

short NumberOfDaysInMonth(short Year, short Month)
{
    if (Month < 1 || Month > 12)
    {
        return 0;
    }
    short NumberOfDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : NumberOfDays[Month - 1];
}

void PrintMonthCalender(short Year, short Month)
{
    printf("\n__________________%s________________\n\n", MonthName(Month).c_str());
    printf(" Sun Mon Tue Wed Thu Fri Sat\n");

    short NumberOfDays = NumberOfDaysInMonth(Year, Month);
    short Current = DayOfWeekOrdre(Year, Month, 1); // اليوم الأول من الشهر

    // طباعة المسافات الفارغة قبل اليوم الأول
    int i;
    for (i = 0; i < Current; i++)
    {
        printf("    "); // استخدم مسافة واحدة فقط لتناسب التنسيق
    }

    // طباعة الأيام
    for (short j = 1; j <= NumberOfDays; j++)
    {
        printf("%3d ", j); // استخدم %3d لتوفير تنسيق مناسب

        if (++i == 7)
        {                 // إذا كانت نهاية الأسبوع
            i = 0;        // إعادة تعيين إلى بداية الأسبوع
            printf("\n"); // الانتقال إلى السطر التالي
        }
    }

    printf("\n_____________________________________\n");
}

void PrintYearCalender(short Year)
{
    printf("\n\n_____________________________________________________\n\n");
    printf("                  Calender - %d               ", Year);
    printf("\n________________________________________________________\n\n");

    for (short i = 1; i <= 12; i++)
    {
        PrintMonthCalender(Year, i);
    }
}

int main()
{
    PrintYearCalender(ReadYear());
}
