#include <iostream>
#include <string>
using namespace std;

string ReadString()
{
    string S1 = "";

    cout << "Enter a string:\n";
    getline(cin, S1);

    return S1;
}

void PrintFirstLettersOfEachWord(string S1) // Ahmed Jamsheed Ahmed
{
    bool IsFirstLetter = true;

    cout << "First letters of each word in this string :\n";

    for (int i = 0; i < S1.length(); i++)
    {
        if (S1[i] != ' ' && IsFirstLetter)
        {
            cout << S1[i] << endl; // A J A
        }

        IsFirstLetter = (S1[i] == ' ' ? true : false);
    }
}

int main()
{
    PrintFirstLettersOfEachWord(ReadString());
}