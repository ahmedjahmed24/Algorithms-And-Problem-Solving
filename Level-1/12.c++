#include <iostream>
using namespace std;

void ReadNumbers(int &Num1, int &Num2)
{
    cout << "Enter Number 1 :\n";
    cin >> Num1;
    cout << "Enter Number 2 :\n";
    cin >> Num2;
}

int MaxOf2Numbers(int Num1, int Num2)
{
    if (Num1 > Num2)
    {
        return Num1;
    }
    else
        return Num2;
}

void PrintResult(int Max)
{
    cout << "The Maximum Number is : " << Max;
}

int main()
{
    int Num1, Num2;

    ReadNumbers(Num1, Num2);
    PrintResult(MaxOf2Numbers(Num1, Num2));
}