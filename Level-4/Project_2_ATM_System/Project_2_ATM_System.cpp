#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

struct stClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    float AccountBalance;
    bool MarkForDelete = false;
};

const string ClientsFileName = "Clients.txt";

stClient CurrentClient;

enum enATMMainMenuOptions
{
    eQuickWthdraw = 1,
    eNormalWithdraw = 2,
    eDeposit = 3,
    eCheckBalance = 4,
    eExit = 5
};

void ShowMainMenu();
void ShowQuickWithdrawScreen();
void ShowNormalWithdrawScreen();
void ShowCheckBalanceScreen();
void ShowDepositScreen();

vector<string> SplitString(string S1, string delim) // A150#//#Ahmed#//#1234
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

    return vString; // vString={"A150","Ahmed","1234"};
}

stClient ConvertLinetoRecord(string Line, string Separator = "#//#") // A150#//#Ahmed#//#1234
{
    vector<string> vString = SplitString(Line, Separator); // vString={"A150","0000","200"};

    stClient Client;

    Client.AccountNumber = vString[0];
    Client.PinCode = vString[1];
    Client.Name = vString[2];
    Client.Phone = vString[3];
    Client.AccountBalance = stof(vString[4]);

    return Client;
}

vector<stClient> LoadClientDataFromFile(string FileName)
{
    vector<stClient> vClients;

    fstream MyFile;

    MyFile.open(FileName, ios::in);

    if (MyFile.is_open())
    {
        string Line;
        stClient Client;

        while (getline(MyFile, Line))
        {
            Client = ConvertLinetoRecord(Line);

            vClients.push_back(Client);
        }

        MyFile.close();
    }

    return vClients;
}

string ConvertRecordToLine(stClient Client, string Seperator = "#//#")
{
    string stClientRecord = "";

    stClientRecord += Client.AccountNumber + Seperator;
    stClientRecord += Client.PinCode + Seperator;
    stClientRecord += Client.Name + Seperator;
    stClientRecord += Client.Phone + Seperator;
    stClientRecord += to_string(Client.AccountBalance);

    return stClientRecord;
}

vector<stClient> SaveClientsDatatoFile(string FileName, vector<stClient> vClients)
{
    fstream MyFile;

    MyFile.open(FileName, ios::out);

    string DataLine;
    if (MyFile.is_open())
    {
        for (stClient &C : vClients)
        {
            if (C.MarkForDelete == false)
            {
                DataLine = ConvertRecordToLine(C);

                MyFile << DataLine << endl;
            }
        }

        MyFile.close();
    }

    return vClients;
}

bool DepositBalanceToClientByAccountNumber(string AccountNumber, double Amount)
{
    vector<stClient> vClients = LoadClientDataFromFile(ClientsFileName);

    char Answer = 'n';

    cout << "\n\nAre you sure you want perfrom this transaction? y/n ? ";
    cin >> Answer;

    if (Answer == 'y' || Answer == 'Y')
    {
        for (stClient &C : vClients)
        {
            if (C.AccountNumber == AccountNumber)
            {
                C.AccountBalance += Amount;

                SaveClientsDatatoFile(ClientsFileName, vClients);

                cout << "\n\nDone Successfully. New balance is: " << C.AccountBalance;
                return true;
            }
        }
        return false;
    }
}

bool FindClientByAccountNumberAndPinCode(string AccountNumber, string PinCode, stClient &CurrentClient)
{
    vector<stClient> vClients = LoadClientDataFromFile(ClientsFileName);

    for (stClient &C : vClients)
    {
        if (C.AccountNumber == AccountNumber && C.PinCode == PinCode)
        {
            CurrentClient = C;
            return true;
        }
    }

    return false;
}

bool LoadClientInfo(string AccountNumber, string PinCode)
{
    if (FindClientByAccountNumberAndPinCode(AccountNumber, PinCode, CurrentClient))
    {
        return true;
    }
    else
        return false;
}

short ReadATMMainMenueOption()
{
    short Choice = 0;

    cout << "Choose what do you want to do? [1 to 5]? ";
    cin >> Choice;

    return Choice;
}

short ReadQuickWithdrawOption()
{
    short Choice = 0;

    cout << "\nChoose what do you want to do? [1 to 9]? ";
    cin >> Choice;

    while (Choice < 1 || Choice > 9)
    {
        cout << "Choose what do you want to do? [1 to 9]? ";
        cin >> Choice;
    }

    return Choice;
}

void GoBacktoMainMenu()
{
    cout << "\n\nPress Any Key to go back to Main Menu...";
    system("pause>0");
    ShowMainMenu();
}

short GetAmountFromQuickOption(short QuickOption)
{
    switch (QuickOption)
    {
    case 1:
        return 20;

    case 2:
        return 50;

    case 3:
        return 100;

    case 4:
        return 200;

    case 5:
        return 400;

    case 6:
        return 600;

    case 7:
        return 800;

    case 8:
        return 1000;

    default:
        return 0;
    }
}

