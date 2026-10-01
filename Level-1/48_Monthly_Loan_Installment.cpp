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

float MonthlyInstallment(float LoanAmount, float HowManyMonth)
{
    return (float)LoanAmount / HowManyMonth;
}

int main()
{
    float LoanAmount = ReadPositiveNumber("Enter Loan Amount :");  // 5000
    float HowManyMonths = ReadPositiveNumber("How Many Months ?"); // 10

    cout << "Monthly Installment : " << MonthlyInstallment(LoanAmount, HowManyMonths);
}