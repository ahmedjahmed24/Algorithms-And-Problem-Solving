#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct stClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    float AccountBalance;
};

vector<string> SplitString(string S1, string delim) // A150#//#1234#//#Mohammed Abu-Hadhoud#//#09855433#//#5270.00000
{
    short Pos = 0;
    string sWord;
    vector<string> vString;

    while ((Pos = S1.find(delim)) != S1.npos)
    {
        sWord = S1.substr(0, Pos); // sWord=A150

        if (sWord != " ")
        {
            vString.push_back(sWord);
        }
        S1.erase(0, Pos + delim.length());
    }

    if (S1 != " ")
    {
        vString.push_back(S1);
    }

    return vString; // vString={"A150","1234","Mohammed Abu-Hadhoud","09855433","5270.00000"};
}

stClient ConvertLinetoRecord(string LineRecord, string delim)
{
    stClient Client;
    vector<string> vString = SplitString(LineRecord, delim); // vString={"A150","1234","Mohammed Abu-Hadhoud","09855433","5270.00000"};

    Client.AccountNumber = vString[0];
    Client.PinCode = vString[1];
    Client.Name = vString[2];
    Client.Phone = vString[3];
    Client.AccountBalance = stof(vString[4]);

    return Client;
}

void PrintClientRecord(stClient Client)
{
    cout << "\n\nThe following is the extracted client record :\n\n";

    cout << "\nAccount Number  : " << Client.AccountNumber;
    cout << "\nPinCode         : " << Client.PinCode;
    cout << "\nName            : " << Client.Name;
    cout << "\nPhone           : " << Client.Phone;
    cout << "\nAccount Balance : " << Client.AccountBalance;
}

int main()
{
    stClient Client;
    string LineRecord = "A150#//#1234#//#Mohammed Abu-Hadhoud#//#09855433#//#5270.00000";

    cout << "\nLine Record is :\n\n";
    cout << LineRecord;

    Client = ConvertLinetoRecord(LineRecord, "#//#");
    PrintClientRecord(Client);
}