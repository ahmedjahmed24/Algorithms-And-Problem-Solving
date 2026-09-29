#include <iostream>
using namespace std;

enum OddOrEven
{
    Odd = 1,
    Even = 2
};

int ReadNumber()
{
    int N;

    cout << "Enter a Number :";
    cin >> N;

    return N;
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

int SumEvenNumbersFrom1ToN_UsingWhile(int N)
{

    cout << "Sum Even Numbers Using While Loop :\n";

    int Sum = 0;
    int Counter = 1;

    while (Counter <= N)
    {

        if (CheckOddOrEven(Counter) == OddOrEven::Even)
        {
            Sum += Counter;
        }

        Counter++;
    }

    return Sum;
}

int SumEvenNumbersFrom1ToN_UsingDoWhile(int N)
{
    cout << "Sum Even Numbers Using Do While Loop :\n";

    int Sum = 0;
    int Counter = 1;

    do
    {
        Counter++;

        if (CheckOddOrEven(Counter) == OddOrEven::Even)
        {
            Sum += Counter;
        }
    } while (Counter <= N);

    return Sum;
}

int SumEvenNumbersFrom1ToN_UsingFor(int N)
{
    int Sum = 0;

    cout << "Sum Even Numbers Using For Loop :\n";

    for (int Counter = 1; Counter <= N; Counter++)
    {
        if (CheckOddOrEven(Counter) == OddOrEven::Even)
        {
            Sum+=Counter;
        }
        Counter++;
    }

    return Sum;
}

int main()
{
    int N = ReadNumber();

    cout << SumEvenNumbersFrom1ToN_UsingWhile(N) << endl;
    cout << SumEvenNumbersFrom1ToN_UsingDoWhile(N) << endl;
    cout << SumEvenNumbersFrom1ToN_UsingFor(N) << endl;
}