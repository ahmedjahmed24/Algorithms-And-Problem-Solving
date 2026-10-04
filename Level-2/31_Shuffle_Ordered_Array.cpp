#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int RandomNumber(int From, int To)
{
    int RandNum = rand() % (To - From + 1) + From;
    return RandNum;
}

void FillArrayFrom1ToNumber(int arr[100], int &ArrLength)
{
    cout << "Enter Number Of Elements :";
    cin >> ArrLength; // 10

    for (int i = 0; i < ArrLength; i++)
    {
        arr[i] = i + 1;
    }
}

void PrintArray(int arr[100], int ArrLength)
{
    for (int i = 0; i < ArrLength; i++)
    {
        cout << arr[i] << " ";
    }
}

void ShuffleArrayElements(int arr[100], int ArrLength)
{
    for (int i = 0; i < ArrLength; i++)
    {
        arr[i] = RandomNumber(1, ArrLength);
    }
}

int main()
{
    srand((unsigned)time(NULL));

    int arr[100], ArrLength;

    FillArrayFrom1ToNumber(arr, ArrLength);

    cout << "\nArray Elements Before Shuffle :\n";
    PrintArray(arr, ArrLength);

    ShuffleArrayElements(arr, ArrLength);
    cout << "\nArray Elements After Shuffle :\n";
    PrintArray(arr, ArrLength);
}