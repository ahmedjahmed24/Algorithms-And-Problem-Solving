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
    cout << "Enter Number of Array Elements : ";
    cin >> ArrLength;

    for (int i = 0; i < ArrLength; i++)
    {
        arr[i] = RandomNumber(1, 100);
    }
}

void PrintArray(int arr[100], int ArrLnegth)
{
    for (int i = 0; i < ArrLnegth; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}

short FindNumberPositionInArray(int Number, int arr[100], int ArrLength)
{
    for (int i = 0; i < ArrLength; i++)
    {
        if (arr[i] == Number)
        {
            return i;// return position in array
        }
    }

    return -1;
}

int ReadNumber()
{
    int Number = 0;

    cout << "Enter a Number to search for :\n";
    cin >> Number;

    return Number;
}

int main()
{
    srand((unsigned)time(NULL));

    int arr[100], ArrLength;

    FillArrayWithRandomNumbers(arr, ArrLength);

    cout << "Array Elements :\n";
    PrintArray(arr, ArrLength);

    int Number = ReadNumber();

    cout << "The Number you are looking for is : " << Number << endl;

    short NumberPosition = FindNumberPositionInArray(Number, arr, ArrLength);

    if (NumberPosition == -1)
    {
        cout << "The Number is not found :-(";
    }
    else
    {
        cout << "The Number found at position " << NumberPosition << endl;
        cout << "The Number found at order " << NumberPosition + 1 << endl;
    }
}