#include <iostream>
using namespace std;

void ReadNumbers(int &Num1, int &Num2, int &Num3)
{
    cout << "Enter Number 1 :\n";
    cin >> Num1;
    cout << "Enter Number 2 :\n";
    cin >> Num2;
    cout << "Enter Number 3 :\n";
    cin >> Num3;
}

int SumOf3Numbers(int Num1, int Num2, int Num3)
{
    return Num1 + Num2 + Num3;
}

void PrintResults(int Total)
{
    cout << "Sum Of 3 Numbers = " << Total;
}

int main()
{
    int Num1, Num2, Num3;
    ReadNumbers(Num1, Num2, Num3);
    PrintResults(SumOf3Numbers(Num1, Num2, Num3));
}