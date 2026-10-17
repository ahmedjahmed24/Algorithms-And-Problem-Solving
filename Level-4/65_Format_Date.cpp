#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct stDate
{
    short Year = 0;
    short Month = 0;
    short Day = 0;
};

string ReadStringDate(string Message)
{
    string StringDate;

    cout << Message;
    getline(cin >> ws, StringDate);

    return StringDate;
}

vector<string> SplitString(string S1, string delim) // " 31/12/2022 "  - "/"
{
    short Pos = 0;
    string sWord;
    vector<string> vString;

    while ((Pos = S1.find(delim)) != S1.npos)
    {
        sWord = S1.substr(0, Pos);
        if (sWord != "")
        {
            vString.push_back(sWord);
        }

        S1.erase(0, Pos + delim.length());
    }

    if (S1 != "")
    {
        vString.push_back(S1);
    }

    return vString;
}

stDate ConvertStringDateToDate(string StringDate) // " 31/12/2022 "
{
    vector<string> vDate = SplitString(StringDate, "/"); // vDate={"31","12","2022"};
    stDate Date;

    Date.Day = stoi(vDate[0]);
    Date.Month = stoi(vDate[1]);
    Date.Year = stoi(vDate[2]);

    return Date;
}

string DateToString(stDate Date)
{
    return to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
}

string ReplaceWordInString(string S1, string WordToReplace, string ReplaceTo) // "dd/mm/yyyy" - dd - to_stirng(Date.Day)
{
    short Pos = S1.find(WordToReplace);

    while (Pos != S1.npos)
    {
        S1 = S1 + S1.replace(Pos, WordToReplace.length(), ReplaceTo);
        Pos = S1.find(WordToReplace);
    }

    return S1;
}

string FormatDate(stDate Date, string DateFormat = "dd/mm/yyyy")
{
    string DateeFormat = "";

    DateeFormat = ReplaceWordInString(DateFormat, "dd", to_string(Date.Day));
    DateeFormat = ReplaceWordInString(DateeFormat, "mm", to_string(Date.Month));
    DateeFormat = ReplaceWordInString(DateeFormat, "yyyy", to_string(Date.Year));

    return DateeFormat;
}

int main()
{
    string StringDate = ReadStringDate("Please Enter Date dd/mm/yyyy : ");
    stDate Date = ConvertStringDateToDate(StringDate);

    cout << FormatDate(Date) << endl;
    cout << FormatDate(Date, "yyyy/mm/dd") << endl;
    cout << FormatDate(Date, "mm/dd/yyyy") << endl;
    cout << FormatDate(Date, "mm-dd-yyyy") << endl;
    cout << FormatDate(Date, "dd-mm,yyyy") << endl;
    cout << FormatDate(Date, "Day:dd - Month:mm - Year:yyyy") << endl;
}