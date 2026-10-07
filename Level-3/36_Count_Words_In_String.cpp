#include <iostream>
#include <string>
using namespace std;

string ReadString()
{
    string S1 = " ";

    cout << "Enter your string :\n";
    getline(cin, S1);

    return S1;
}

short CountEachWordInString(string S1) // Mohammed Abu-Hadhoud @ProgrammingAdvices Ahmed
{
    short Pos = 0;
    string sWord;
    string delim = " ";
    short Counter = 0;

    while ((Pos = S1.find(delim)) != S1.npos)
    {
        sWord = S1.substr(0, Pos);

        if (sWord != "")
        {
            Counter++; // 1 2 3
        }

        S1.erase(0, Pos + delim.length());
    }

    if (S1 != " ")
    {
        Counter++; // 4
    }

    return Counter;
}

int main()
{
    cout << "The number Of words in your string is : " << CountEachWordInString(ReadString());
}