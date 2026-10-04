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
    cout << "\nEnter number of array elements : ";
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

int EvenCount(int arr[100], int ArrLength)
{
    short Counter = 0;

    for (int i = 0; i < ArrLength; i++)
    {
        if (arr[i] % 2 == 0)
        {
            Counter++;
        }
    }

    return Counter;
}

int main()
{
    srand((unsigned)time(NULL));

    int arr[100], ArrLength;

    FillArrayWithRandomNumbers(arr, ArrLength);

    cout << "\nArray elements :\n";
    PrintArray(arr, ArrLength);

    cout << "\nEven numbers count is : ";
    cout << EvenCount(arr, ArrLength);
}