#include <iostream>
#include <cmath>
using namespace std;

enum enPrimeNotPrime
{
    Prime = 1,
    NotPrime = 2
};

float ReadPositiveNumber(string Messsage)
{
    float Number = 0;

    do
    {
        cout << Messsage << endl;
        cin >> Number;

    } while (Number <= 0);

    return Number;
}

enPrimeNotPrime CheckPrime(int Number)
{
    int M = round(Number / 2);

    for (int Counter = 2; Counter <= M; Counter++)
    {
        if (Number % Counter == 0)
        {
            return enPrimeNotPrime::NotPrime;
        }
    }
            return enPrimeNotPrime::Prime;
}

void PrintNumberType(int Number)
{
    switch (CheckPrime(Number))
    {
    case enPrimeNotPrime::Prime:
        cout << "The Number is Prime";
        break;
    case enPrimeNotPrime::NotPrime:
        cout << "The Number is Not Prime";
        break;
    }
}

int main()
{
    float Number=ReadPositiveNumber("Enter a Positive Number :");
    PrintNumberType(CheckPrime(Number));
    
    // printNumberType(ReadPositiveNumber("Enter a Positive Number :"));
}