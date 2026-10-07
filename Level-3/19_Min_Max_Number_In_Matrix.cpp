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

int MinimumNumberInMatrix(int Matrix[3][3], short Rows, short Cols)
{
    short Min = Matrix[0][0];

    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            // Min=Matrix[0][0]; خطأ تحطا هون لانو انا بدي لما يطلع معي المين احافظ عليه واقارنو مع البعدو بس اذا عملت هيك كل مرة بطلع معي ميين جديد برجع برجعو المين هو اول عنصر فمابحافظ على المين الجديد اللي عم يطلع معي كل مرة

            if (Matrix[i][j] < Min)
            {
                Min = Matrix[i][j];
            }
        }
    }

    return Min;
}

int MaximumNumberInMatrix(int Matrix[3][3], short Rows, short Cols)
{
    short Max = Matrix[0][0];

    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            // Max=Matrix[0][0]; خطأ تحطا هون لانو انا بدي لما يطلع معي الماكس احافظ عليه واقارنو مع البعدو بس اذا عملت هيك كل مرة بطلع معي ماكس جديد برجع برجعو الماكس هو اول عنصر فمابحافظ على الماكس الجديد اللي عم يطلع معي كل مرة

            if (Matrix[i][j] > Max)
            {
                Max = Matrix[i][j];
            }
        }
    }

    return Max;
}

int main()
{
    int Matrix[3][3] = {{77, 5, 12}, {22, 20, 6}, {14, 3, 9}};

    cout << "\nMatrix :\n";
    PrintMatrix(Matrix, 3, 3);

    cout << "Min number is : " << MinimumNumberInMatrix(Matrix, 3, 3) << endl;
    cout << "Max number is : " << MaximumNumberInMatrix(Matrix, 3, 3) << endl;
}