#include <iostream>
using namespace std;

int FibonacciUsingRecursion(short Number)
{
    if (Number == 0)
    {
        return 0;
    }
    else if (Number == 1)
    {
        return 1;
    }
    else
        return FibonacciUsingRecursion(Number - 1) + FibonacciUsingRecursion(Number - 2);
}

void PrintFibonacciSeriesFrom1ToNumber(short Number)
{
    for (int i = 1; i <= Number; i++)
    {
        cout << FibonacciUsingRecursion(i) << "   ";
    }
}

int main()
{
    short Number = 0;
    cout << "Enter a number : ";
    cin >> Number;

    cout << "Fibonacci series for number " << Number << " : ";
    PrintFibonacciSeriesFrom1ToNumber(Number);
}