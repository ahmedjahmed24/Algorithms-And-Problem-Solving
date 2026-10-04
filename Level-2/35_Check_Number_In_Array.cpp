#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int RandomNumber(int From, int To)
{
    int RandNum = rand() % (To - From + 1) + From;
    return RandNum;
}

void FillArrayWithRandomNumber(int arr[100], int &ArrLength)
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

int ReadNumber()
{
    int Number = 0;

    cout << "\nEnter a number you are looking for :\n";
    cin >> Number;

    return Number;
}

bool IsNumberInArray(int Number,int arr[100],int ArrLength)
{
    return FindNumberPosition(Number,arr,ArrLength)!=-1;
}

int main()
{
    srand((unsigned)time(NULL));

    int arr[100], ArrLength;

    FillArrayWithRandomNumber(arr, ArrLength);

    cout << "Array elements :\n";
    PrintArray(arr, ArrLength);

    int Number = ReadNumber();
    cout << "The Number you are looking for is : " << Number << endl;

    if (!IsNumberInArray(Number,arr,ArrLength))
    {
        cout<<"No,the number is not found :-(";
    }
    else
        cout<<"Yes,the number is found";
    
}