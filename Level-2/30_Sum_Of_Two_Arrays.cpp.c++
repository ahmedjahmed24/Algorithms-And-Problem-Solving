#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int ReadPositiveNumber(string Message)
{
    int Number=0;

    do
    {
        cout<<Message<<endl;
        cin>>Number;

    } while (Number<=0);
    
    return Number;
}

int RandomNumbers(int From, int To)
{
    int RandNum = rand() % (To - From + 1) + From;
    return RandNum;
}

void FillArrayWithRandomNumbers(int arr[100], int ArrLength)
{
    for (int i = 0; i < ArrLength; i++)
    {
        arr[i] = RandomNumbers(1, 100);
    }
}

void PrintArray(int arr[100], int ArrLength)
{
    for (int i = 0; i < ArrLength; i++)
    {
        cout << arr[i] << " ";
    }
}

void SumOf2Arrays(int arr1[100],int arr2[100],int arrSum[100],int ArrLength)
{
    for (int i = 0; i < ArrLength; i++)
    {
        arrSum[i]=arr1[i]+arr2[i];
    }
    
}

int main()
{
    srand((unsigned)time(NULL));

    int arr1[100],arrSum[100],arr2[100], ArrLength;

    ArrLength=ReadPositiveNumber("How Many Numbers :");

    FillArrayWithRandomNumbers(arr1, ArrLength);
    FillArrayWithRandomNumbers(arr2, ArrLength);
    SumOf2Arrays(arr1,arr2,arrSum,ArrLength);

    cout << "\nArray 1 Elements :\n";
    PrintArray(arr1, ArrLength);

    cout << "\nArray 2 Elements :\n";
    PrintArray(arr2, ArrLength);

    cout<<"\nSum Of Array 1 Elements and Array 2 Elements :\n";
    PrintArray(arrSum,ArrLength);
}