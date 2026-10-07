#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <fstream>
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

enum enMainMenuOptions
{
    eListClients = 1,
    eAddNewClient = 2,
    eDeleteClient = 3,
    eUpdateClient = 4,
    eFindClient = 5,
    eTransactions = 6,
    eExit = 7
};

enum enTransactionsOptions
{
    eDeposit = 1,
    eWithdraw = 2,
    eTotalBalances = 3,
    eMainMenu = 4
};

void ShowMainMenu();
void ShowTransactionsScreen();

short ReadMainMenuOption()
{
    short Choice;

    cout << "Choose what do you want to do? [1 to 7]? ";
    cin >> Choice;

    return Choice;
}

vector<string> SplitStirng(string S1, string delim)
{
    short Pos = 0;
    string sWord;
    vector<string> vString;

    while ((Pos = S1.find(delim)) != S1.npos)
    {
        sWord = S1.substr(0, Pos);

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

    return vString;
}

stClient ConvertLineToRecord(string Line, string Separator = "#//#")
{
    stClient Client;
    vector<string> vString = SplitStirng(Line, Separator); // vStirng={"A150","1234","Ahmed","09327742","8000"};

    Client.AccountNumber = vString[0];
    Client.PinCode = vString[1];
    Client.Name = vString[2];
    Client.Phone = vString[3];
    Client.AccountBalance = stof(vString[4]);

    return Client;
}

vector<stClient> LoadClientsDataFromFile(string FileName)
{
    vector<stClient> vClients;

    fstream MyFile;

    MyFile.open(FileName, ios::in);

    if (MyFile.is_open())
    {
        stClient Client;
        string Line;
        while (getline(MyFile, Line))
        {
            Client = ConvertLineToRecord(Line);

            vClients.push_back(Client);
        }

        MyFile.close();
    }

    return vClients;
}

void PrintClientData(stClient &Client)
{
    cout << "| " << left << setw(15) << Client.AccountNumber;
    cout << "| " << left << setw(10) << Client.PinCode;
    cout << "| " << left << setw(30) << Client.Name;
    cout << "| " << left << setw(12) << Client.Phone;
    cout << "| " << left << setw(12) << Client.AccountBalance;
}

void ShowListClientsScreen()
{
    vector<stClient> vClients = LoadClientsDataFromFile(ClientsFileName);

    cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
    cout << "\n-------------------------------------------------------------------------------------------------------\n";
    cout << "| " << left << setw(15) << "Account Number";
    cout << "| " << left << setw(10) << "Pin Code";
    cout << "| " << left << setw(30) << "Name";
    cout << "| " << left << setw(12) << "Phone";
    cout << "| " << left << setw(12) << "Balance";

    cout << "\n-------------------------------------------------------------------------------------------------------\n";

    if (vClients.size() == 0)
    {
        cout << "\t\t\tNo Clients Available In The System!";
    }
    else
        for (stClient &C : vClients)
        {
            PrintClientData(C);

            cout << endl;
        }
    cout << "\n-------------------------------------------------------------------------------------------------------\n";
}

void GoBackToMainMenu()
{
    cout << "\n\nPress any key to go back to main menu...";
    system("pause>0");
    ShowMainMenu();
}

bool ClientExistByAccountNumber(string AccountNumber, string FileName)
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
            Client = ConvertLineToRecord(Line);

            if (Client.AccountNumber == AccountNumber)
            {
                MyFile.close();
                return true;
            }

            vClients.push_back(Client);
        }

        MyFile.close();
    }

    return false;
}

stClient ReadNewClient()
{
    stClient Client;

    cout << "Enter Account Number ? ";
    getline(cin >> ws, Client.AccountNumber);

    if (ClientExistByAccountNumber(Client.AccountNumber, ClientsFileName))
    {
        cout << "Client with Account Number [" << Client.AccountNumber << "] is already exist ! Please Enter another One ? ";
        getline(cin >> ws, Client.AccountNumber);
    }

    cout << "Enter Pin Code ? ";
    getline(cin, Client.PinCode);

    cout << "Enter Name ? ";
    getline(cin, Client.Name);

    cout << "Enter Phone ? ";
    getline(cin, Client.Phone);

    cout << "Enter Account Balance ? ";
    cin >> Client.AccountBalance;

    return Client;
}

