#include <iostream>
using namespace std;

struct stPeggyBankContent
{
    int Pennies, Nickels, Dimes, Quarters, Dollars;
};

stPeggyBankContent ReadPeggyBankContent()
{
    stPeggyBankContent PeggyBankContent;

    cout << "Please Enter a Total Pennies :\n";
    cin >> PeggyBankContent.Pennies;
    cout << "Please Enter a Total Nickels :\n";
    cin >> PeggyBankContent.Nickels;
    cout << "Please Enter a Total Dimes :\n";
    cin >> PeggyBankContent.Dimes;
    cout << "Please Enter a Total Quarter :\n";
    cin >> PeggyBankContent.Quarters;
    cout << "Please Enter a Total Dollars :\n";
    cin >> PeggyBankContent.Dollars;

    return PeggyBankContent;
}

int CalculateTotalPennies(stPeggyBankContent PeggyBankContent)
{
    int TotalPennies = 0;

    TotalPennies = PeggyBankContent.Pennies * 1 + PeggyBankContent.Nickels * 5 + PeggyBankContent.Dimes * 10 + PeggyBankContent.Quarters * 25 + PeggyBankContent.Dollars * 100;

    return TotalPennies;
}

int main()
{
    int TotalPennies = CalculateTotalPennies(ReadPeggyBankContent());

    cout << "Total Pennies = " << TotalPennies << endl;
    cout << "Total Dollars = " << (float)TotalPennies / 100;
}