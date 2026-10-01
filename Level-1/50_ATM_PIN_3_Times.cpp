#include <iostream>
using namespace std;

string ReadPinCode()
{
    string PinCode;

    cout << "Enter PIN Code :\n";
    cin >> PinCode;

    return PinCode;
}

bool Login()
{
    string PinCode;
    int Counter = 3;

    do
    {
        
        PinCode = ReadPinCode();
        Counter--;

        if (PinCode == "1234")
        {
            return true;
        }
        else
            system("color 4F");
        cout << "Wrong PIN ! You have " << Counter << " More tries .\n";

    } while (Counter >= 1 && PinCode != "1234");
    return 0;
}

int main()
{
    if (Login()==true)
    {
        system("color 2F");
        cout << "Your Account Balance is : " << 7500 << "\n";
    }
    else
    
        cout << "Your Account is Locked , Please Call Bank for Help .";
    
    
}