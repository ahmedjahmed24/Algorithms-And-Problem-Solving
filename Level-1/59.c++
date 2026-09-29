#include<iostream>
using namespace std;

class YT 
{
    public:
    string name;
    void print(YT ob)
    {
        cout<<"name is "<<ob.name<<endl;

    }
};

int main()
{
    YT ob1;
    YT ob2;

    ob1.name="et3allambbasata";
    ob2.name="ahmed";

    ob1.print(ob2); //name is ahmed
    ob2.print(ob1);//name is et3allambbasata

}