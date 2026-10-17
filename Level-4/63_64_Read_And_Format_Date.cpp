#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct stDate
{
    short Day = 0;
    short Month = 0;
    short Year = 0;
};

string ReadStringDate()
{
    string StringDate;

    cout << "Please Enter Date dd/mm/yyyy : ";
    cin >> StringDate;

    return StringDate;
}

vector<string> SplitString(string S1, string delim) // " 2022 "
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

stDate ConvertStringDateToDate(string StringDate) // "10/12/2022"
{
    stDate Date;
    vector<string> vDate = SplitString(StringDate, "/"); // vString={"31","12","2022"};

    Date.Day = stoi(vDate[0]);
    Date.Month = stoi(vDate[1]);
    Date.Year = stoi(vDate[2]);

    return Date;
}

string DateToString(stDate Date)
{
    // string StringDate;

    // StringDate = StringDate + to_string(Date.Day) + "/";
    // StringDate = StringDate + to_string(Date.Month) + "/";
    // StringDate = StringDate + to_string(Date.Year);

    // return StringDate;

    return to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
}

int main()
{
    string StringDate = ReadStringDate();

    stDate Date = ConvertStringDateToDate(StringDate);

    cout << "\n\nDay : " << Date.Day;
    cout << "\nMonth : " << Date.Month;
    cout << "\nYear  : " << Date.Year;

    string DateString = DateToString(Date);

    cout << "\n\nyou entered : " << DateString;
}