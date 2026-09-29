#include<iostream>
using namespace std;

int ReadAge()
{
    int Age;

    cout<<"Enter Age Between 18 and 45 :\n";
    cin>>Age;

    return Age;
}

int ValidateNumberInRange(int Number,int From,int To)
{
    return (Number>=From && Number<=To);
}

void PrintResult(int Age)
{
    if(ValidateNumberInRange(Age, 18, 45)==true)
    {
        cout<<"The Age is Valid";
    }
    else
    cout<<"The Age is Invalid";
}

int main()
{
    PrintResult(ReadAge());

}