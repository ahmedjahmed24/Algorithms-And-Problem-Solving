#include <iostream>
using namespace std;

enum enOperationType
{
    Add = '+',
    Subtract = '-',
    Multiply = '*',
    Divide = '/'
};

float ReadNumbers(string Message)
{
    float Number = 0;

    cout << Message << endl;
    cin >> Number;

    return Number;
}

enOperationType ReadOperationType()
{
    char OT = '+';

    cout << "Enter Operation Type (+,-,*,/) :\n";
    cin >> OT;

    return (enOperationType)OT;
}

float Calculate(float Number1, float Number2, enOperationType OperationType)
{
    switch (OperationType)
    {
    case enOperationType::Add:
        return Number1 + Number2;
        break;

    case enOperationType::Subtract:
        return Number1 - Number2;
        break;

    case enOperationType::Multiply:
        return Number1 * Number2;
        break;

    case enOperationType::Divide:
        return Number1 / Number2;
        break;
    default:
        return Number1 + Number2;
        break;
    }
}

int main()
{
    float Number1, Number2;

    Number1 = ReadNumbers("Enter The First Number :");
    Number2 = ReadNumbers("Enter The Second Number :");

    enOperationType OperationType=ReadOperationType();

    cout << "Result = " << Calculate(Number1, Number2, OperationType);
}