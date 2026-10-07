#include <iostream>
#include <string>
using namespace std;

char ReadChar()
{
    char Ch1 = ' ';

    cout << "Enter a Character :\n";
    cin >> Ch1;

    return Ch1;
}

bool IsVowelLetter(char Ch1) // A
{
    Ch1 = tolower(Ch1);//a

    return (Ch1 == 'a' || Ch1 == 'e' || Ch1 == 'o' || Ch1 == 'l' || Ch1 == 'u');
}

int main()
{
    char Ch1 = ReadChar();

    if (IsVowelLetter(Ch1))
    {
        cout << "Yes, Letter \'" << Ch1 << "\' is Vowel";
    }
    else
        cout << "No, Letter \'" << Ch1 << "\' is NOT Vowel";
}