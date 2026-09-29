#include <iostream>
using namespace std;

int ReadNumber()
{
    int N;

    cout << "Enter a Number :";
    cin >> N;

    return N;
}

void PowerOf2_3_4(int Number)
{
    int a, b, c;

    a = Number * Number;
    b = Number * Number * Number;
    c = Number * Number * Number * Number;

    cout << a << " " << b << " " << c;
}

int main()
{
    PowerOf2_3_4(ReadNumber());
}