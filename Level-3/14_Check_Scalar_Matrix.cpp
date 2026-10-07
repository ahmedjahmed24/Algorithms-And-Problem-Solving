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
        cout << endl;
    }
}

bool IsScalarMatrix(int Matrix[3][3], short Rows, short Cols)
{
    short FirstDiagonalValue = Matrix[0][0];

    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            if (i == j && Matrix[i][j] != FirstDiagonalValue) // العنصر على القطر الرئيسي اذا كان لايساوي اول عنصر على القطر الرئيسي برجع فولص
            {
                return false;
            }
            else if (i != j && Matrix[i][j] != 0) // اذا كان العنصر مش على القطر الرئيسي لازم يكون يساوي الصفر والا برجع فولص
            {
                return false;
            }
        }
    }

    return true;
}

int main()
{
    int Matrix[3][3] = {{9, 0, 0}, {0, 9, 0}, {0, 0, 9}};

    cout << "\nMatrix:\n";
    PrintMatrix(Matrix, 3, 3);

    if (IsScalarMatrix(Matrix, 3, 3))
    {
        cout << "Yes:matrix is scalar";
    }
    else
        cout << "No,matrix is NOT scalar";
}