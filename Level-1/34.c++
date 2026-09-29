#include <iostream>
using namespace std;

int ReadTotalSales()
{
    int TotalSales;

    cout << "Enter Total Sales :\n";
    cin >> TotalSales;

    return TotalSales;
}

float GetCommisionPercentage(int TotalSales)
{
    if (TotalSales >= 1000000)
    {
        return 0.01;
    }
    else if (TotalSales >= 500000)
    {
        return 0.02;
    }
    else if (TotalSales >= 100000)
    {
        return 0.03;
    }
    else if (TotalSales >= 50000)
    {
        return 0.05;
    }
    else
        return 0.00;
}

float CalculateTotalCommision(int TotalSales)
{
    return GetCommisionPercentage(TotalSales) * TotalSales;
}

int main()
{
    float TotalSales = ReadTotalSales();

    cout << "Commision Percentage = " << GetCommisionPercentage(TotalSales) << endl;
    cout << "Total Commision = " << CalculateTotalCommision(TotalSales) << endl;
}