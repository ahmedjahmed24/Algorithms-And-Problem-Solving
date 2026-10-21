#include <iostream>
#include "clsMyStackArr.h"
using namespace std;

int main()
{
    clsMyStackArr<int> MyStackArr;

    MyStackArr.push(10);
    MyStackArr.push(20);
    MyStackArr.push(30);
    MyStackArr.push(40);
    MyStackArr.push(50);

    cout << "\nStack :\n";
    MyStackArr.Print();

    cout << "\n\nStack Size : " << MyStackArr.Size();
    cout << "\nStack Top : " << MyStackArr.Top();
    cout << "\nStack Bottom : " << MyStackArr.Bottom();

    MyStackArr.pop();
    cout << "\n\nStack after pop :\n";
    MyStackArr.Print();

    // Extension #1
    cout << "\n\nItem(2) : " << MyStackArr.GetItem(2);

    // Extension #2
    MyStackArr.Reverse();
    cout << "\n\nStack after Reverse() :\n";
    MyStackArr.Print();

    // Extension #3
    MyStackArr.UpdateItem(2, 600);
    cout << "\n\nStack after Updating Item(2) to 600 :\n";
    MyStackArr.Print();

    // Extension #4
    MyStackArr.InsertAfter(2, 800);
    cout << "\n\nStack after Inserting 800 after Item(2) :\n";
    MyStackArr.Print();

    // Extension #5
    MyStackArr.InsertAtFront(1000);
    cout << "\n\nStack after Inserting 1000 at Front :\n";
    MyStackArr.Print();

    // Extension #6
    MyStackArr.InsertAtBack(2000);
    cout << "\n\nStack after Inserting 2000 at Back :\n";
    MyStackArr.Print();

    // Extension #7
    MyStackArr.Clear();
    cout << "\n\nStack after Clear() :\n";
    MyStackArr.Print();
}