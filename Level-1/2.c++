#include <iostream>
#include <string>
using namespace std;

string ReadName()
{
    string Name;

    cout << "Enter Your Name : \n";
    getline(cin, Name);

    return Name;
}

void PrintName(string Name)
{
    cout << "Your Name is : " << Name << endl;
}

int main()
{
    PrintName(ReadName());
}