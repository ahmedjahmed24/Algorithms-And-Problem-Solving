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

int SumOfDigits(int Number)
{
    int Remainder = 0;
    int Sum = 0;

    while (Number > 0)
    {
        Remainder = Number % 10; // R=1234%10=4  R=123%10=3 R=12%10=2 R=1%10=1
        Sum = Sum + Remainder;   // sum=0+4=4 sum=4+3=7 sum=7+2=9 sum=9+1=10
        Number = Number / 10;    // N=1234/10=123 N=123/10=12 N=12\10=1 N=1/10=0
    }

    return Sum;
}

int main()
{
    cout << "Sum Of Digits = " << SumOfDigits(ReadPositiveNumber("Enter a Positive Number :"));
}