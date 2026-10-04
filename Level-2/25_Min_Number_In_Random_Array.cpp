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
    cout << "Enter Number Of Array Elements :";
    cin >> ArrLength;

    for (int i = 0; i < ArrLength; i++)
    {
        arr[i] = RandomNumber(1, 100);
    }
}

void PrintArrayElements(int arr[100], int ArrLength)
{

    for (int i = 0; i < ArrLength; i++)
    {
        cout << arr[i] << " ";
    }
}

int MinNumberInArray(int arr[100], int ArrLength)
{
    int Min = 0;// قيمة ابتدائية 
    Min = arr[0];

    for (int i = 0; i < ArrLength; i++)
    {
        if (arr[i] < Min)
        {
            Min = arr[i];
        }
    }

    return Min;
}

int main()
{
    srand((unsigned)time(NULL));

    int arr[100], ArrLength;

    FillArrayWithRandomNumbers(arr, ArrLength);
    cout << "Array Elements :\n";
    PrintArrayElements(arr, ArrLength);
    cout << "\nMin Number is : " << MinNumberInArray(arr, ArrLength);
}