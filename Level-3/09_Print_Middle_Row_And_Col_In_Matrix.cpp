/*
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
            arr[i][j] = RandomNumber(1, 10);
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
        cout << "\n";
    }
}

void PrintMiddleRow(int arr[3][3], short RowNumber, short Cols)
{
    for (short i = 0; i < RowNumber; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            cout << arr[RowNumber][j] << "   ";
        }
    }
}

void PrintMiddleCol(int arr[3][3], short Rows, short ColNumber)
{
    for (short j = 0; j < ColNumber; j++)
    {
        for (short i = 0; i < Rows; i++)
        {
            cout << arr[i][ColNumber] << "   ";
        }
    }
}

int main()
{
    srand((unsigned)time(NULL));

    int Matrix1[3][3];
    FillMatrixWithRandomNumber(Matrix1, 3, 3);

    cout << "\nMatrix 1:\n";
    PrintMatrix(Matrix1, 3, 3);

    cout << "\nMiddle row :\n";
    PrintMiddleRow(Matrix1, 1, 3);

    cout << "\nMiddle Col :\n";
    PrintMiddleCol(Matrix1, 3, 1);
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

void FillMatrixWithRandomNumber(int arr[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            arr[i][j] = RandomNumber(1, 10);
        }
    }
}

void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            printf(" %0*d  ", 2, arr[i][j]);
            // cout<<setw(3)<<arr[i][j];
        }
        cout << "\n";
    }
}

void PrintMiddleRowInMatrix(int arr[3][3], short Rows, short Cols)
{
    short MiddleRow = Rows / 2; // 3/2=1

    for (short i = 0; i < Rows; i++)
    {
        printf(" %0*d  ", 2, arr[MiddleRow][i]);
        // cout << arr[MiddleRow][i] << "   ";
    }
}

void PrintMiddleColInMatrix(int arr[3][3], short Rows, short Cols)
{
    short MiddleCol = Cols / 2; // 3/2=1;

    for (short j = 0; j < Cols; j++)
    {
        printf(" %0*d  ", 2, arr[j][MiddleCol]);
        // cout << arr[j][MiddleCol] << "   ";
    }
}

int main()
{
    srand((unsigned)time(NULL));

    int Matrix1[3][3];
    FillMatrixWithRandomNumber(Matrix1, 3, 3);

    cout << "\nMatrix 1:\n";
    PrintMatrix(Matrix1, 3, 3);

    cout << "\nMiddle row in matrix :\n";
    PrintMiddleRowInMatrix(Matrix1, 3, 3);

    cout << "\nMiddle Col in matrix :\n";
    PrintMiddleColInMatrix(Matrix1, 3, 3);
}