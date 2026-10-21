#pragma warning(disable : 4996)
#pragma once

#include <iostream>
#include <vector>
using namespace std;

class clsString
{
private:
    string _Value;

public:
    clsString()
    {
        _Value = "";
    }

    clsString(string Value)
    {
        _Value = Value;
    }

    void SetValue(string Value)
    {
        _Value = Value;
    }

    string GetValue()
    {
        return _Value;
    }

    static short Length(string S1)
    {
        return S1.length();
    }

    short Length()
    {
        return _Value.length();
    }

    static void PrintFirstLetterOfEachWord(string S1)
    {
        bool isFirstLetter = true;
        cout << "\nFirst letters of this string :\n";

        for (int i = 0; i < S1.length(); i++)
        {
            if (S1[i] != ' ' && isFirstLetter)
            {
                cout << S1[i] << endl;
            }

            isFirstLetter = (S1[i] == ' ' ? true : false);
        }
    }

    void PrintFirstLetterOfEachWord()
    {
        PrintFirstLetterOfEachWord(_Value);
    }

    static string UpeerFirstLetterOfEachWord(string S1)
    {
        bool isFirstLetter = true;

        for (int i = 0; i < S1.length(); i++)
        {

            if (S1[i] != ' ' && isFirstLetter)
            {
                S1[i] = toupper(S1[i]);
            }

            isFirstLetter = (S1[i] == ' ' ? true : false);
        }

        return S1;
    }

    void UpeerFirstLetterOfEachWord()
    {
        _Value = UpeerFirstLetterOfEachWord(_Value);
    }

    static string LowerFirstLetterOfEachWord(string S2)
    {
        bool isFirstLetter = true;

        for (int i = 0; i < S2.length(); i++)
        {
            if (S2[i] != ' ' && isFirstLetter)
            {
                S2[i] = tolower(S2[i]);
            }

            isFirstLetter = (S2[i] == ' ' ? true : false);
        }

        return S2;
    }

    void LowerFirstLetterOfEachWord()
    {
        _Value = LowerFirstLetterOfEachWord(_Value);
    }

    static char InvertLetterCase(char Char1)
    {
        return isupper(Char1) ? tolower(Char1) : toupper(Char1);
    }

    static bool IsVowel(char Ch4)
    {
        Ch4 = tolower(Ch4);
        return ((Ch4 == 'a') || (Ch4 == 'e') || (Ch4 == 'i') || (Ch4 == 'o') || (Ch4 == 'u'));
    }

    static string UpperAllString(string S3)
    {
        for (int i = 0; i < S3.length(); i++)
        {
            S3[i] = toupper(S3[i]);
        }
        return S3;
    }

    void UpperAllString()
    {
        _Value = UpperAllString(_Value);
    }

    static string LowerAllString(string S3)
    {
        for (int i = 0; i < S3.length(); i++)
        {
            S3[i] = tolower(S3[i]);
        }
        return S3;
    }

    void LowerAllString()
    {
        _Value = LowerAllString(_Value);
    }

    static string InvertAllLetterCase(string S1)
    {
        for (int i = 0; i < S1.length(); i++)
        {
            S1[i] = InvertLetterCase(S1[i]);
        }

        return S1;
    }

    void InvertAllStringLetterCase()
    {
        _Value = InvertAllLetterCase(_Value);
    }

    static short CountCapitalLetters(string S1)
    {
        short Counter = 0;

        for (int i = 0; i < S1.length(); i++)
        {
            if (isupper(S1[i]))
                Counter++;
        }

        return Counter;
    }

    short CountCapitalLetters()
    {
        return CountCapitalLetters(_Value);
    }

    static short CountSmallLetters(string S1)
    {
        short Counter = 0;

        for (int i = 0; i < S1.length(); i++)
        {
            if (islower(S1[i]))
                Counter++;
        }

        return Counter;
    }

    short CountSmallLetters()
    {
        return CountSmallLetters(_Value);
    }

    enum enWhatToCount
    {
        SmallLetters = 0,
        CapitalLetters = 1,
        All = 3
    };

    static short CountLetters(string S5, enWhatToCount WhatToCount = enWhatToCount::All)
    {
        if (WhatToCount == enWhatToCount::All)
        {
            return S5.length();
        }

        short Counter = 0;

        for (int i = 0; i < S5.length(); i++)
        {
            if (WhatToCount == enWhatToCount::CapitalLetters && isupper(S5[i]))
                Counter++;
            if (WhatToCount == enWhatToCount::SmallLetters && islower(S5[i]))
                Counter++;
        }
        return Counter;
    }

    short CountLetters()
    {
        return CountLetters(_Value);
    }

    static short CountSpecificLetter(string S6, char Letter, bool MatchCase = true)
    {
        short Counter = 0;

        for (short i = 0; i <= S6.length(); i++)
        {
            if (MatchCase)
            {
                if (S6[i] == Letter)
                    Counter++;
            }
            else
            {
                if (tolower(S6[i]) == tolower(Letter))
                    Counter++;
            }
        }
        return Counter;
    }

    short CountSpecificLetter(char Char, bool MatchCase = true)
    {
        return CountSpecificLetter(_Value, Char, MatchCase);
    }

