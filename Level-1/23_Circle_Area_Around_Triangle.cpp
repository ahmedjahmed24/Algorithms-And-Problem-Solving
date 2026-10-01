#include <iostream>
#include <cmath>
using namespace std;

void ReadTriangleData(float &A, float &B, float &C)
{
    cout << "Enter Triangle Side A :\n";
    cin >> A;
    cout << "Enter Triangle Side C :\n";
    cin >> C;
    cout << "Enter Triangle Base B :\n";
    cin >> B;
}

float CircleAreaByATriangle(float A, float B, float C)
{
    const float PI = 3.141592653589793238;
    float P, T, Area;

    P = (A + B + C) / (2);

    T = (A * B * C) / (4 * sqrt(P * (P - A) * (P - B) * (P - C)));

    Area = PI * pow(T, 2);

    return Area;
}

void PrintResult(float Area)
{
    cout << "Circle Area = " << Area;
}

int main()
{
    float A, B, C;

    ReadTriangleData(A, B, C);
    PrintResult(CircleAreaByATriangle(A, B, C));
}