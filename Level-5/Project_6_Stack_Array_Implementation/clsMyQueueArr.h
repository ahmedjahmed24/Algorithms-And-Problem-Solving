#pragma once

#include <iostream>
#include "clsDynamicArray.h"
using namespace std;

template <class T>
class clsMyQueueArr
{
protected:
    clsDynamicArray<T> _MyQueueArr;

public:
    clsMyQueueArr()
    {
    }

    void push(T Value)
    {
        _MyQueueArr.InsertAtEnd(Value);
    }

    int Size()
    {
        return _MyQueueArr.Size();
    }

    bool IsEmpty()
    {
        return _MyQueueArr.IsEmpty();
    }

    T front()
    {
        return _MyQueueArr.GetItem(0);
    }

    T back()
    {
        return _MyQueueArr.GetItem(_MyQueueArr.Size() - 1);
    }

    void pop()
    {
        _MyQueueArr.DeleteFirstItem();
    }

    T GetItem(int Index)
    {
        return _MyQueueArr.GetItem(Index);
    }

    void Reverse()
    {
        _MyQueueArr.Reverse();
    }

    void UpdateItem(int Index, T Value)
    {
        _MyQueueArr.SetItem(Index, Value);
    }

    void InsertAfter(int Index, T Value)
    {
        _MyQueueArr.InsertAfter(Index, Value);
    }

    void InsertAtFront(T Value)
    {
        _MyQueueArr.InsertAtBeginning(Value);
    }

    void InsertAtBack(T Value)
    {
        _MyQueueArr.InsertAtEnd(Value);
    }

    void Clear()
    {
        _MyQueueArr.Clear();
    }

    void Print()
    {
        _MyQueueArr.PrintList();
    }
};