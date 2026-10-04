#include <iostream>
using namespace std;

void FillArray(int arr[100], int &ArrLength)
{
    ArrLength = 10;

    arr[0] = 10;
    arr[1] = 10;
    arr[2] = 10;
    arr[3] = 50;
    arr[4] = 50;
    arr[5] = 70;
    arr[6] = 70;
    arr[7] = 70;
    arr[8] = 70;
    arr[9] = 90;
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

short FindNumberPosition(int Number, int arr[100], int ArrLength)
{
    for (int i = 0; i < ArrLength; i++)
    {
        if (arr[i] == Number)
        {
            return i;
        }
    }

    return -1;
}

bool IsNumberInArray(int Number, int arr[100], int ArrLength)
{
    return FindNumberPosition(Number, arr, ArrLength) != -1;
}
// 10 10 10 50  50 70 70 70 70 90
// 10 50 70 90
void CopyDistinticNumbers(int arrSource[100], int arrDestination[100], int SourceLength, int &DestinationLength)
{
    for (int i = 0; i < SourceLength; i++)
    {
        if (!IsNumberInArray(arrSource[i], arrDestination, DestinationLength))
        {
            AddArrayElement(arrSource[i], arrDestination, DestinationLength);
        }
    }
}

int main()
{
    int arrSource[100], arrDestination[100], SourceLength = 0, DestinationLength = 0;

    FillArray(arrSource, SourceLength);

    cout << "\nArray 1 elements :\n";
    PrintArray(arrSource, SourceLength);

    CopyDistinticNumbers(arrSource, arrDestination, SourceLength, DestinationLength);

    cout << "\nArray 2 elements :\n";
    PrintArray(arrDestination, DestinationLength);
}