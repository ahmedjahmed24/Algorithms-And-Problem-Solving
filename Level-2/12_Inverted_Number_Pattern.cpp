// دائما المشاكل من هذه الانواع تكون عدد الاسطر هي الفور الخارجية والفور الداخلية هي عدد الاعمدة
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

    }  while (Number <= 0);

    return Number;
}

void PrintInvertedNumberPattern(int Number)
{
    cout << "\n";

    for (int i = Number; i >= 1; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << i;
        }
        cout << "\n";
    }
}

int main()
{
    PrintInvertedNumberPattern(ReadPositiveNumber("Please enter a positive number?"));
    return 0;
}

/*
Another Solution
#include<iostream>
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

void PrintInventedPatternNumber(int Number)
{
    for (int i = Number; i >= 1; i--)
    {
        for (int j = i; j > 0; j--)
        {
            cout << i;
        }

        cout << endl;
    }
}

int main()
{
    PrintInventedPatternNumber(ReadPositiveNumber("Enter a Positive Number :"));
}*/

/*
انا مبالي هيك كان السؤال شوف خرجو واعمل متلو لانو كمان سؤال حلوو
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

void PrintInventedPatternNumber(int Number)
{
    for (int i = Number; i >= 1; i--)
    {
        for (int j = i; j > 0; j--)
        {
            cout << Number;
        }

        cout << endl;
    }
}

int main()
{
    PrintInventedPatternNumber(ReadPositiveNumber("Enter a Positive Number :"));
}*/