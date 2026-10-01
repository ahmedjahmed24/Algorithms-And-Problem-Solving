#include<iostream>
using namespace std;

float ReadPositiveNumber(string Message)
{
    float Number=0;

    do
    {
        cout<<Message<<endl;
        cin>>Number;

    } while (Number<=0);
    
    return Number;
}

float TotalMonth(float LoanAmount,float MonthlyPayment)
{
    return (float)LoanAmount/MonthlyPayment;
}

int main()
{
    float LoanAmount=ReadPositiveNumber("Enter Loan Amount :");
    float MonthlyPayment=ReadPositiveNumber("Enter Monthly Payment :");

    cout<<"Total Month : "<<TotalMonth(LoanAmount,MonthlyPayment);
}