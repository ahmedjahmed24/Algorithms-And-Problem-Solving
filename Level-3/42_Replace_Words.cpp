#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> SplitString(string S1, string delim) // Welcome to Jordan , Jordan is a nice country
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

vector<string> ReplaceWordsInString(string S1, string WantReplace, string ReplaceTo)
{
    vector<string>vString=SplitString(S1," "); // vString={"Welcome" ,"to", "Jordan" , "Jordan", "is", "a", "nice" ,"country"};

    for (short i = 0; i < vString.size(); i++)
    {
        if (vString[i] == WantReplace)
        {
            vString[i] = ReplaceTo;
        }
    }

    return vString;
}

int main()
{
    string S1 = "Welcome to Jordan , Jordan is a nice country";
    cout << "Orgianl String :\n";
    cout << S1 << endl;

    vector<string> vString = ReplaceWordsInString(S1, "Jordan", "USA"); // vString={"Welcome" ,"to", "USA" , "USA", "is", "a", "nice" ,"country"};

    for (const string &s : vString)
    {
        cout << s << " ";
    }
}