void PerformQuickWithdrawOption(short QuickWithdrawOption)
{
    short Amount = GetAmountFromQuickOption(QuickWithdrawOption);

    if (Amount > CurrentClient.AccountBalance)
    {
        cout << "\nThe Amount Exceeds Your Balance, Make Another Choice...";
        system("pause>0");
        ShowQuickWithdrawScreen();
    }

    vector<stClient> vClients = LoadClientDataFromFile(ClientsFileName);
    DepositBalanceToClientByAccountNumber(CurrentClient.AccountNumber, Amount * -1);
    CurrentClient.AccountBalance -= Amount;
}

int ReadAmountMultipleOf5()
{
    int Amount = 0;

    cout << "\nEnter an amount multiple of 5's : ";
    cin >> Amount;

    while (Amount % 5 != 0)
    {
        cout << "\nEnter an amount multiple of 5's : ";
        cin >> Amount;
    }

    return Amount;
}

void PerformNormalWithdrawOption()
{
    int Amount = ReadAmountMultipleOf5();

    if (Amount > CurrentClient.AccountBalance)
    {
        cout << "\nThe Amount Exceeds Your Balance, Make Another Choice...";
        system("pause>0");
        ShowNormalWithdrawScreen();
    }

    vector<stClient> vClients = LoadClientDataFromFile(ClientsFileName);
    DepositBalanceToClientByAccountNumber(CurrentClient.AccountNumber, Amount * -1);
    CurrentClient.AccountBalance -= Amount;
}

void Login()
{
    bool LoginFailed = false;
    string AccountNumber, PinCode;

    do
    {
        system("cls");

        cout << "\n---------------------------------\n";
        cout << "\tLogin Screen";
        cout << "\n---------------------------------\n";

        if (LoginFailed)
        {
            cout << "\nInvalid Account Number / PinCode !";
        }

        cout << "\nEnter Account Number : ";
        cin >> AccountNumber;

        cout << "\nEnter Pin Code : ";
        cin >> PinCode;

        LoginFailed = !LoadClientInfo(AccountNumber, PinCode);

    } while (LoginFailed);

    ShowMainMenu();
}

int ReadPositiveAmount()
{
    int Amount = 0;

    cout << "\nEnter a positive amount to deposit : ";
    cin >> Amount;

    while (Amount <= 0)
    {
        cout << "\nEnter a positive amount to deposit : ";
        cin >> Amount;
    }

    return Amount;
}

void PerformDepositOption()
{
    int DepositAmount = ReadPositiveAmount();

    vector<stClient> vClients = LoadClientDataFromFile(ClientsFileName);
    DepositBalanceToClientByAccountNumber(CurrentClient.AccountNumber, DepositAmount);
    CurrentClient.AccountBalance += DepositAmount;
}

void Perform_ATM_MainMenuOption(enATMMainMenuOptions MainMenuOption)
{
    switch (MainMenuOption)
    {
    case enATMMainMenuOptions::eQuickWthdraw:
        ShowQuickWithdrawScreen();
        GoBacktoMainMenu();

        break;

    case enATMMainMenuOptions::eNormalWithdraw:
        ShowNormalWithdrawScreen();
        GoBacktoMainMenu();
        break;

    case enATMMainMenuOptions::eCheckBalance:
        ShowCheckBalanceScreen();
        GoBacktoMainMenu();
        break;

    case enATMMainMenuOptions::eDeposit:
        ShowDepositScreen();
        GoBacktoMainMenu();
        break;

    case enATMMainMenuOptions::eExit:
        Login();
        break;
    }
}

int main()
{
    Login();
}

void ShowMainMenu()
{
    system("cls");

    cout << "===========================================\n";
    cout << "\t\tATM Main Menue Screen\n";
    cout << "===========================================\n";
    cout << "\t[1] Quick Withdraw.\n";
    cout << "\t[2] Normal Withdraw.\n";
    cout << "\t[3] Deposit.\n";
    cout << "\t[4] Check Balance.\n";
    cout << "\t[5] Logout.\n";
    cout << "===========================================\n";

    Perform_ATM_MainMenuOption((enATMMainMenuOptions)ReadATMMainMenueOption());
}

void ShowQuickWithdrawScreen()
{
    system("cls");

    cout << "===========================================\n";
    cout << "\tQuick Withdraw Screen\n";
    cout << "===========================================\n";
    cout << "\t[1] 20\t\t[2] 50 \n";
    cout << "\t[3] 100\t\t[4] 200 \n";
    cout << "\t[5] 400\t\t[6] 600 \n";
    cout << "\t[7] 800\t\t[8] 1000 \n";
    cout << "\t[9] Exit\n";
    cout << "===========================================\n";
    cout << "\nYour Balance is : " << CurrentClient.AccountBalance;

    PerformQuickWithdrawOption(ReadQuickWithdrawOption());
}

void ShowNormalWithdrawScreen()
{
    system("cls");

    cout << "===========================================\n";
    cout << "\tNormal Withdraw Screen\n";
    cout << "===========================================\n";

    PerformNormalWithdrawOption();
}

void ShowCheckBalanceScreen()
{
    system("cls");

    cout << "===========================================\n";
    cout << "\tCheck Balance Screen\n";
    cout << "===========================================\n";

    cout << "\nYour Balance is : " << CurrentClient.AccountBalance;
}

void ShowDepositScreen()
{
    system("cls");

    cout << "===========================================\n";
    cout << "\tDeposit Screen\n";
    cout << "===========================================\n";

    PerformDepositOption();
}