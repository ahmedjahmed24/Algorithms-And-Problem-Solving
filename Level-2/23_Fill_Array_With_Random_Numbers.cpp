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

void PrintArray(int arr[100], int Arrlength)
{
    cout << "Array Elements :\n";

    for (int i = 0; i < Arrlength; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    srand((unsigned)time(NULL));

    int arr[100], Arrlength;

    FillArrayWithRandomNumbers(arr, Arrlength);
    PrintArray(arr, Arrlength);
}