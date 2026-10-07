#include <iostream>
using namespace std;

void PrintFibonacciUsingLoop(short Number)
{
    int FebNumber = 0;
    int Prev1 = 1, Prev2 = 0;

    cout << "1   ";
    for (int i = 2; i <= Number; i++)
    {
        FebNumber = Prev1 + Prev2;
        cout << FebNumber << "   ";
        Prev2 = Prev1;
        Prev1 = FebNumber;
    }
}

int main()
{
    short Number = 0;
    cout << "Enter a number :\n";
    cin >> Number;

    cout << "Fibonacci series for number " << Number << " : ";
    PrintFibonacciUsingLoop(Number);
}