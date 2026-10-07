#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string ReadString()
{
    string S1 = "";

    do
    {
        cout << "Enter a string:\n";
        getline(cin, S1);

    } while (S1.empty());

    return S1;
}

string UpperFirstLettersOfEachWord(string S1)
{
    bool IsFirstLetter = true;

    for (int i = 0; i < S1.length(); i++)
    {
        if (S1[i] != ' ' && IsFirstLetter)
        {
            S1[i] = toupper(S1[i]);
        }

        IsFirstLetter = (S1[i] == ' ');
    }

    return S1;
}

int main()
{
    string S1 = ReadString();

    cout << "\nString after convert:\n";
    cout << UpperFirstLettersOfEachWord(S1) << endl;

    return 0;
}