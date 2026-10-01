#include <iostream>
using namespace std;

void ReadNumbers(float &A, float &B)
{
    cout << "Enter Rectangle Length :\n";
    cin >> A;
    cout << "Enter Rectangle Width :\n";
    cin >> B;
}

float CalculateRectangleArea(float A, float B)
{
    return A * B;
}

void PrintResults(float Area)
{
    cout << "Area Of Rectangle = " << Area;
}

int main()
{
    float A, B;

    ReadNumbers(A, B);
    PrintResults(CalculateRectangleArea(A, B));
}