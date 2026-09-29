#include <iostream>
using namespace std;

string ReadPinCode()
{
    string PinCode = 0;

    cout << "Enter PIN Code :" << endl;
    cin >> PinCode;

    return PinCode;
}

bool Login()
{
    string PinCode;

    do
    {
        PinCode = ReadPinCode();

        if (PinCode == "1234")
        {
            return 1;
        }
        else
            return "Wrong PIN\n";
        system("color 4F");

    } while (PinCode != "1234");

    return 0;
}

int main()
{
    if (Login() == true)
    {
        system("color 2F");
        cout << "Your Account Balance is :" << 7500 << "\n";
    }

    return 0;
}