#include <iostream>
using namespace std;

struct stInfo
{
    int Age;
    bool HasDrivingLiscense;
};

stInfo ReadInfo()
{
    stInfo Info;

    cout << "Enter Your Age :\n";
    cin >> Info.Age;

    cout << "Do You Have a Driving Liscense ? \n";
    cin >> Info.HasDrivingLiscense;

    return Info;
}

bool IsAccepted(stInfo Info)
{
    return (Info.Age > 21 && Info.HasDrivingLiscense == 1);
}

void PrintResult(stInfo Info)
{
    if (IsAccepted(Info))
    {
        cout << "Hired\n";
    }
    else
        cout << "Rejected\n";
}

int main()
{
    PrintResult(ReadInfo());
}