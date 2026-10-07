
/*
#include <iostream>
#include <string>
using namespace std;

char ReadChar()
{
    char Ch1;

    cout << "Please Enter a Character :\n";
    cin >> Ch1; // a

    return Ch1;
}

void PrintInvertingCharCase(char Ch1) // a  S
{
    cout << "Character after inverting :\n";

    if (isupper(Ch1))
    {
        cout << (char)tolower(Ch1); // s
    }
    else
        cout << (char)toupper(Ch1); // A
}

int main()
{
    PrintInvertingCharCase(ReadChar());
}
*/

#include <iostream>
#include <string>
using namespace std;

char ReadChar()
{
    char Ch1;

    cout << "Please Enter a Character :\n";
    cin >> Ch1;

    return Ch1;
}

char InvertLetterCase(char Ch1)
{
    return (isupper(Ch1) ? tolower(Ch1) : toupper(Ch1));
}

int main()
{
    char Ch1 = ReadChar();

    cout << "\nCharacter after inverting :\n";
    Ch1 = InvertLetterCase(Ch1);

    cout << Ch1 << endl;
}