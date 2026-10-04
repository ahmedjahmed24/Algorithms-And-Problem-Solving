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

int MyRound(float Number) // 10.2
{
    int IntPart = int(Number);                    // 10
    float FractionPart = GetFractionPart(Number); // 0.2

    if (abs(FractionPart) >= .5)
    {
        if (Number > 0)
        {
            return ++IntPart;// ++10=10+1=11
        }
        else
            return --IntPart;//--10=-1-10=-11
    }
    else
        return IntPart;//10
}

int main()
{
    float Number = 0;

    Number = ReadNumber();

    cout << "My Round is : " << MyRound(Number) << endl;
    cout << "C++ Round is : " << round(Number);
}