string ConvertRecordToLine(stClient Client, string separator = "#//#")
{
    string RecordLine;

    RecordLine = RecordLine + Client.AccountNumber + separator;
    RecordLine = RecordLine + Client.PinCode + separator;
    RecordLine = RecordLine + Client.Name + separator;
    RecordLine = RecordLine + Client.Phone + separator;
    RecordLine = RecordLine + to_string(Client.AccountBalance);

    return RecordLine;
}

void AddClientLineToFile(string FileName, string ClientLine)
{
    fstream MyFile;

    MyFile.open(FileName, ios::app | ios::out);

    if (MyFile.is_open())
    {
        MyFile << ClientLine << endl;
    }

    MyFile.close();
}

void AddNewClient()
{
    stClient Client;

    Client = ReadNewClient();

    AddClientLineToFile(ClientsFileName, ConvertRecordToLine(Client));
}

void AddNewClients()
{
    char Answer = 'Y';

    do
    {
        cout << "Adding New Client\n\n";

        AddNewClient();

        cout << "\nClient Added successfully, do you want to add more clients ? (Y/N)? ";
        cin >> Answer;

    } while (Answer == 'y' || Answer == 'Y');
}

void ShowAddNewClientScreen()
{
    cout << "\n-----------------------------------------\n";
    cout << "\tAdd New Client Screen\t";
    cout << "\n-----------------------------------------\n";

    AddNewClients();
}

bool FindClientByAccountNumber(string AccountNumber, vector<stClient> &vClients, stClient &Client)
{
    for (stClient &C : vClients)
    {

        if (C.AccountNumber == AccountNumber)
        {
            Client = C;
            return true;
        }
    }

    return false;
}

string ReadClientAccountNumber()
{
    string AccountNumber = "";

    cout << "Enter Account Number ? ";
    cin >> AccountNumber;

    return AccountNumber;
}

void PrintClientCard(stClient Client)
{
    cout << "\n\nThe following is the client details :\n";

    cout << "---------------------------------------------------------------\n";

    cout << "\nAccount Number  : " << Client.AccountNumber;
    cout << "\nPin Code        : " << Client.PinCode;
    cout << "\nName            : " << Client.Name;
    cout << "\nPhone           : " << Client.Phone;
    cout << "\nAccount Balance : " << Client.AccountBalance;

    cout << "\n---------------------------------------------------------------\n";
}

vector<stClient> SaveClientDataToFile(string FileName, vector<stClient> vClients)
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

bool MarkClientForDeleteByAccountNumber(string AccountNumber, vector<stClient> &vClients)
{
    for (stClient &C : vClients)
    {
        if (AccountNumber == C.AccountNumber)
        {
            C.MarkForDelete = true;
            return true;
        }
    }
    return false;
}

bool DeleteClientByAccountNumber(string AccountNumber, vector<stClient> &vClients)
{
    stClient Client;

    char Answer = 'y';

    if (FindClientByAccountNumber(AccountNumber, vClients, Client))
    {
        PrintClientCard(Client);

        cout << "\n\nAre you sure you want to delete this client ? y/n ? ";
        cin >> Answer;

        if (Answer == 'Y' || Answer == 'y')
        {
            MarkClientForDeleteByAccountNumber(AccountNumber, vClients);
            SaveClientDataToFile(ClientsFileName, vClients);

            vClients = LoadClientsDataFromFile(ClientsFileName);

            cout << "\nClient Deleted Successfully.";
            return true;
        }
    }

    else
        cout << "Client with Account Number[" << AccountNumber << "] NOT Found!";

    return false;
}

void ShowDeleteClientScreen()
{
    cout << "\n-----------------------------------------\n";
    cout << "\tDelete Client Screen\t";
    cout << "\n-----------------------------------------\n";

    string AccountNumber = ReadClientAccountNumber();
    vector<stClient> vClients = LoadClientsDataFromFile(ClientsFileName);

    DeleteClientByAccountNumber(AccountNumber, vClients);
}

stClient ChangeClientRecord(string AccountNumber)
{
    stClient Client;

    Client.AccountNumber = AccountNumber;

    cout << "Enter Pin Code ? ";
    getline(cin >> ws, Client.PinCode);

    cout << "Enter Name ? ";
    getline(cin, Client.Name);

    cout << "Enter Phone ? ";
    getline(cin, Client.Phone);

    cout << "Enter Account Balance ? ";
    cin >> Client.AccountBalance;

    return Client;
}

