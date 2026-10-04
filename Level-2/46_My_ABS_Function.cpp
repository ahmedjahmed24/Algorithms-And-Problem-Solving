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

float Myabs(float Number)
{
    if (Number > 0)
    {
        return Number;
    }
    else
        return Number * -1;
}

int main()
{
    float Number = ReadNumber();

    cout << "My abs Result : " << Myabs(Number) << endl;
    cout << "C++ abs Result : " << abs(Number) << endl;
}