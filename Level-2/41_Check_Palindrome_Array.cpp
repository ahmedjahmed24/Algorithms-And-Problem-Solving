#include <iostream>
using namespace std;

void FillArray(int arr[100], int &ArrLength)
{
    ArrLength = 6;

    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;
    arr[3] = 30;
    arr[4] = 20;
    arr[5] = 10;
}

void PrintArray(int arr[100], int ArrLength)
{
    for (int i = 0; i < ArrLength; i++)
    {
        cout << arr[i] << " ";
    }
}

bool IsPalindromeArray(int arr[100],int ArrLength)
{
    int Counter=0;

    for (int i = 0; i < ArrLength; i++)
    {
        if (arr[Counter]!=arr[ArrLength-i-1])
        {
            return false;
        }
        Counter++;
        
    }
    return true;
}

int main()
{
    int arr[100], ArrLength = 0;

    FillArray(arr, ArrLength);

    cout << "\nArray elements :\n";
    PrintArray(arr, ArrLength);

    if (IsPalindromeArray(arr, ArrLength))
    {
        cout << "\nArray is palindrome";
    }
    else
        cout << "\nArray is Not palindrome";
}