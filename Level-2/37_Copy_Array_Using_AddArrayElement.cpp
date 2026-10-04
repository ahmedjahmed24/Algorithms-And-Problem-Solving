#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

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

void AddArrayElement(int Number, int arr[100], int &ArrLength)
{
    ArrLength++;
    arr[ArrLength - 1] = Number;
}

void CopyArrayUsingAddArrayElement(int arrSource[100], int arrDestination[100], int Arr1Length, int &Arr2Length)
{
    for (int i = 0; i < Arr1Length; i++)
    {
        AddArrayElement(arrSource[i], arrDestination, Arr2Length);
    }
}

int main()
{
    srand((unsigned)time(NULL));

    int arr[100], Arr1Length, Arr2Length = 0;

    FillArrayWithRandomNumbers(arr, Arr1Length);

    int arr2[100];
    CopyArrayUsingAddArrayElement(arr, arr2, Arr1Length, Arr2Length);

    cout << "\nArray 1 Elements :\n";
    PrintArray(arr, Arr1Length);

    cout << "\nArray 2 Elements After Copy Using AddArrayElement :\n";
    PrintArray(arr2, Arr2Length);
}