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

bool IsPerfectNumber(int Number)
{
    int Sum = 0;

    for (int i = 1; i < Number; i++)
    {
        if (Number % i == 0)
        {
            Sum = Sum + i;
        }
    }

    return Sum == Number;
}

void PrintResult(int Number)
{
    if (IsPerfectNumber(Number))
    {
        cout << Number << " is Perfect Number\n";
    }
    else
        cout << Number << " is Not Perfect Number";
}

int main()
{
    PrintResult(ReadPositiveNumber("Please Enter a Positive Number :"));
}


  /*حلي للمشكلة
#include <iostream>
using namespace std;

enum enDivasorNotDivasor
{
    Divasor = 1,
    NotDivasor = 2
};

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

enDivasorNotDivasor IsDivasor(int Number, int i)
{
    if (Number % i == 0)
    {
        return enDivasorNotDivasor::Divasor;
    }
    else
        return enDivasorNotDivasor::NotDivasor;
}

int SumDivasorsNumbers(int Number)
{
    int Sum = 0;

    for (int i = 1; i < Number; i++)
    {
        if (IsDivasor(Number, i) == enDivasorNotDivasor::Divasor)
        {
            Sum = Sum + i;
        }
    }

    return Sum;
}

bool CheckSumDivasorsandNumber(int Number)
{
    if (SumDivasorsNumbers(Number) == Number)
    {
        return true;
    }
    else
        return false;
}

void PrintPerfectOrNot(int Number)
{
    if (CheckSumDivasorsandNumber(Number) == true)
    {
        cout << Number << " is Perfect\n";
    }
    else
        cout << Number << " is Not Perfect\n";
}

int main()
{
    PrintPerfectOrNot(ReadPositiveNumber("Enter a Positive Number :"));
}
*/

/*
  حلي الاول للمشكلة
#include <iostream>
using namespace std;

enum enDivasorNotDivasor
{
    Divasor = 1,
    NotDivasor = 2
};

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

enDivasorNotDivasor IsDivasorNumber(int Number, int i)
{
    if (Number % i == 0)
    {
        return enDivasorNotDivasor::Divasor;
    }
    else
        return enDivasorNotDivasor::NotDivasor;
}

int Sum(int Number)
{
    int Sum = 0;

    for (int i = 1; i < Number; i++)
    {
        if (IsDivasorNumber(Number, i) == enDivasorNotDivasor::Divasor)
        {
            Sum = Sum + i; // sum=0+1=1 sum=1+2=3 sum=3+3=6
        }
    }
    return Sum;
}

void CheckPerfectNumber(int Number)
{
    if (Sum(Number) == Number)
    {
        cout << Number << " is Perfect";
    }
    else
        cout << Number << " is Not Perfect";
}

int main()
{
    CheckPerfectNumber(ReadPositiveNumber("Enter a Positive Number :"));
}*/