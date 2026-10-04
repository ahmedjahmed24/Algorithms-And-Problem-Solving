#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

enum enPrimeNotPrime
{
    Prime = 1,
    NotPrime = 2
};

int RandomNumber(int From, int To)
{
    int RandNum = rand() % (To - From + 1) + From;
    return RandNum;
}

void FillArrayWithRandomNumber(int arr[100], int &ArrLength)
{
    cout << "Enter Number Of Array Elements : ";
    cin >> ArrLength;

    for (int i = 0; i < ArrLength; i++)
    {
        arr[i] = RandomNumber(1, 100);
    }
}

void PrintArray(int arr[100], int ArrLength)
{
    for (int i = 0; i < ArrLength; i++)
    {
        cout << arr[i] << " ";
    }
}

void AddArrayElement(int Number, int arr[100], int &ArrLength)
{
    ArrLength++;
    arr[ArrLength - 1] = Number;
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

void CopyPrimeNumbers(int arrSource[100], int arrDestination[100], int &Arr1Length, int &Arr2Length)
{
    for (int i = 0; i < Arr1Length; i++)
    {
        if (CheckPrime(arrSource[i]) == enPrimeNotPrime::Prime)
        {
            AddArrayElement(arrSource[i], arrDestination, Arr2Length);
        }
    }
}

int main()
{
    srand((unsigned)time(NULL));
    
    int arr[100], Arr1Length;
    int arr2[100], Arr2Length = 0;

    FillArrayWithRandomNumber(arr, Arr1Length);

    cout << "\nArray 1 elements :\n";
    PrintArray(arr, Arr1Length);

    CopyPrimeNumbers(arr, arr2, Arr1Length, Arr2Length);

    cout << "\nArray 2 elements after copy odd numbers :\n";
    PrintArray(arr2, Arr2Length);
}