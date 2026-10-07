#include <iostream>
using namespace std;

void FillMatrixWithOrderedNumbers(int arr[3][3], short Rows, short Cols)
{
    int Counter = 0;

    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            Counter++;
            arr[i][j] = Counter;
        }
    }
}

void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            cout << arr[i][j] << "   ";
        }
        cout << endl;
    }
}

void FillTransposeMatrix(int arr[3][3], int arrTrasposed[3][3], short Rows, short cols)
{
    short ColNumber = 0;

    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            arrTrasposed[i][j] = arr[j][ColNumber];
        }
        ColNumber++;
    }
}

int main()
{
    int arr[3][3];
    int arrTransposed[3][3];

    FillMatrixWithOrderedNumbers(arr, 3, 3);

    cout << "\nThe following is a 3x3 ordered matrix :\n";
    PrintMatrix(arr, 3, 3);

    FillTransposeMatrix(arr, arrTransposed, 3, 3);
    cout << "\nThe following is the transposed matrix :\n";
    PrintMatrix(arrTransposed, 3, 3);
}