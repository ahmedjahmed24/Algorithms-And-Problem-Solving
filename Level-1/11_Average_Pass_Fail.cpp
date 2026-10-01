#include <iostream>
using namespace std;

enum enPassFail
{
    Pass = 1,
    Fail = 0
};

void ReadMarks(int &Mark1, int &Mark2, int &Mark3)
{
    cout << "Enter Mark 1 :\n";
    cin >> Mark1;
    cout << "Enter Mark 2 :\n";
    cin >> Mark2;
    cout << "Enter Mark 3 :\n";
    cin >> Mark3;
}

int SumOf3Marks(int Mark1, int Mark2, int Mark3)
{
    return Mark1 + Mark2 + Mark3;
}

float CalculateAverage(int Mark1, int Mark2, int Mark3)
{
    return (float)SumOf3Marks(Mark1, Mark2, Mark3) / 3;
}

enPassFail CheckAverage(float Average)
{
    if(Average>=50)
    {
        return enPassFail::Pass;

    }
    else
    return enPassFail::Fail;

}

void PrintResults(float Average)
{
    cout << " The Average = " << Average << endl;

    if(CheckAverage(Average)==enPassFail::Pass)
    {
        cout<<"You Passed .\n";

    }
    else 
    cout<<"You Failed .\n";
}

int main()
{
    int Mark1, Mark2, Mark3;
    ReadMarks(Mark1, Mark2, Mark3);
    PrintResults(CalculateAverage(Mark1, Mark2, Mark3));
}