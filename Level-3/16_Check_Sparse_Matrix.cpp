#include <iostream>
using namespace std;

void PrintMatrix(int Matrix[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            printf(" %0*d  ", 2, Matrix[i][j]);
        }
        cout << "\n";
    }
}

short CountNumberInMatrix(int Matrix[3][3], short NumberToCount, short Rows, short Cols)
{
    short NumberCount = 0;

    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            if (Matrix[i][j] == NumberToCount)
            {
                NumberCount++;
            }
        }
    }

    return NumberCount++;
}

/*bool IsSparseMatrix(int Matrix[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            if (CountNumberInMatrix(Matrix, 0, Rows, Cols) < 5)
            {
                return false;
            }
        }
    }

    return true;
}*/

bool IsSparseMatrix(int Matrix[3][3], short Rows, short Cols)
{
    float SizeMatrix = Rows * Cols;

    return CountNumberInMatrix(Matrix, 0, 3, 3) >= SizeMatrix / 2;
}

int main()
{
    int Matrix[3][3] = {{0, 0, 1}, {0, 0, 9}, {10, 10, 3}};

    cout << "\nMatrix :\n";
    PrintMatrix(Matrix, 3, 3);

    if (IsSparseMatrix(Matrix, 3, 3))
    {
        cout << "Yes : it is a Sparse Matrix";
    }
    else
        cout << "No : it is NOT a Sparse matrix";
}