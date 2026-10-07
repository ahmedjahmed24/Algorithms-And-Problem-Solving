#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int RandomNumber(int From, int To)
{
    int randnum = rand() % (To - From + 1) + From;
    return randnum;
}

void FillMatrixWithRandomNumbers(int arr[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            arr[i][j] = RandomNumber(1, 100);
        }
    }
}

int RowSum(int arr[3][3], short RowNumber, short Cols)
{
    int Sum = 0;

    for (short i = 0; i < Cols; i++)
    {
        Sum = Sum + arr[RowNumber][i];
    }

    return Sum;
}

void AddSumInArray(int arr[3][3], int arrSum[3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        arrSum[i] = RowSum(arr, i, 3);
    }
}

void PrintSumOfEachRowInArraySum(int arrSum[3], short length)
{
    for (short i = 0; i < length; i++)
    {
        cout << " Row " << i + 1 << " Sum = " << arrSum[i] << endl;
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
        cout << "\n";
    }
}

int main()
{
    srand((unsigned)time(NULL));

    int arr[3][3];
    int arrSum[3];
    FillMatrixWithRandomNumbers(arr, 3, 3);

    cout << "\nThe following is a 3x3 random matrix :\n";
    PrintMatrix(arr, 3, 3);

    AddSumInArray(arr, arrSum, 3, 3);
    PrintSumOfEachRowInArraySum(arrSum, 3);
}