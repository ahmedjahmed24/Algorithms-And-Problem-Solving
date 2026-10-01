#include <iostream>
using namespace std;

float ReadNumbers(string Message)
{
    float Number;

    cout << Message << endl;
    cin >> Number;

    return Number;
}

float SumNumbers()
{
    int Sum = 0, Number = 0, Counter = 1;

    do
    {
        Number = ReadNumbers("Enter Number " + to_string(Counter));

        if (Number == -99)
        {
            break;
        }
        
            Sum += Number;
            Counter++;
    } while (Number != -99);

    return Sum;
}

int main()
{
    cout << "Result = " << SumNumbers()<<endl;

    return 0;
}