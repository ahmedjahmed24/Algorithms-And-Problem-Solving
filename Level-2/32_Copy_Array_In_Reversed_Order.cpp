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
    cout<<"Enter Number Of Elements : ";
    cin>>ArrLength;

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

void CopyArrayInReversed(int ArrSource[100],int ArrReverse[100], int ArrLength)
{

    for (int i = 0; i < ArrLength; i++)
    {
        ArrReverse[i]=ArrSource[ArrLength-1-i];
    }

    /*int j=0;

    for (int i = ArrLength-1; i >= 0; i--)
    {
        ArrReverse[j]=ArrSource[i];
        j++;
    }*/
    
}

int main()
{
    srand((unsigned)time(NULL));

    int arr[100],arr2[100],ArrLength;

    FillArrayWithRandomNumbers(arr, ArrLength);
    cout << "\nArray 1 Elements :\n";
    PrintArray(arr, ArrLength);

    CopyArrayInReversed(arr,arr2, ArrLength);
    cout << "\nArray 2 Elements After Copying Array 1 in Reversed order :\n";
    PrintArray(arr2, ArrLength);
}