    static short CountVowels(string S7)
    {
        short Counter = 0;

        for (short i = 0; i < S7.length(); i++)
        {
            if (IsVowel(S7[i]))
            {
                Counter++;
            }
        }

        return Counter;
    }

    short CountVowels()
    {
        return CountVowels(_Value);
    }

    static void PrintVowels(string S8)
    {
        cout << "\nVowels in string are : ";
        for (short i = 0; i < S8.length(); i++)
        {
            if (IsVowel(S8[i]))
            {
                cout << S8[i] << " ";
            }
        }
    }

    void PrintVowels()
    {
        PrintVowels(_Value);
    }

    static void PrintEachWordInString(string S9)
    {
        string delim = " ";

        cout << "\nYour string words are : \n\n";

        short pos = 0;
        string sWord;

        while ((pos = S9.find(delim)) != std::string::npos)
        {
            sWord = S9.substr(0, pos);

            if (sWord != "")
            {
                cout << sWord << endl;
            }

            S9.erase(0, pos + delim.length());
        }

        if (S9 != "")
        {
            cout << S9 << endl;
        }
    }

    void PrintEachWordInString()
    {
        PrintEachWordInString(_Value);
    }

    static short CountWords(string S9)
    {
        string delim = " "; // Delimiter
        short Count = 0;
        short pos = 0;
        string sWord;

        while ((pos = S9.find(delim)) !=
               std::string::npos)
        {
            sWord = S9.substr(0, pos);
            if (sWord != "")
            {
                Count++;
            }
            // erase() until positon and move to next word
            S9.erase(0, pos + delim.length());
        }
        if (S9 != "")
        {
            // it print last word of the string
            Count++;
        }
        return Count;
    }

    short CountWords()
    {
        return CountWords(_Value);
    }

    static vector<string> Split(string S9, string Delim)
    {
        vector<string> vString;
        short pos = 0;
        string sWord;
        while ((pos = S9.find(Delim)) !=
               std::string::npos)
        {
            sWord = S9.substr(0, pos);
            if (sWord != "")
            {
                vString.push_back(sWord);
            }

            S9.erase(0, pos + Delim.length());
        }
        if (S9 != "")
        {
            // it print last word of the string
            vString.push_back(S9);
        }
        return vString;
    }

    vector<string> Split(string delim)
    {
        return Split(_Value, delim);
    }

    static string TrimLeft(string S10) //   Mohemdd
    {
        for (short i = 0; i < S10.length(); i++)
        {
            if (S10[i] != ' ')
            {
                return S10.substr(i, S10.length() - i);
            }
        }
        return "";
    }

    void TrimLeft()
    {
        _Value = TrimLeft(_Value);
    }

    static string TrimRight(string S10) // Mohemmd
    {
        for (short i = S10.length() - 1; i >= 0; i--)
        {
            if (S10[i] != ' ')
            {
                return S10.substr(0, i + 1);
            }
        }
        return "";
    }

    void TrimRight()
    {
        _Value = TrimRight(_Value);
    }

    static string Trim(string S10)
    {
        return TrimLeft(TrimRight(S10));
    }

    void Trim()
    {
        _Value = Trim(_Value);
    }

    static string JoinString(vector<string> vString, string Delim = " ")
    {
        string S1 = "";

        for (string &s : vString)
        {
            S1 = S1 + s + Delim;
        }

        return S1.substr(0, S1.length() - Delim.length());
    }

    static string JoinString(string arrString[], short Length, string Delim = " ")
    {
        string S1 = "";

        for (short i = 0; i < Length; i++)
        {
            S1 = S1 + arrString[i] + Delim;
        }

        return S1.substr(0, S1.length() - Delim.length());
    }

    static string ReverseWords(string S11)
    {
        vector<string> vString;
        string S2 = "";

        vString = Split(S11, " ");

        vector<string>::iterator iter = vString.end();
        while (iter != vString.begin())
        {
            --iter;
            S2 += *iter + " ";
        }
        S2 = S2.substr(0, S2.length() - 1); // remove last space.
        return S2;
    }

    void ReverseWords()
    {
        _Value = ReverseWords(_Value);
    }

    static string ReplaceWord(string S12, string StringToReplace, string sRepalceTo, bool MatchCase = true)
    {
        vector<string> vString = Split(S12, " ");

        for (string &s : vString)
        {
            if (MatchCase)
            {
                if (s == StringToReplace)
                {
                    s = sRepalceTo;
                }
            }
            else if (LowerAllString(s) == LowerAllString(StringToReplace))
            {
                s = sRepalceTo;
            }
        }

        return JoinString(vString, " ");
    }

    string ReplaceWord(string StringToReplace, string ReplaceTo, bool MatchCase = true)
    {
        return ReplaceWord(_Value, StringToReplace, ReplaceTo, MatchCase);
    }

    static string RemovePunctuationsFromString(string S14)
    {
        string S2 = "";
        for (short i = 0; i < S14.length(); i++)
        {
            if (!ispunct(S14[i]))
            {
                S2 += S14[i];
            }
        }
        return S2;
    }

    void RemovePunctuationsFromString()
    {
        _Value = RemovePunctuationsFromString(_Value);
    }
};
