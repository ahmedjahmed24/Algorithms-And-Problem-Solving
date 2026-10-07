#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int RandomNumber(int From, int To)
{
    int randnum = rand() % (To - From + 1) + From;
    return randnum;
}

void FillMatrixWithRandomNumber(int arr[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            arr[i][j] = RandomNumber(1, 100);
        }
    }
}

int ColSum(int arr[3][3], short Rows, short ColNumber)
{
    int Sum = 0;

    for (short i = 0; i < Rows; i++)
    {
        Sum = Sum + arr[i][ColNumber];
    }
    return Sum;
}

void AddSumToArray(int arr[3][3], int arrSum[3], short Rows, short Cols)
{
    for (short i = 0; i < Cols; i++)
    {
        arrSum[i] = ColSum(arr, Rows, i);
    }
}

void PrintArraySum(int arrsum[3], short length) // هي بالاخير هي ون دايمنشنال ارراي ف بمشي فيا من الصفر يعني من الاول لل لينجث تبعا
{
    cout << "\n The following are the sum of each col in the matrix :\n";
    for (short i = 0; i < length; i++)
    {
        cout << " Col " << i + 1 << " Sum = " << arrsum[i] << endl;
    }
}

void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            cout << setw(3) << arr[i][j] << "   ";
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    srand((unsigned)time(NULL));

    int arr[3][3];
    int arrSum[3];
    FillMatrixWithRandomNumber(arr, 3, 3);

    cout << "\nThe following is a 3x3 random matrix :\n";
    PrintMatrix(arr, 3, 3);

    AddSumToArray(arr, arrSum, 3, 3);
    PrintArraySum(arrSum, 3);
}