#include <iostream>
using namespace std;

void ReadNumbers(float &A, float &H)
{
    cout << "Enter Triangle Base A :\n";
    cin >> A;
    cout << "Enter Triangle Hide H :\n";
    cin >> H;
}

float CalculateTriangleArea(float A, float H)
{
    float Area = (A / 2) * H;

    return Area;
}

void PrintResult(float Area)
{
    cout << "\nTriangle Area = " << Area;
}

int main()
{
    float A, H;

    ReadNumbers(A, H);

    PrintResult(CalculateTriangleArea(A, H));
}