bool UpdateClientByAccountNumber(string AccountNumber, vector<stClient> &vClients)
{
    stClient Client;
    char Answer = 'n';

    if (FindClientByAccountNumber(AccountNumber, vClients, Client))
    {
        PrintClientCard(Client);

        cout << "\n\nAre you sure you want to update this client ? Y/N ? ";
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {
            for (stClient &C : vClients)
            {
                if (C.AccountNumber == AccountNumber)
                {
                    C = ChangeClientRecord(AccountNumber);
                    break;
                }
            }

            SaveClientDataToFile(ClientsFileName, vClients);
            return true;
        }
    }
    else
        cout << "Client with Account Number(" << AccountNumber << ") NOT Found!";
}

void ShowUpdateClientScreen()
{
    cout << "\n-----------------------------------------\n";
    cout << "\tUpdate Client Screen\t";
    cout << "\n-----------------------------------------\n";

    string AccountNumber = ReadClientAccountNumber();
    vector<stClient> vClients = LoadClientsDataFromFile(ClientsFileName);

    UpdateClientByAccountNumber(AccountNumber, vClients);
}

void ShowFindClientScreen()
{
    cout << "\n-----------------------------------------\n";
    cout << "\tFind Client Screen\t";
    cout << "\n-----------------------------------------\n";

    string AccountNumber = ReadClientAccountNumber();
    vector<stClient> vClients = LoadClientsDataFromFile(ClientsFileName);
    stClient Client;

    if (FindClientByAccountNumber(AccountNumber, vClients, Client))
    {
        PrintClientCard(Client);
    }
    else
        cout << "\nClient with Account Number(" << AccountNumber << ") NOT Found!";
}

void ShowExitScreen()
{
    cout << "\n-----------------------------------------\n";
    cout << "\tPrograme Ends :-)\t";
    cout << "\n-----------------------------------------\n";
}

short ReadTransactionsOption()
{
    short Choice;

    cout << "Choose what do you want to do? [1 to 4]? ";
    cin >> Choice;

    return Choice;
}

bool DepositBalanceToClientByAccountNumber(string AccountNumber, float Amount, vector<stClient> &vClients)
{

    char Answer = 'y';

    cout << "\n\nAre you sure you want to perform this transaction? y/n ? ";
    cin >> Answer;

    if (Answer == 'y' || Answer == 'Y')
    {
        for (stClient &C : vClients)
        {
            if (C.AccountNumber == AccountNumber)
            {
                C.AccountBalance += Amount;
                SaveClientDataToFile(ClientsFileName, vClients);
                cout << "\n Done Successfully, New Balance = " << C.AccountBalance;
                return true;
            }
        }
        return false;
    }
}

void ShowDepsitScreen()
{
    cout << "\n-----------------------------------------\n";
    cout << "\t    Deposit Screen\t";
    cout << "\n-----------------------------------------\n";

    stClient Client;
    string AccountNumber = ReadClientAccountNumber();
    vector<stClient> vClients = LoadClientsDataFromFile(ClientsFileName);

    while (!FindClientByAccountNumber(AccountNumber, vClients, Client))
    {
        cout << "\nClient with [" << AccountNumber << "] does NOT Exist!" << endl;
        AccountNumber = ReadClientAccountNumber();
    }

    PrintClientCard(Client);

    float Amount = 0;
    cout << "\nPlease Enter deposit amount? ";
    cin >> Amount;

    DepositBalanceToClientByAccountNumber(AccountNumber, Amount, vClients);
}

void ShowWithdrawScreen()
{
    cout << "\n-----------------------------------------\n";
    cout << "\t    Withdraw Screen\t";
    cout << "\n-----------------------------------------\n";

    stClient Client;
    string AccountNumber = ReadClientAccountNumber();
    vector<stClient> vClients = LoadClientsDataFromFile(ClientsFileName);

    while (!FindClientByAccountNumber(AccountNumber, vClients, Client))
    {
        cout << "\nClient with [" << AccountNumber << "] does NOT Exist!" << endl;
        AccountNumber = ReadClientAccountNumber();
    }

    PrintClientCard(Client);

    float Amount = 0;
    cout << "\nPlease Enter Withdraw Amount : ";
    cin >> Amount;

    while (Amount > Client.AccountBalance)
    {
        cout << "\nAmount Exceeds the balance, you can withdraw up to : " << Client.AccountBalance << endl;
        cout << "Please Enter another amount : ";
        cin >> Amount;
    }

    DepositBalanceToClientByAccountNumber(AccountNumber, Amount * -1, vClients);
}

