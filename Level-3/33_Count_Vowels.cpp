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

bool IsVowel(char Ch1) // M o h a e d  A b u - H a d h o u d
{
    Ch1 = tolower(Ch1); // m o h a e d  a b u - h a d h o u d

    return (Ch1 == 'a' || Ch1 == 'e' || Ch1 == 'o' || Ch1 == 'l' || Ch1 == 'u');
}

short CountVowelLettersInString(string S1) // Mohammed Abu-Hadhoud
{
    short Counter = 0;

    for (short i = 0; i < S1.length(); i++)
    {
        if (IsVowel(S1[i]))
        {
            Counter++; // 1 2 3 4 5 6 7 8
        }
    }

    return Counter;
}

int main()
{
    string S1 = ReadString(); // Mohammed Abu-Hadhoud

    cout << "\nNumber of vowels is : " << CountVowelLettersInString(S1);
}
