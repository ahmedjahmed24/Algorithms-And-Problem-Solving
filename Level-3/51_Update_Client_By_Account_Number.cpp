#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
const string ClientsFileName = "Clients.txt";

struct stClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    float AccountBalance;
    bool MarkForDelete = false;
    bool MarkForUpdate = false;
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

    if (S1 != "")
    {
        vString.push_back(S1);
    }

    return vString;
}

stClient ConvertLineToRecord(string Line, string Separator = "#//#")
{
    vector<string> vString = SplitString(Line, Separator); // vString={"A150","1234","Ahmed Ahmed","09657621","7000"};
    stClient Client;

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

        MyFile.close();
    }

    return vClient;
}

string ReadClientAccountNumber()
{
    string AccountNumber = "";

    cout << "Please Enter Account Number :\n";
    cin >> AccountNumber;

    return AccountNumber;
}

bool FindClientByAccountNumber(string AccountNumber, vector<stClient> &vClient, stClient &Client)
{
    for (stClient &C : vClient)
    {
        if (AccountNumber == C.AccountNumber)
        {
            Client = C;
            return true;
        }
    }

    return false;
}

void PrintClientCard(stClient Client)
{
    cout << "\n\nThe following is the delete client card :\n\n";

    cout << "\nAccount Number  : " << Client.AccountNumber;
    cout << "\nPin Code        : " << Client.PinCode;
    cout << "\nName            : " << Client.Name;
    cout << "\nPhone           : " << Client.Phone;
    cout << "\nAccount Balance : " << Client.AccountBalance;
}

bool MarkClientForUpdateByAccountNumber(string AccountNumber, vector<stClient> &vClient)
{
    for (stClient &C : vClient)
    {
        if (AccountNumber == C.AccountNumber)
        {
            C.MarkForUpdate = true;
            return true;
        }
    }
    return false;
}

string ConvertRecordToLine(stClient Client, string Separator = "#//#")
{
    string RecordLine;

    RecordLine = RecordLine + Client.AccountNumber + Separator;
    RecordLine = RecordLine + Client.PinCode + Separator;
    RecordLine = RecordLine + Client.Name + Separator;
    RecordLine = RecordLine + Client.Phone + Separator;
    RecordLine = RecordLine + to_string(Client.AccountBalance);

    return RecordLine;
}

stClient UpdateClient()
{
    stClient Client;

    cout << "Enter Pin Code : ";
    getline(cin, Client.PinCode);

    cout << "Enter Name : ";
    getline(cin, Client.Name);

    cout << "Enter Phone : ";
    getline(cin, Client.Phone);

    cout << "Enter Account Balance : ";
    cin >> Client.AccountBalance;

    return Client;
}

vector<stClient> SaveClientToFile(string FileName, vector<stClient> vClient)
{
    fstream MyFile;
    MyFile.open(FileName, ios::out);

    string DataLine;
    if (MyFile.is_open())
    {
        for (stClient &C : vClient)
        {
            if (C.MarkForUpdate == true)
            {
                C = UpdateClient();

                DataLine = ConvertRecordToLine(C);

                MyFile << DataLine << endl;
            }
        }

        MyFile.close();
    }

    return vClient;
}

bool UpdateClientByAccountNumber(string AccountNumber, vector<stClient> &vClient)
{
    stClient Client;
    char Answer = 'n';

    if (FindClientByAccountNumber(AccountNumber, vClient, Client))
    {
        PrintClientCard(Client);

        cout << "\n\nAre you sure you want update this client ? ";
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {
            MarkClientForUpdateByAccountNumber(AccountNumber, vClient);
            SaveClientToFile(ClientsFileName, vClient);
            vClient = LoadDataFromFile(ClientsFileName);

            cout << "\n\nClient Updated Successfully.\n";
            return true;
        }
    }
    else
    {
        cout << "Client with Account Number (" << AccountNumber << ") is NOT Found !.\n";
        return false;
    }
}

int main()
{
    vector<stClient> vClient = LoadDataFromFile(ClientsFileName);

    string AccountNumber = ReadClientAccountNumber();

    UpdateClientByAccountNumber(AccountNumber, vClient);
}