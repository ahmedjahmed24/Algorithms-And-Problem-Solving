#include <iostream>
#include <cmath>
using namespace std;

float ReadCercumference()
{
    float L;

    cout << "Enter Cercumference :\n";
    cin >> L;

    return L;
}

float CircleAreaByCercumference(float L)
{
    const float PI = 3.141592653589793238;

    float Area = (pow(L, 2)) / (4 * PI);

    return Area;
}

void PrintResult(float Area)
{
    cout << "Area = " << Area;
}

int main()
{
    PrintResult(CircleAreaByCercumference(ReadCercumference()));
}