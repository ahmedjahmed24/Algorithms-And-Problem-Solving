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

bool IsPalindromeMatrix(int Matrix[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols / 2; j++)
        {
            if (Matrix[i][j] != Matrix[i][Cols - j - 1])
            {
                return false;
            }
        }
    }

    return true;
}

int main()
{
    int Matrix[3][3] = {{1, 2, 1}, {5, 5, 5}, {7, 3, 7}};

    cout << "\nMatrix :\n";
    PrintMatrix(Matrix, 3, 3);

    if (IsPalindromeMatrix(Matrix, 3, 3))
    {
        cout << "Yes : Matrix is palindrome";
    }
    else
        cout << "No : Matrix is NOT palindrome";
}