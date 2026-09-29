#include <iostream>
using namespace std;

int ReadAge()
{
    int Age;

    cout << "Enter Age Between 18 and 45 :\n";
    cin >> Age;

    return Age;
}

int ValidateNumberInRange(int Number, int From, int To)
{
    return (Number >= From && Number <= To);
}

int ReadUntilAgeBetween(int From, int To)
{
    int Age = 0;

    do
    {
        Age=ReadAge(); // خطاي كان يالاسناد الى ايج مااسندتا 

    } while (!ValidateNumberInRange(Age, 18, 45));

    return Age;
}

void PrintResult(int Age)
{
    cout << "Your Age is " << Age;
}

int main()
{
    PrintResult(ReadUntilAgeBetween(18, 45));
}