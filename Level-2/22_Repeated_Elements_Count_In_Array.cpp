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

void ReadArray(int arr[100], int &ArrLength)
{
    cout << "Enter Number Of Elements :";
    cin >> ArrLength;

    cout << "\nEnter Array Elements :\n";

    for (int i = 0; i < ArrLength; i++)
    {
        cout << "Element [" << i + 1 << "] : ";
        cin >> arr[i];
    }

    cout << endl;
}

void PrintArray(int arr[100], int ArrLength)
{
    for (int i = 0; i < ArrLength; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int TimesRepeted(int arr[100], int ArrLength, int NumberToCheck)
{
    int Counter = 0;

    for (int i = 0; i <= ArrLength; i++)
    {
        if (arr[i] == NumberToCheck)
        {
            Counter++;
        }
    }

    return Counter;
}

int main()
{
    int arr[100], ArrLength, NumberToCheck;

    ReadArray(arr, ArrLength);

    NumberToCheck = ReadPositiveNumber("Enter Number To Check :");

    cout << "Original Array : ";
    PrintArray(arr, ArrLength);

    cout<<"\nNumber "<<NumberToCheck;
    cout<<" is Repeted ";
    cout << TimesRepeted(arr, ArrLength, NumberToCheck) << " Time(s)";
}