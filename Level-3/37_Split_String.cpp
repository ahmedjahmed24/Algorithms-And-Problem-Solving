#include <iostream>
#include <string>
#include <vector>
using namespace std;

string ReadString()
{
    string S1 = " ";

    cout << "Enter your string :\n";
    getline(cin, S1);

    return S1;
}

vector<string> SplitString(string S1, string delim) // Mohammed Sami Rami
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

int main()
{
    vector<string> vString = SplitString(ReadString(), " ");

    cout << "Tokens : " << vString.size() << endl;

    for (const string &s : vString)
    {
        cout << s << endl;
    }
}