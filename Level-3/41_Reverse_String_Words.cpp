#include <iostream>
#include <string>
#include <vector>
using namespace std;

string ReadString()
{
    string S1;

    cout << "Enter your string:\n";
    getline(cin, S1);

    return S1;
}

vector<string> SplitString(string S1, string delim) // Mohammed Sami Rami
{
    short Pos = 0;
    string sWord;
    vector<string> vWord;

    while ((Pos = S1.find(delim)) != S1.npos)
    {
        sWord = S1.substr(0, Pos);

        if (sWord != " ")
        {
            vWord.push_back(sWord);
        }

        S1.erase(0, Pos + delim.length());
    }

    if (S1 != " ")
    {
        vWord.push_back(S1);
    }

    return vWord;
}

string ReverseString(string S1) // Ahmed From Syria
{
    string S2 = "";
    vector<string> vString = SplitString(S1, " "); // vString={"ahmed","from","syria"};

    vector<string>::iterator iter = vString.end();

    while (iter != vString.begin())
    {
        --iter;
        S2 = S2 + *iter + " "; // S2=Ahmed From syria
    }

    return S2.substr(0, S2.length() - 1);
}

int main()
{
    string S1 = ReadString();

    cout << "Your string :\n";
    cout << S1 << endl;

    cout << "String after Reverse :\n";
    cout << ReverseString(S1);
}