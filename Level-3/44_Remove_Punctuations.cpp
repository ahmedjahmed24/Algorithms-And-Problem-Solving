#include <iostream>
#include <string>
using namespace std;

string RemovePuncuations(string S1)
{
    string S2 = "";

    for (short i = 0; i < S1.length(); i++)
    {
        if (!ispunct(S1[i]))
        {
            S2 += S1[i];
        }
    }

    return S2;
}

int main()
{
    string S1 = "Welcome to Jordan , Jordan is a nice country; it's amazing.";

    cout << "\nOrginal string : " << S1 << endl;

    cout << "\nString after removed puncuations : " << RemovePuncuations(S1);
}