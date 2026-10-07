#include <iostream>
#include <string>
#include <vector>
using namespace std;

string JoinString(vector<string> &vString, string delim)
{
    string S1;

    for (const string &s : vString)
    {
        S1 = S1 + s + delim; // S1=Ahmed from syria
    }

    return S1.substr(0, S1.length() - delim.length());
}

string JoinString(string arrString[], short Length, string delim) // arrString={"ahmed","from","syria"};
{
    string S1;

    for (short i = 0; i < Length; i++)
    {
        S1 = S1 + arrString[i] + delim; // S1=ahmed from syria
    }

    return S1.substr(0, S1.length() - delim.length());
}

int main()
{
    vector<string> vS1 = {"Ahmed", "from", "syria"};
    string arrString[] = {"Ahmed", "from", "syria"};

    cout << "Join string :\n";
    cout << JoinString(vS1, " ");

    cout << "\n\nJoin string using array :\n";
    cout << JoinString(arrString, 3, " ");
}