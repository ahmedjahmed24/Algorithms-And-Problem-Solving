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

void CopyArray(int arrSource[100], int arrDestination[100], int ArrLength)
{
    for (int i = 0; i < ArrLength; i++)
    {
        arrDestination[i] = arrSource[i];
    }
}

int main()
{
    srand((unsigned)time(NULL));

    int arr[100], ArrLength;

    FillArrayWithRandomNumbers(arr, ArrLength);

    int arr2[100];
    CopyArray(arr, arr2, ArrLength);

    cout << "\nArray 1 Elements :\n";
    PrintArray(arr, ArrLength);

    cout << "\nArray 2 Elements After Copy :\n";
    PrintArray(arr2, ArrLength);
}