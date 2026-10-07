#include <iostream>
#include <string>
using namespace std;

string ReadString()
{
    string S1;

    cout << "Enter a string :\n";
    getline(cin, S1);

    return S1;
}

string TermLeft(string S1) //   Mohammed Ahmed
{
    int Start = 0;

    while (Start < S1.length() && S1[Start] == ' ')
    {
        ++Start; // 1 2 3
    }

    S1 = S1.substr(Start); // عطيني السترينج الجديد بلشو من للاخير s1[start] = s1[3]=M

    return S1;
}

string TermRight(string S1) // mohmmed    
{
    int End = S1.length(); // End =10

    while (S1[End] == ' ')
    {
        --End; // 10 9 8 7 5 6
    }

    S1 = S1.substr(0, End); // 0,6=mohammed

    return S1;
}

string Term(string S1) // mohammed
{
    S1 = TermLeft(S1);
    S1 = TermRight(S1);

    return S1;
}

int main()
{
    string S1 = ReadString();

    cout << "String after term left :\n";
    cout << TermLeft(S1) << endl;

    cout << "String after term right :\n";
    cout << TermRight(S1) << endl;

    cout << "String after term :\n";
    cout << Term(S1) << endl;
}