#include <iostream>
#include <string>
using namespace std;

string ReadText()
{
    string Text;

    cout << "Please Enter Text :\n";
    getline(cin, Text);

    return Text;
}

string TextEncryption(string Text, short EncryptionKey)
{
    for (int i = 0; i <= Text.length(); i++)
    {
        Text[i] = char((int)Text[i] + EncryptionKey);
    }

    return Text;
}

string TextDecryption(string Text, short EncryptionKey)
{
    for (int i = 0; i <= Text.length(); i++)
    {
        Text[i] = char((int)Text[i] - EncryptionKey);
    }

    return Text;
}

int main()
{
    const short EncryptionKey = 2;

    string Text = ReadText();

    string TextBeforeEncryption = Text;
    string TextAfterEncryption = TextEncryption(Text, EncryptionKey);
    string TextAfterDecryption = TextDecryption(TextAfterEncryption, EncryptionKey);

    cout << "Text Before Encryption :\n";
    cout << Text << endl;
    cout << "Text After Encryption :\n";
    cout << TextAfterEncryption << endl;
    cout << "Text After Decryption :\n";
    cout << TextAfterDecryption << endl;
}

/*
حلي ولكن لا  يؤدي المطلوب بشكل صحيح ع حسب مافهمت حليت بس طلع بدو اكتر
#include <iostream>
#include <string>
using namespace std;

string ReadName()
{
    string Name;

    cout << "Enter Your Name :\n";
    cin >> Name;

    return Name;
}

string NameBeforeEncryption(string Name)
{
    return Name;
}

string NameAfterEncryption(string Name)
{
    short n = Name.length();

    string NameAfterEncryption;
    string Encryption = "Oqfoo";

    NameAfterEncryption = NameAfterEncryption + Encryption;

    return NameAfterEncryption;
}

string NameAfterDecryption(string Name)
{
    string name;
    string Decryption = Name; //"Ahmed"

    name = name + Decryption;

    return name;
}

int main()
{
    string Name = ReadName();
    cout << "Name Before Encryption :" << NameBeforeEncryption(Name) << endl;
    cout << "Name After Encryption :" << NameAfterEncryption(Name) << endl;
    cout << "Name After Encryption :" << NameAfterDecryption(Name) << endl;
}*/