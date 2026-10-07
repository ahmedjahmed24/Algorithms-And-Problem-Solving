/*
Another Solution
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int RandomNumber(int From, int To)
{
    int RandNum = rand() % (To - From + 1) + From;
    return RandNum;
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
}

void SumEachRow(int arr[3][3], short Rows, short Cols)
{
    short Count = 1;
    short Sum = 0;

    if (Count <= Rows) // 1<=3 4<=3
    {
        for (short i = 0; i < Rows; i++) // 0<3  1<3  2<3  3<3
        {
            for (short j = 0; j < Cols; j++) // 0<3  1<3  2<3  3<3
            {
                Sum = Sum + arr[i][j]; // sum=0+7=7  sum=16  sum=25
            }
            cout << "\nThe following is sum of row " << Count << " : " << Sum << endl; // row 1 = 6  row 2 =15  row 3 = 25
            Count++;                                                                   // 2  3  4
            Sum = 0;
        }
    }
}

int main()
{
    srand((unsigned)time(NULL));

    int arr[3][3];
    FillMatrixWithRandomNumbers(arr, 3, 3);

    cout << "\nThe following is a 3x3 random matrix :\n";
    PrintMatrix(arr, 3, 3);

    SumEachRow(arr, 3, 3);
}
*/

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

void PrintEachRowSum(int arr[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        cout << " Row " << i + 1 << " Sum = " << RowSum(arr, i, 3) << endl;
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
    FillMatrixWithRandomNumbers(arr, 3, 3);

    cout << "\nThe following is a 3x3 random matrix :\n";
    PrintMatrix(arr, 3, 3);

    PrintEachRowSum(arr, 3, 3);
}