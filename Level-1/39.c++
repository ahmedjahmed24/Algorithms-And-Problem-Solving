#include <iostream>
using namespace std;

int ReadPositiveNumber(string Message)
{
    float Number = 0;

    do
    {
        cout << Message << endl;
        cin >> Number;
    } while (Number <= 0);

    return Number;
}

float CalculateRemainder(float TotalBill, float TotalCashPaid)
{
    return TotalCashPaid - TotalBill;
}

int main()
{
    float TotalBill = ReadPositiveNumber("Enter Total Bill :");
    float TotalCashPaid = ReadPositiveNumber("Enter Total Cash Paid");

    cout << "Total Bill = " << TotalBill << endl;
    cout << "Total Cash Paid = " << TotalCashPaid << endl;

    cout<<"************************\n";
    cout << "Remainder = " << CalculateRemainder(TotalBill, TotalCashPaid) << endl;
}