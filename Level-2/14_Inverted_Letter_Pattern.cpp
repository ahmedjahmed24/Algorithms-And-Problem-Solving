#include <iostream>
#include <string>
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

void PrintInvertedLetterPattern(int Number)
{
    cout << "\n";
    for (int i = 65 + Number - 1; i >= 65; i--)
    {
        for (int j = 1; j <= Number - (65 + Number - 1 - i); j++)
        {
            cout << char(i);
        }
        cout << "\n";
    }
}
int main()
{
    PrintInvertedLetterPattern(ReadPositiveNumber("Please enter a positive number?"));
    return 0;
}

/*
Another Solution
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

void PrintInvertedLetterPattern(int Number)
{
    int CountLetter = 65;
    short c = 1;

    cout << "\n";

    for (int i = Number; i >= 1; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << char(CountLetter + (Number - c));
        }
        cout << endl;
        c++;
    }
}

int main()
{
    PrintInvertedLetterPattern(ReadPositiveNumber("Enter a Positive Number :"));
}*/