#include <iostream>
#include <cmath>
using namespace std;

struct stTaskDuration
{
    int NumberOfDays, NumberOfHours, NumberOfMinute, NumberOfSeconds;
};

int ReadPositiveNumber(string Message)
{
    int Number = 0;

    do
    {
        cout << Message << endl;
        cin >> Number;
    } while (Number <= 0);

    return Number;
}

stTaskDuration TaskDuration(int TotalSeconds)
{
    stTaskDuration Task;
    int NumberOfSeconds = 0;
    int Remainder = 0;

    const int SecPerDay = 24 * 60 * 60;
    const int SecPerHour = 60 * 60;
    const int SecPerMinute = 60;

    Task.NumberOfDays = floor(TotalSeconds / SecPerDay);
    Remainder = TotalSeconds % SecPerDay;

    Task.NumberOfHours = floor(Remainder / SecPerHour);
    Remainder = Remainder % SecPerHour;

    Task.NumberOfMinute = floor(Remainder / SecPerMinute);
    Remainder = Remainder % SecPerMinute;

    Task.NumberOfSeconds=Remainder;

    return Task;
}

void PrintTaskDuration(stTaskDuration Task)
{
    cout << Task.NumberOfDays << " : " << Task.NumberOfHours << " : " << Task.NumberOfMinute << " : " << Task.NumberOfSeconds;
}

int main()
{
    int TotalSeconds = ReadPositiveNumber("Enter Number Of Total Seconds :");

    PrintTaskDuration(TaskDuration(TotalSeconds));
}