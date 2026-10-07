#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> SplitString(string S1, string delim) // ahmed ahmed
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

string LowerAllString(string S1) // Jordan
{
    for (short i = 0; i < S1.length(); i++)
    {
        S1[i] = tolower(S1[i]);
    }

    return S1;
}

string JoinString(vector<string> vString, string delim) // بياخد الفكتور اللي مربلس vString={"Welcome" ,"to" ,"USA" , "USA" ,"is" ,"a" ,"nice" ,"country"};
{
    string S1 = "";

    for (string &s : vString)
    {
        S1 = S1 + s + delim; // S1 = Welcome to USA , USA is a nice country
    }
    return S1.substr(0, S1.length() - delim.length());
}

string ReplaceWordsInStringUsingSplit(string S1, string WantReplace, string ReplaceTo, bool MatchCase = true)
{
    vector<string> vString = SplitString(S1, " "); // vString={"Welcome" ,"to", "Jordan" , "Jordan" ,"is" ,"a", "nice", "country"}

    for(string &s : vString)
    {
        if (MatchCase)
        {
            if (s==WantReplace)
            {
                s=ReplaceTo;
            }
            
        }
        else
        {
            if (LowerAllString(s)==LowerAllString(WantReplace))
            {
                s=ReplaceTo;
            }
            
        }
        
    }

    return JoinString(vString," ");//vString={"Welcome" ,"to", "USA" , "USA" ,"is" ,"a", "nice", "country"}
}


int main()
{
    string WantReplace = "jordan";
    string ReplaceTo = "USA";

    string S1 = "Welcome to Jordan , Jordan is a nice country";
    cout << "\nOrginal string : " << S1 << endl;

    cout << "\nReplace with match case :\n";
    cout << ReplaceWordsInStringUsingSplit(S1, WantReplace, ReplaceTo);

    cout << "\nReplace without match case :\n";
    cout << ReplaceWordsInStringUsingSplit(S1, WantReplace, ReplaceTo, false);
}