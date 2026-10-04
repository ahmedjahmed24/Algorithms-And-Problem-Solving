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

void PrintLetterPattern(int Number)
{
    cout << "\n";
    for (int i = 65; i <= 65 + Number - 1; i++)
    {
        for (int j = 1; j <= i - 65 + 1; j++)
        {
            cout << char(i);
        }
        cout << "\n";
    }
}

int main()
{
    PrintLetterPattern(ReadPositiveNumber("Please enter a positive number?"));
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

void PrintNumberPattern(int Number)
{
    short CountLetter = 65;
    short c = 0;

    cout << "\n";

    for (int i = 1; i <= Number; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << char(CountLetter+c);
        }
        cout << "\n";
        c++;
    }
}

int main()
{
    PrintNumberPattern(ReadPositiveNumber("Enter a Positive Number :"));
}*/