void GoBackToTransactionsScreen()
{
    cout << "\n\nPress any key to go back to transactions screen...";
    system("pause>0");
    ShowTransactionsScreen();
}

void PrintClientDataForBalancesScreen(stClient Client)
{
    cout << "| " << left << setw(15) << Client.AccountNumber;
    cout << "| " << left << setw(30) << Client.Name;
    cout << "| " << left << setw(12) << Client.AccountBalance;
}

void ShowTotalBalancesScreen()
{
    vector<stClient> vClients = LoadClientsDataFromFile(ClientsFileName);

    cout << "\n\t\t\t\t\tBalances List (" << vClients.size() << ") Client(s).";
    cout << "\n-------------------------------------------------------------------------------------------------------\n";
    cout << "| " << left << setw(15) << "Account Number";
    cout << "| " << left << setw(30) << "Name";
    cout << "| " << left << setw(12) << "Balance";

    cout << "\n-------------------------------------------------------------------------------------------------------\n";

    float TotalBalances = 0;

    if (vClients.size() == 0)
    {
        cout << "\t\t\t\tNo Clients Available In the System!";
    }

    else
        for (stClient &C : vClients)
        {
            PrintClientDataForBalancesScreen(C);
            TotalBalances += C.AccountBalance;

            cout << endl;
        }
    cout << "\n-------------------------------------------------------------------------------------------------------\n";

    cout << "\t\t\t\t\t Total Balances = " << TotalBalances << endl;
}

void PerformTransactionsOptions(enTransactionsOptions TransactionOption)
{
    switch (TransactionOption)
    {
    case enTransactionsOptions::eDeposit:
        system("cls");
        ShowDepsitScreen();
        GoBackToTransactionsScreen();
        break;

    case enTransactionsOptions::eWithdraw:
        system("cls");
        ShowWithdrawScreen();
        GoBackToTransactionsScreen();
        break;

    case enTransactionsOptions::eTotalBalances:
        system("cls");
        ShowTotalBalancesScreen();
        GoBackToTransactionsScreen();
        break;

    case enTransactionsOptions::eMainMenu:
        ShowMainMenu();
        break;
    }
}

void PerformMainMenuOption(enMainMenuOptions MainMenuOption)
{
    switch (MainMenuOption)
    {
    case enMainMenuOptions::eListClients:
        system("cls");
        ShowListClientsScreen();
        GoBackToMainMenu();
        break;

    case enMainMenuOptions::eAddNewClient:
        system("cls");
        ShowAddNewClientScreen();
        GoBackToMainMenu();
        break;

    case enMainMenuOptions::eDeleteClient:
        system("cls");
        ShowDeleteClientScreen();
        GoBackToMainMenu();
        break;

    case enMainMenuOptions::eUpdateClient:
        system("cls");
        ShowUpdateClientScreen();
        GoBackToMainMenu();
        break;

    case enMainMenuOptions::eFindClient:
        system("cls");
        ShowFindClientScreen();
        GoBackToMainMenu();
        break;

    case enMainMenuOptions::eTransactions:
        system("cls");
        ShowTransactionsScreen();
        break;

    case enMainMenuOptions::eExit:
        system("cls");
        ShowExitScreen();
        break;
    }
}

void ShowMainMenu()
{
    system("cls");

    cout << "\n====================================================================\n";
    cout << "\t\t Main Menu Screen \t\t";
    cout << "\n====================================================================\n";

    cout << "[1] Show Client List .\n";
    cout << "[2] Add New Client .\n";
    cout << "[3] Delete Client .\n";
    cout << "[4] Update Client Info .\n";
    cout << "[5] Find Client .\n";
    cout << "[6] Transactions .\n";
    cout << "[7] Exit .\n";

    cout << "====================================================================\n";

    PerformMainMenuOption((enMainMenuOptions)ReadMainMenuOption());
}

int main()
{
    ShowMainMenu();
    system("pause>0");
    return 0;
}

void ShowTransactionsScreen()
{
    system("cls");

    cout << "\n====================================================================\n";
    cout << "\t\t Transactions Menu Screen \t\t";
    cout << "\n====================================================================\n";

    cout << "\t [1] Deposit.\n";
    cout << "\t [2] Withdraw.\n";
    cout << "\t [3] Total Balances.\n";
    cout << "\t [4] Main Menu.\n";

    cout << "====================================================================\n";

    PerformTransactionsOptions((enTransactionsOptions)ReadTransactionsOption());
}