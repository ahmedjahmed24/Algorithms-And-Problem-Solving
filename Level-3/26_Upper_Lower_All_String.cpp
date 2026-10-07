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

string UpperAllString(string S1)
{
    for (int i = 0; i < S1.length(); i++)
    {
        S1[i] = toupper(S1[i]);
    }

    return S1;
}

string LowerAllString(string S1)
{
    for (int i = 0; i < S1.length(); i++)
    {
        S1[i] = tolower(S1[i]);
    }

    return S1;
}

int main()
{
    string S1 = ReadString();

    cout << "\nString after upper letters :\n";
    cout << UpperAllString(S1);

    cout << "\nString after lower letters :\n";
    cout << LowerAllString(S1);
}