#include <iostream>
#include <iomanip>
using namespace std;

int ReadPositiveNumber(string Message)
{
    int Number = 0;

    do
    {
        cout << Message << endl;
        cin >> Number;

    } while (Number <= 0);

    return Number;
}

int RandomNumber(int From, int To)
{
    int randnum = rand() % (To - From + 1) + From;
    return randnum;
}

void FillMatrixWithRandomNumbers(int Matrix[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            Matrix[i][j] = RandomNumber(1, 10);
        }
    }
}

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

int CountNumberInMatrix(int Matrix[3][3], short NumberToCount, short Rows, short Cols)
{
    short NumberCounter = 0;

    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            if (Matrix[i][j] == NumberToCount)
            {
                NumberCounter++;
            }
        }
    }

    return NumberCounter; // 2
}

void PrintNumberFrequency(int Matrix[3][3], int NumberToCount, short Rows, short Cols)
{
    cout << "Number " << NumberToCount << " count in matrix is " << CountNumberInMatrix(Matrix, NumberToCount, 3, 3) << " Time(s)";
}

int main()
{
    int Matrix[3][3];
    FillMatrixWithRandomNumbers(Matrix, 3, 3);

    cout << "\nMatrix :\n";
    PrintMatrix(Matrix, 3, 3);

    short NumberToCount = ReadPositiveNumber("Enter a number to count it :"); // 9

    PrintNumberFrequency(Matrix, NumberToCount, 3, 3);
}