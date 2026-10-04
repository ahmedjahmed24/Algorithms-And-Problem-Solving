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

int CountDigitFrequency(short DigitToCheck, int Number)
{
    int Remainder = 0;
    int FreqCount = 0;

    while (Number > 0)
    {
        Remainder = Number % 10;

        if (Remainder == DigitToCheck)
        {
            FreqCount++; // 5
            // FreqCount=FreqCount+1;
        }

        Number = Number / 10;
    }

    return FreqCount;
}

int main()
{
    int Number = ReadPositiveNumber("Enter The Main Number :");
    short DigitToCheck = ReadPositiveNumber("Enter a Digit To Check :");

    cout << "Digit " << DigitToCheck << " Frequency is " << CountDigitFrequency(DigitToCheck, Number) << " Time(s).";
}