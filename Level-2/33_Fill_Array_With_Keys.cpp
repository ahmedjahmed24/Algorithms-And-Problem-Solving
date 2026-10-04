#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

enum enCharType
{
    SmallLetter = 1,
    CapitalLetter = 2,
    Digit = 3,
    SpecialCharacter = 4
};

int ReadPositiveNumber(string Message)
{
    int Number = 0;

    do
    {
        cout << Message << endl;
        cin >> Number;

    } while (Number <= 0);

    return Number;
}

int RandomNumber(int From, int To)
{
    int RandNum = rand() % (To - From + 1) + From;
    return RandNum;
}

char GetRandomCharacter(enCharType CharType)
{
    switch (CharType)
    {
    case enCharType::SmallLetter:
        return char(RandomNumber(97, 122));
        break;

    case enCharType::CapitalLetter:
        return char(RandomNumber(65, 90));
        break;

    case enCharType::Digit:
        return char(RandomNumber(48, 57));
        break;

    case enCharType::SpecialCharacter:
        return char(RandomNumber(33, 47));
        break;
    }
}

string GenarateWord(enCharType CharType, short length)
{
    string Word = "";

    for (int i = 1; i <= length; i++)
    {
        Word = Word + GetRandomCharacter(CharType);
    }

    return Word;
}

string GenarateKey()
{
    string Key = "";

    Key = GenarateWord(enCharType::CapitalLetter, 4) + "-";
    Key = Key + GenarateWord(enCharType::CapitalLetter, 4) + "-";
    Key = Key + GenarateWord(enCharType::CapitalLetter, 4) + "-";
    Key = Key + GenarateWord(enCharType::CapitalLetter, 4);

    return Key;
}

void FillArrayWithKeys(string arr[100], int ArrLength)
{

    for (int i = 0; i < ArrLength; i++)
    {
        arr[i] = GenarateKey();
    }
}

void PrintStringArray(string arr[100], int ArrLength)
{
    cout << "Array Elements :\n";

    for (int i = 0; i < ArrLength; i++)
    {
        cout << "Array [" << i << "] : " << arr[i] << " " << endl;
    }
}

int main()
{
    srand((unsigned)time(NULL));

    string arr[100];
    int ArrLength = ReadPositiveNumber("How Many Keys Do You Want To Create ?");

    FillArrayWithKeys(arr, ArrLength);
    PrintStringArray(arr, ArrLength);
}