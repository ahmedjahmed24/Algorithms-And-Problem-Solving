#include <iostream>
using namespace std;

struct stTaskDuration
{
    int NumberOfDays, NumberOfHours, NumberOfMinutes, NumberOfSeconds;
};

int ReadPositiveNumber(string Message)
{
    int Number = 0;

    do
    {
        cout << Message << endl;
        cin >> Number;

    } while (Number < 0);

    return Number;
}

stTaskDuration TaskDuration()
{
    stTaskDuration TaskDuration;

    TaskDuration.NumberOfDays = ReadPositiveNumber("Enter Number Of Days :");
    TaskDuration.NumberOfHours = ReadPositiveNumber("Enter Number Of Hours :");
    TaskDuration.NumberOfMinutes = ReadPositiveNumber("Enter Number Of Minutes :");
    TaskDuration.NumberOfSeconds = ReadPositiveNumber("Enter Number Of Seconds :");

    return TaskDuration;
}

int CalculateTotalSeconds(stTaskDuration TaskDuration)
{
    int TotslSeconds = 0;

    int DaysToSeconds = TaskDuration.NumberOfDays * (24 * 60 * 60);
    int HoursToSeconds = TaskDuration.NumberOfHours * (60 * 60);
    int MinutesToSeconds = TaskDuration.NumberOfMinutes * (60);
    int SecondsToSeconds = TaskDuration.NumberOfSeconds * (1);

    TotslSeconds = DaysToSeconds + HoursToSeconds + MinutesToSeconds + SecondsToSeconds;

    return TotslSeconds;
}

int main()
{
    cout << CalculateTotalSeconds(TaskDuration());
}