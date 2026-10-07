#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void PrintMatrix(int Matrix[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            printf(" %0*d  ", 2, Matrix[i][j]);
            // cout<<setw(3)<<Marix[i][j]<<"   ";
        }
        cout << "\n";
    }
}

bool IsIdentityMatrix(int Matrix[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            if (i == j && Matrix[i][j] != 1) // يجب ان يكون العنصر على القطر الرئيسي ويساوي الواحد والا برجع فولص
            {
                return false;
            }
            else if (i != j && Matrix[i][j] != 0) // يجب ان يكون العنصر مش على القطر الرئيسي ويساوي الصفر والا برجع فولص
            {
                return false;
            }
        }
    }

    return true;
}

int main()
{
    //int Matrix[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    int Matrix[3][3] = {{1, 0, 3}, {0, 1, 0}, {0, 0, 1}};

    cout << "\nMatrix :\n";
    PrintMatrix(Matrix, 3, 3);

    if (IsIdentityMatrix(Matrix, 3, 3))
    {
        cout << "yes:matrix is identity";
    }
    else
        cout << "No:matrix is NOT identity";
}