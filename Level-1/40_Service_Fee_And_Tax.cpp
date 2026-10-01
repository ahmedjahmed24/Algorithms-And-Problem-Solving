#include <iostream>
using namespace std;

float ReadPositiveNumber(string Message)
{
    float Number = 0;

    do
    {
        cout << Message << endl;
        cin >> Number;
    } while (Number <= 0);

    return Number;
}

float TotalBillAfterSalesandTax(float TotalBill)
{
    TotalBill = TotalBill * 1.1;
    TotalBill = TotalBill * 1.16;

    return TotalBill;
}

int main()
{
    float TotalBill = ReadPositiveNumber("Enter Total Bill :");
    cout << "Total Bill = " << TotalBill << endl;

    cout << "Total Bill After Services Fee and Sales Tax = " << TotalBillAfterSalesandTax(TotalBill);
}