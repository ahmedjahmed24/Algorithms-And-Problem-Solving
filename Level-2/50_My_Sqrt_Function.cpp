#include <iostream>
#include <cmath>
using namespace std;

float ReadNumber()
{
    float Number = 0;

    cout << "Enter a number :\n";
    cin >> Number;

    return Number;
}

float MySqrt(float Number)
{
    return pow(Number, 0.5);
}

int main()
{
    float Number = ReadNumber();

    cout << "My Sqrt is : " << MySqrt(Number) << endl;
    cout << "C++ Sqrt is : " << sqrt(Number);
}