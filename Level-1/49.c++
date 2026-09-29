#include <iostream>
using namespace std;

string ReadPinCode()
{
    string PinCode="";//كنت حاطط قيمة ابتدائية رقم صفر وهو سترينغ لاني دب

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
            return true;
        }
        else
            cout << "Wrong PIN\n";
        system("color 4F");

    } while (PinCode != "1234");

    return false;
}

int main()
{
    if (Login())
    {
        system("color 2F");
        cout << "Your Account Balance is :" << 7500 << "\n";
    }

    return 0;
}