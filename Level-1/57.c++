#include <iostream>
using namespace std;

int ReadNumber()
{
    int N;

    cout << "Enter a Number : ";
    cin >> N;

    return N;
}

void PrintRangeNumbersFrom1ToN_UsingWhile(int N)
{
    cout << "Print Range Number From 1 To " << N << " Using While Loop :\n";

    int Counter = 1;

    while (Counter <= N)
    {
        cout << Counter << endl;
        Counter++;
    }
}

void PrintRangeNumbersFrom1ToN_UsingDoWhile(int N)
{

    cout << "Print Range Number From 1 To " << N << " Using Do While Loop :\n";

    int Counter = 1;

    do
    {
        cout << Counter << endl;
        Counter++;
    } while (Counter <= N);
}

void PrintRangeNumbersFrom1ToN_UsingFor(int N)
{
    cout << "Print Range Number From 1 To " << N << " Using Do While Loop :\n";

    for (int Counter = 1; Counter <= N; Counter++)
    {
        cout << Counter << endl;
    }
}

int main()
{

    PrintRangeNumbersFrom1ToN_UsingWhile(ReadNumber());
    PrintRangeNumbersFrom1ToN_UsingDoWhile(ReadNumber());
    PrintRangeNumbersFrom1ToN_UsingFor(ReadNumber());
}