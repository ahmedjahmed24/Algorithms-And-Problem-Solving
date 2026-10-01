#include <iostream>
using namespace std;

int ReadNumber()
{
    int N;

    cout << "Enter a Number : ";
    cin >> N;

    return N;
}

void PrintRangeNumbersFromNTo1_UsingWhile(int N)
{
    cout << "Print Range Number From " << N << " To 1 Using While Loop :\n";

    int Counter = N;

    while (Counter >= 1)
    {
        cout << Counter << endl;
        Counter--;
    }
}

void PrintRangeNumbersFromNTo1_UsingDoWhile(int N)
{

    cout << "Print Range Number From " << N << " To 1 Using Do While Loop :\n";

    int Counter = N;

    do
    {
        cout << Counter << endl;
        Counter--;
    } while (Counter >= 1);
}

void PrintRangeNumbersFromNTo1_UsingFor(int N)
{
    cout << "Print Range Number From " << N << " To 1 Using For Loop :\n";

    for (int Counter = N; Counter >= 1; Counter--)
    {
        cout << Counter << endl;
    }
}

int main()
{
    int N = ReadNumber();

    PrintRangeNumbersFromNTo1_UsingWhile(N);
    PrintRangeNumbersFromNTo1_UsingDoWhile(N);
    PrintRangeNumbersFromNTo1_UsingFor(N);
}