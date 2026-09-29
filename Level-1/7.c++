#include <iostream>
using namespace std;

int ReadNumber()
{
    int Num;

    cout << "Enter a Number :\n";
    cin >> Num;

    return Num;
}

float CalculateHalfNumber(int Num)
{
    return (float)Num / 2;
}

void PrintResults(int Num)
{
    string Results = "Half Of " + to_string(Num) + " is " + to_string(CalculateHalfNumber(Num));
    cout << Results;
}

int main()
{
    PrintResults(ReadNumber());
}