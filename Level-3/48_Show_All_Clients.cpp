#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std;
const string ClientsFileName = "Clients.txt";

struct stClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    float AccountBalance;
};

vector<string> SplitString(string S1, string delim)
{
    short Pos = 0;
    string sWord;
    vector<string> vString;

    while ((Pos = S1.find(delim)) != S1.npos)
    {
        sWord = S1.substr(0, Pos);

        if (sWord != "")
        {
            vString.push_back(sWord);
        }

        S1.erase(0, Pos + delim.length());
    }

    if (S1 != " ")
    {
        vString.push_back(S1);
    }

    return vString;
}

stClient ConvertLineToRecord(string Line, string Separator = "#//#")
{
    stClient Client;

    vector<string> vString = SplitString(Line, Separator);

    Client.AccountNumber = vString[0];
    Client.PinCode = vString[1];
    Client.Name = vString[2];
    Client.Phone = vString[3];
    Client.AccountBalance = stof(vString[4]);

    return Client;
}

vector<stClient> LoadDataFromFile(string FileName)
{
    vector<stClient> vClient;

    fstream MyFile;
    MyFile.open(FileName, ios::in);

    if (MyFile.is_open())
    {
        string Line;
        stClient Client;

        while (getline(MyFile, Line))
        {
            Client = ConvertLineToRecord(Line);

            vClient.push_back(Client);
        }
    }

    return vClient;
}

void PrintClientRecord(stClient Client)
{
    cout << "| " << left << setw(15) << Client.AccountNumber;
    cout << "| " << left << setw(10) << Client.PinCode;
    cout << "| " << left << setw(30) << Client.Name;
    cout << "| " << left << setw(12) << Client.Phone;
    cout << "| " << left << setw(12) << Client.AccountBalance;
}

void PrintAllClientsData(vector<stClient> vClient)
{
    cout << "\n\t\t\tClient List(" << vClient.size() << ") Client(s).";
    cout << "\n-------------------------------------------------------------------------------------------------------------------------------\n\n";

    cout << "| " << left << setw(15) << "Account Number";
    cout << "| " << left << setw(10) << "Pin Code ";
    cout << "| " << left << setw(30) << "Name ";
    cout << "| " << left << setw(12) << "Phone ";
    cout << "| " << left << setw(12) << "Balance ";

    cout << "\n-------------------------------------------------------------------------------------------------------------------------------\n\n";

    for (stClient Client : vClient)
    {
        PrintClientRecord(Client);
        cout << endl;
    }
}

int main()
{
    vector<stClient> vClient = LoadDataFromFile(ClientsFileName);

    PrintAllClientsData(vClient);
}