#include <iostream>
using namespace std;

struct stInfo
{
    string FirstName;
    string LastName;
};

stInfo ReadInfo()
{
    stInfo Info;

    cout << "Enter Your First Name : \n";
    cin >> Info.FirstName;
    cout << "Enter Your Last Name :\n";
    cin >> Info.LastName;

    return Info;
}

string GetFullName(stInfo Info, bool Reversed)
{
    string FullName = "";

    if (Reversed == true)
    {
        FullName = Info.LastName + " " + Info.FirstName;
    }
    else
        FullName = Info.FirstName + " " + Info.LastName;

    return FullName;
}

void PrintFullName(string FullName)
{
    cout << "Your Full Name is : " << FullName << endl;
}

int main()
{
    PrintFullName(GetFullName(ReadInfo(), false));
}