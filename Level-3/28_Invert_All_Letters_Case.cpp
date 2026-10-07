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

char InvertLetterCase(char Ch1)
{
    return (isupper(Ch1) ? tolower(Ch1) : toupper(Ch1));
}

string InvertAllStringLetterCase(string S1) // ahmed AHMED
{
    for (short i = 0; i < S1.length(); i++)
    {
        S1[i] = InvertLetterCase(S1[i]);
    }

    return S1;
}

int main()
{
    string S1 = ReadString();

     S1 = InvertAllStringLetterCase(S1);

    cout << "String after inverting all letters :\n";
    cout << S1 << endl;
}