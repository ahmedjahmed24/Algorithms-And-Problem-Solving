#include <iostream>
#include "clsDynamicArray.h"
using namespace std;

int main()
{
    clsDynamicArray<int> MyDynamicArray(5);

    MyDynamicArray.SetItem(0, 10);
    MyDynamicArray.SetItem(1, 20);
    MyDynamicArray.SetItem(2, 30);
    MyDynamicArray.SetItem(3, 40);
    MyDynamicArray.SetItem(4, 50);

    cout << "\nIs Empty ? " << MyDynamicArray.IsEmpty() << endl;
    cout << "\nSize = " << MyDynamicArray.Size() << endl;

    cout << "\n\nArray Items :\n";
    MyDynamicArray.PrintList();

    MyDynamicArray.InsertAtBeginning(400);
    cout << "\n\nArray after inserting 400 at beginning :\n";
    MyDynamicArray.PrintList();
    cout << "\nArray Size : " << MyDynamicArray.Size() << endl;

    MyDynamicArray.InsertBefore(2, 500);
    cout << "\n\nArray after inserting 500 before Index 2 :\n";
    MyDynamicArray.PrintList();
    cout << "\nArray Size : " << MyDynamicArray.Size() << endl;

    MyDynamicArray.InsertAfter(2, 600);
    cout << "\n\nArray after inserting 600 after Index 2 :\n";
    MyDynamicArray.PrintList();
    cout << "\nArray Size : " << MyDynamicArray.Size() << endl;

    MyDynamicArray.InsertAtEnd(800);

    cout << "\n\nArray after inserting 800 at end :\n";
    MyDynamicArray.PrintList();
    cout << "\nArray Size : " << MyDynamicArray.Size() << endl;

    return 0;
}