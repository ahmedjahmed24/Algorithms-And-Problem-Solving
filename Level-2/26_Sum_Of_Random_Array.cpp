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
    cout << "\nEnter Number Of Array Elements :\n";
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
    cout << "\n";
}

int SumNumbersInArray(int arr[100], int ArrLength)
{
    int Sum = 0;

    for (int i = 0; i < ArrLength; i++)
    {
        // Sum = Sum + arr[i];
        Sum += arr[i];
    }

    return Sum;
}

int main()
{
    srand((unsigned)time(NULL));

    int arr[100], ArrLength;

    FillArrayWithRandomNumbers(arr, ArrLength);

    cout << "\nArray Elements : ";
    PrintArray(arr, ArrLength);

    cout << "\nSum Of All Numbers : " << SumNumbersInArray(arr, ArrLength);
}