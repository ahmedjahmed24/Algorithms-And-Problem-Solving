#include <iostream>
#include "clsMyQueueArr.h"
using namespace std;

int main()
{
    clsMyQueueArr<int> MyQueue;

    MyQueue.push(10);
    MyQueue.push(20);
    MyQueue.push(30);
    MyQueue.push(40);
    MyQueue.push(50);

    cout << "\nQueue :\n";
    MyQueue.Print();

    cout << "\n\nQueue Size : " << MyQueue.Size();
    cout << "\nQueue Front : " << MyQueue.front();
    cout << "\nQueue Back : " << MyQueue.back();

    MyQueue.pop();
    cout << "\n\nQueue after pop :\n";
    MyQueue.Print();

    // Extension #1
    cout << "\n\nItem(2) : " << MyQueue.GetItem(2);

    // Extension #2
    MyQueue.Reverse();
    cout << "\n\nQueue after Reverse() :\n";
    MyQueue.Print();

    // Extension #3
    MyQueue.UpdateItem(2, 600);
    cout << "\n\nQueue after Updating Item(2) to 600 :\n";
    MyQueue.Print();

    // Extension #4
    MyQueue.InsertAfter(2, 800);
    cout << "\n\nQueue after Inserting 800 after Item(2) :\n";
    MyQueue.Print();

    // Extension #5
    MyQueue.InsertAtFront(1000);
    cout << "\n\nQueue after Inserting 1000 at Front :\n";
    MyQueue.Print();

    // Extension #6
    MyQueue.InsertAtBack(2000);
    cout << "\n\nQueue after Inserting 2000 at Back :\n";
    MyQueue.Print();

    // Extension #7
    MyQueue.Clear();
    cout << "\n\nQueue after Clear() :\n";
    MyQueue.Print();
}