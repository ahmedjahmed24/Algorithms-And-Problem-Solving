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

void PrintDigits(int Number)
{
    int Remainder = 0;

    while (Number > 0)
    {
        Remainder = Number % 10;   // 1234 % 10 =4  123 % 10 =3 r=12%10=2 1%10=1
        Number = Number / 10;      // number=1234/10=123 number=123/10=12 number=12/10=1 number=1/10=0
        cout << Remainder << endl; // 4  3  2  1
    }
}

int main()
{
    PrintDigits(ReadPositiveNumber("Enter a Positive Number :"));
}

/*
Another Solution
#include <iostream>
#include <string>
using namespace std;

int ReadPositiveNumber(string Message)
{
    int Number = 0;

    do
    {
        cout << Message;
        cin >> Number;

    } while (Number < 0);

    return Number;
}

void PrintDigits(int Number)
{
    string n = to_string(Number);
    int x = n.length();

    // cout << n << endl;
    // cout << x << endl;

    for (int i = 1; i <= x; i++)
    {
        cout << n[x - i] << endl;
    }
}

int main()
{
    PrintDigits(ReadPositiveNumber("Enter a Positive Number :"));
}*/