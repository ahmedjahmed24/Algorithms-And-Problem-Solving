#include <iostream>
#include <cmath>
using namespace std;

void ReadTriangleData(float &A, float &B)
{
    cout << "Enter Triangle Side A :\n";
    cin >> A;
    cout << "Enter Triangle Base B :\n";
    cin >> B;
}

float CircleAreaByITriangle(float A, float B)
{
    const float PI = 3.141592653589793238;

    float Area = PI * pow(B, 2) / 4 * (2 * A - B) / (2 * A + B);

    return Area;
}

void PrintResult(float Area)
{
    cout << "Area = " << Area;
}

int main()
{
    float A, B;
    ReadTriangleData(A, B);
    PrintResult(CircleAreaByITriangle(A,B));
}