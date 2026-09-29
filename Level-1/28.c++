#include <iostream>
using namespace std;

enum OddOrEven
{
    Odd = 1,
    Even = 2
};

int ReadNumber()
{
    int Number;

    cout << "Enter a Number :";
    cin >> Number;

    return Number;
}

OddOrEven CheckOddOrEven(int Number)
{
    if (Number % 2 != 0)
    {
        return OddOrEven::Odd;
    }
    else
        return OddOrEven::Even;
}

int SumOddNumbersFrom1ToN_UsingWhile(int N)
{

    cout << "Sum Odd Numbers Using While :\n";

    int Sum = 0;
    int Counter = 1;

    while (Counter <= N)
    {
        if (CheckOddOrEven(Counter) == OddOrEven::Odd)
        {
            Sum = Sum + Counter;
        }

        Counter++;
    }

    return Sum;
}

int SumOddNumbersFrom1ToN_UsingDoWhile(int N)
{

    cout << "Sum Odd Numbers Using Do While :\n";

    int Sum = 0;
    int Counter = 0;

    do
    {
        Counter++;
        if (CheckOddOrEven(Counter) == OddOrEven::Odd)
        {
            Sum += Counter;
        }
    } while (Counter < N);

    return Sum;
}

int SumOddNumbersFrom1ToN_UsingFor(int N)
{

    cout << "Sum Odd Numbers Using For Loop :\n";

    int Sum = 0;

    for (int Counter = 1; Counter <= N; Counter++)
    {
        if (CheckOddOrEven(Counter) == OddOrEven::Odd)
        {
            Sum += Counter;
        }
    }

    return Sum;
}

int main()
{
    int N = ReadNumber();

    cout << SumOddNumbersFrom1ToN_UsingWhile(N) << endl;
    cout << SumOddNumbersFrom1ToN_UsingDoWhile(N) << endl;
    cout << SumOddNumbersFrom1ToN_UsingFor(N) << endl;
}