#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct stClient
{
    string AccountNumber;
    string Pincode;
    string Name;
    string Phone;
    float AccountBalance;
};

stClient ReadNewClient()
{
    stClient Client;

    cout << "Enter Account Number ? ";
    getline(cin, Client.AccountNumber);
    cout << "Enter PinCode ? ";
    getline(cin, Client.Pincode);
    cout << "Enter Name ? ";
    getline(cin, Client.Name);
    cout << "Enter Phone ? ";
    getline(cin, Client.Phone);
    cout << "Enter Account Balance ? ";
    cin >> Client.AccountBalance;

    return Client;
}

string ConvertRecordToLine(stClient Client, string Separator = "#//#")
{
    string LineRecord;

    LineRecord = LineRecord + Client.AccountNumber + Separator;
    LineRecord = LineRecord + Client.Pincode + Separator;
    LineRecord = LineRecord + Client.Name + Separator;
    LineRecord = LineRecord + Client.Phone + Separator;
    LineRecord = LineRecord + to_string(Client.AccountBalance);

    return LineRecord;
}

void AddLineRecordToFile(string LineRecord)
{
    fstream MyFile;

    MyFile.open("MyFile.txt", ios::app | ios::out);

    if (MyFile.is_open())
    {
        MyFile << LineRecord << endl;

        MyFile.close();
    }
}

void Start()
{
    char ReadAgain;
    stClient Client;
    string LineRecord;

    do
    {
        system("cls");
        cout << "Adding New Client :\n\n";
        Client = ReadNewClient();
        cin.ignore();
        LineRecord = ConvertRecordToLine(Client);
        AddLineRecordToFile(LineRecord);

        cout << "\n\nClient Added Successfully, do you want to add more clients ?";
        cin >> ReadAgain;

        cin.ignore();

    } while (ReadAgain == 'y' || ReadAgain == 'Y');
}

int main()
{
    Start();
}