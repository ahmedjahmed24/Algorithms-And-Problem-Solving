#include <iostream>
using namespace std;

int ReadPositiveNumber(string Message)
{
    int Number = 0;

    do
    {
        cout << Message << endl;
        cin >> Number;

    } while (Number <= 0);

    return Number;
}

int CountDigitFrequency(int Number, short DigitToCheck)
{
    int Remainder = 0;
    int FreqCount = 0;

    while (Number > 0)
    {
        Remainder = Number % 10;

        if (Remainder == DigitToCheck)
        {
            FreqCount++;
        }

        Number = Number / 10;
    }

    return FreqCount;
}

void PrintAllDigitFrequency(int Number)
{
    short DigitFrequency = 0;
    for (int i = 0; i < 10; i++)
    {
        DigitFrequency = CountDigitFrequency(Number, i);
        if (DigitFrequency > 0)
        {
            cout << i << " Frequency is " << DigitFrequency << " Time(s)." << endl;
        }
    }
}

int main()
{
    int Number=ReadPositiveNumber("Enter a Positive Number :");
    PrintAllDigitFrequency(Number);
}