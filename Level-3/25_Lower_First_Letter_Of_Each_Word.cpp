#include <iostream>
#include <string>
using namespace std;

string ReadString()
{
    string S1 = "";

    cout << "Enter a string :\n";
    getline(cin, S1);

    return S1;
}

string LowerFirstLettersOfEachWord(string S1) // ahmed jamsheed ahmed
{
    bool IsFirstLetter = true;

    for (int i = 0; i < S1.length(); i++)
    {
        if (S1[i] != ' ' && IsFirstLetter)
        {
            S1[i] = tolower(S1[i]);
        }

        IsFirstLetter = (S1[i] == ' ' ? true : false);
    }

    return S1;
}

int main()
{
    string S1 = ReadString();
    cout << "String after convert :\n";
    S1 = LowerFirstLettersOfEachWord(S1);
    cout << S1 << endl;
}