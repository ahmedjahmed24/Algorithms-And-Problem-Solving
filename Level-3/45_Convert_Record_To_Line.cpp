#include <iostream>
#include <string>
using namespace std;

struct stClientData
{
    string AccountNumber;
    int PinCode = 0;
    string Name = "";
    string PhoneNumber = "";
    float AccountBalance = 0;
};

stClientData ReadClientData()
{
    stClientData ClientData;

    cout << "Please Enter Client Data :\n\n";

    cout << "Enter Account Number : ";
    cin >> ClientData.AccountNumber;

    cout << "Enter PinCode : ";
    cin >> ClientData.PinCode;

    cin.ignore(); // تجاهل كبسة الانتر ك دخل وماتحطا دخل للنيم يلي بالكيتلاين البعدا-

    cout << "Enter Name : ";
    getline(cin, ClientData.Name);

    cout << "Enter Phone : ";
    cin >> ClientData.PhoneNumber;

    cout << "Enter Account Balance : ";
    cin >> ClientData.AccountBalance;

    return ClientData;
}

void PrintClientDataInOneLine(stClientData ClientData, string delim)
{
    cout << "Client Record for saving is : ";
    cout << ClientData.AccountNumber << delim << ClientData.PinCode << delim << ClientData.Name << delim << ClientData.PhoneNumber << delim << ClientData.AccountBalance;
}

int main()
{
    // stClientData ClientData;

    cout << "\n\n";
    PrintClientDataInOneLine(ReadClientData(), " #//# ");
}