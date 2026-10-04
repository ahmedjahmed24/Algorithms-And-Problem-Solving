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

float GetFractionPart(float Number) // 0.2=10.2-10
{
    return Number - int(Number);
}

int MyCeil(float Number) // -10.3 -> -10
{
    if (abs(GetFractionPart(Number)) > 0)
    {
        if (Number > 0) // -10.3<0
        {
            return int(Number) + 1; // 11 = 10+1
        }
        else
            return int(Number); // -10 =
    }
    else
        return Number;
}

int main()
{
    float Number = ReadNumber();

    cout << "My Ceil is : " << MyCeil(Number) << endl;
    cout << "C++ Ceil is : " << ceil(Number);
}