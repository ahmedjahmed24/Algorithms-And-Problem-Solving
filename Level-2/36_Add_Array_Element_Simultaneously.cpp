#include <iostream>
using namespace std;

int ReadNumber()
{
    int Number = 0;

    cout << "Please enter a number ?\n";
    cin >> Number;

    return Number;
}

void AddArrayElement(int Number, int arr[100], int &ArrLength)
{
    ArrLength++;
    arr[ArrLength - 1] = Number;
}

void InputUserArray(int arr[100], int &ArrLength)
{
    bool AddMore = true;

    do
    {
        AddArrayElement(ReadNumber(), arr, ArrLength);

        cout << "Do you want to enter more number ? [0]:No,[1]:Yes\n";
        cin >> AddMore;

    } while (AddMore == true);
}

void PrintArray(int arr[100], int ArrLength)
{
    for (int i = 0; i < ArrLength; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr[100], ArrLength = 0;

    InputUserArray(arr, ArrLength);

    cout << "\nArray length : " << ArrLength << endl;
    cout << "\nArray elements : ";
    PrintArray(arr, ArrLength);
}