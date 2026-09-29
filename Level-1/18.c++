#include <iostream>
#include <cmath>
using namespace std;

float ReadRadios()
{
    float R;

    cout << "Please Enter Radios R :\n";
    cin >> R;

    return R;
}

float CalculateCircleArea(float R)
{
    const float PI = 3.141592653589793238;

    float Area = PI * pow(R, 2);

    return Area;
}

void PrintResult(float Area)
{
    cout << "\nCircle Area = " << Area << endl;
}

int main()
{
    float R;

    PrintResult(CalculateCircleArea(ReadRadios()));
}