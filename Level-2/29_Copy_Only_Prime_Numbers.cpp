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

void FillArrayWithRandomNumbers(int arr[100], int &ArrLength)
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

void CopyOnlyPrimNumbers(int arrSource[100], int arrDestination[100], int ArrLength, int &Arr2Length)
{
    int Counter = 0;

    for (int i = 0; i < ArrLength; i++)
    {
        if (CheckPrime(arrSource[i]) == enPrimeNotPrime::Prime)
        {
            arrDestination[Counter] = arrSource[i];
            Counter++;
        }
    }

    Arr2Length = --Counter;
}

int main()
{
    srand((unsigned)time(NULL));

    int arr[100], ArrLength;

    FillArrayWithRandomNumbers(arr, ArrLength);
    int arr2[100], Arr2Length;
    CopyOnlyPrimNumbers(arr, arr2, ArrLength, Arr2Length);

    cout << "\nArray 1 Elements :\n";
    PrintArray(arr, ArrLength);

    cout << "\nArray 2 Elements After Copy Only Prime Numbers :\n";
    PrintArray(arr2, Arr2Length);
}