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

bool IsNumberInMatrix(int Matrix[3][3], short Number, short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            if (Matrix[i][j] == Number) // 1==77 2==77  5==77  4==77  77==77
            {
                return true; // اذا لاقيت الرقم خلص رجع ترو وطلاع من الفنكشن كلو لاتكمل وتبطئ البرنامج
            }
        }
    }

    return false;
}

/*short CountNumberInMatrix(int Matrix[3][3], short Number, short Rows, short Cols)
{
    short NumberCount = 0;

    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            if (Matrix[i][j] == Number)
            {
                NumberCount++;
            }
        }
    }

    return NumberCount;
}*/

int main()
{
    int Matrix[3][3] = {{1, 2, 5}, {4, 77, 3}, {2, 4, 5}};

    cout << "\nMatrix :\n";
    PrintMatrix(Matrix, 3, 3);

    int Number = 0;
    cout << "\nEnter a number to search for ?\n";
    cin >> Number;

    if (IsNumberInMatrix(Matrix, Number, 3, 3))
    {
        cout << "Yes : it is there";
    }
    else
        cout << "No : it is not there";

    /*if (CountNumberInMatrix(Matrix, Number, 3, 3) > 0)
    {
        cout << "Yes : it is there";
    }
    else
        cout << "No : it is not there";*/
}