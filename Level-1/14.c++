#include <iostream>
using namespace std;

void ReadNumbers(int &Num1, int &Num2)
{
    cout << "Please Enter Number 1 :\n";
    cin >> Num1;
    cout << "Please Enter Number 2 :\n";
    cin >> Num2;
}

void Swap(int &Num1, int &Num2)
{
    int Temp;

    Temp = Num1;
    Num1 = Num2;
    Num2 = Temp;
}

void PrintNumbers(int Num1, int Num2)
{
    cout << "Number 1 : " << Num1 << endl;
    cout << "Number 2 : " << Num2 << endl;
    cout<<"\n\n";
}

int main()
{
    int Number1, Number2;

    ReadNumbers(Number1, Number2);
    PrintNumbers(Number1, Number2);
    Swap(Number1, Number2);
    PrintNumbers(Number1, Number2);
}