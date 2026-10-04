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

int MyFloor(float Number) // -10.2
{

    if (Number > 0) // -10.2<0
    {
        return int(Number); // 10
    }
    else//
        return int(Number)-1; // -10-1=-11
}

int main()
{
    float Number = ReadNumber();

    cout << "My Floor is : " << MyFloor(Number) << endl;
    cout << "C++ Floor is : " << floor(Number);
}