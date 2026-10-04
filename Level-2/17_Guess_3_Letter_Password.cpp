#include <iostream>
using namespace std;

string ReadPassword()
{
    string Password;

    cout << "Please enter a 3-Letter Password (all capital)?\n";
    cin >> Password;

    return Password;
}

bool GuessPassword(string OrginalPassword)
{
    string Word = "";
    int Counter = 0;

    for (int i = 65; i <= 90; i++)
    {
        for (int j = 65; j <= 90; j++)
        {
            for (int k = 65; k <= 90; k++)
            {
                Word = Word + char(i);
                Word = Word + char(j);
                Word = Word + char(k);

                Counter++;
                cout << "Trial [" << Counter << "] : " << Word << endl;

                if (Word == OrginalPassword)
                {
                    cout << "\nPassword is " << Word << endl;
                    cout << "Found After " << Counter << "\nTrial(s)\n";
                    return true;
                }
                Word = "";
            }
        }
    }
    return false;
}

int main()
{
    GuessPassword(ReadPassword());
}

