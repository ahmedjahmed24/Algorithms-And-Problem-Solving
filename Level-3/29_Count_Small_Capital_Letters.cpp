#include <iostream>
#include <string>
using namespace std;

enum enWhatToCount
{
    SmallLetters = 0,
    CapitalLetters = 1,
    All = 3
};

short CountLetters(string S1, enWhatToCount WhatToCount = enWhatToCount::All) // Ahmed Ahmed
{
    short Counter = 0;

    if (WhatToCount == enWhatToCount::All)
    {
        Counter = S1.length();
    }

    for (short i = 0; i < S1.length(); i++)
    {

        if (WhatToCount == enWhatToCount::SmallLetters && islower(S1[i]))
        {
            Counter++;
        }
        else if (WhatToCount == enWhatToCount::CapitalLetters && isupper(S1[i]))
        {
            Counter++;
        }
    }

    return Counter;
}

string ReadString()
{
    string S1 = " ";

    cout << "Enter a string :\n";
    getline(cin, S1);

    return S1;
}

short CountCapitalLetters(string S1) // Ahmed Ahmed
{
    short CountUpperLetters = 0;

    for (short i = 0; i < S1.length(); i++)
    {
        if (isupper(S1[i]))
        {
            CountUpperLetters++;
        }
    }

    return CountUpperLetters;
}

short CountSmallLetters(string S1) // Ahmed Ahmed
{
    short CounLowerLetters = 0;

    for (short i = 0; i < S1.length(); i++)
    {
        if (islower(S1[i]))
        {
            CounLowerLetters++;
        }
    }

    return CounLowerLetters;
}

int main()
{
    string S1 = ReadString();

    cout << "All string Letters = " << S1.length() << endl;
    cout << "Capital letters count = " << CountCapitalLetters(S1) << endl;
    cout << "Small letters count = " << CountSmallLetters(S1) << endl;

    cout << "\n\nMethod 2 :\n";

    cout << "All string Letters = " << CountLetters(S1) << endl;
    cout << "Capital letters count = " << CountLetters(S1, enWhatToCount::CapitalLetters) << endl;
    cout << "Small letters count = " << CountLetters(S1, enWhatToCount::SmallLetters) << endl;
}