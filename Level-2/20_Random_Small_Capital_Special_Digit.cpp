#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int RandomNumber(int From, int To)
{
    int RandNum = rand() % (To - From + 1) + From;
    return RandNum;
}

enum enCharType
{
    SmallLetter = 1,
    CapitalLetter = 2,
    Digit = 3,
    SpecialCharacter = 4
};

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

int main()
{
    srand((unsigned)time(NULL));

    cout << GetRandomCharacter(enCharType::SmallLetter) << endl;
    cout << GetRandomCharacter(enCharType::CapitalLetter) << endl;
    cout << GetRandomCharacter(enCharType::Digit) << endl;
    cout << GetRandomCharacter(enCharType::SpecialCharacter) << endl;
}

/*
حلي قريب جداااا عحل الاستاذ الفرق في طباعة ال digit

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

enum enRandom
{
    SmallLetter = 1,
    CapitalLetter = 2,
    SpecialCarachter = 3,
    Digit = 4
};

int RandomNmber(int From, int To)
{
    int RandNum = rand() % (To - From + 1) + From;
    return RandNum;
}

void PrintRandom(enRandom RandomThing)
{
    int RandomChar = 0;
    int RandDigit = 0;

    switch (RandomThing)
    {
    case enRandom::SmallLetter:

        RandomChar = RandomNmber(97, 122);
        cout << char(RandomChar) << endl;

        break;

    case enRandom::CapitalLetter:

        RandomChar = RandomNmber(65, 90);
        cout << char(RandomChar) << endl;

        break;

    case enRandom::Digit:

        RandDigit = rand() % 10;
        cout << RandDigit << endl;

        break;

    case enRandom::SpecialCarachter:

        RandomChar = RandomNmber(33, 47);
        cout << char(RandomChar) << endl;

        break;
    }
}

int main()
{
    srand((unsigned)time(NULL));

    PrintRandom(enRandom::SmallLetter);
    PrintRandom(enRandom::CapitalLetter);
    PrintRandom(enRandom::Digit);
    PrintRandom(enRandom::SpecialCarachter);

    return 0;
}*/