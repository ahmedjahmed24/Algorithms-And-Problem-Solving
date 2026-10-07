#include <iostream>
#include <string>
#include <vector>
using namespace std;

string JoinString(vector<string> &vString, string delim) // Mohammed Ahmed Sami Rami 
{
    string S1;

    /*for (short i = 0; i < vString.size(); i++)
    {
        S1=S1+vString[i];

        if (i<vString.size()-1)
        {
            S1=S1+delim;
        }

    }*/

    for (const string &s : vString)
    {
        S1 = S1 + s + delim;
    }

    return S1.substr(0,S1.length()-delim.length());
}

int main()
{
    vector<string> vString = {"Mohammed", "Ahmed", "Sami", "Rami"};

    cout << "Vector after join :\n";
    cout << JoinString(vString, " # ");
}