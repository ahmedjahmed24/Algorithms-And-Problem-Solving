#include <iostream>
using namespace std;

int ReadNumber()
{
    int N;

    cout << "Enter a Number :\n";
    cin >> N;

    return N;
}

int ReadPower()
{
    int M;

    cout << "Enter Power :\n";
    cin >> M;

    return M;
}

int PowerOfM(int Number, int M)
{
    if (M == 0)
    {
        return 1;
    }

    int P = 1;
    for (int i = 1; i <= M; i++)
    {
        P = P * Number;
    }
    return P;
}

int main()
{
    cout << "Result = " << PowerOfM(ReadNumber(), ReadPower());
}