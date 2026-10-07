#include <iostream>
#include <string>
using namespace std;

string ReadString()
{
    string S1 = " ";

    cout << "Enter a string :\n";
    getline(cin, S1);

    return S1;
}

char ReadChar()
{
    char Ch1 = ' ';

    cout << "Enter a character :\n";
    cin >> Ch1;

    return Ch1;
}

short CountLetter(string S1, char Ch1) // Mohammed   m
{
    short Counter = 0;

    for (short i = 0; i < S1.length(); i++)
    {
        if (S1[i] == Ch1)
        {
            Counter++;
        }
    }

    return Counter; // 2
}

short CountLetterSmallOrCapital(string S1, char Ch1) // Mohammed   m
{
    short Counter = 0;

    char SmallLetterOfCh1 = tolower(Ch1);   // m
    char CapitalLetterOfCh1 = toupper(Ch1); // toupper(m)=M

    for (short i = 0; i < S1.length(); i++)
    {
        if (S1[i] == SmallLetterOfCh1 || S1[i] == CapitalLetterOfCh1)
        {
            Counter++; // 1 2 3
        }
    }

    return Counter; // 3
}

char InvertCaseLetter(char Ch1)
{
    return (Ch1 == isupper(Ch1) ? tolower(Ch1) : toupper(Ch1));
}

int main()
{
    string S1 = ReadString();
    char Ch1 = ReadChar();

    cout << "\nLetter \'" << Ch1 << "\' Count = " << CountLetter(S1, Ch1); // Letter 'm' count = 2

    cout << "\nLetter '" << Ch1 << "' or '" << InvertCaseLetter(Ch1) << "' Count = " << CountLetterSmallOrCapital(S1, Ch1); // Letter 'm' or 'M' Count = 3
}