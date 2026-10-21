#pragma once

#include <iostream>
#include "clsMyQueueArr.h"
using namespace std;

template <class T>
class clsMyStackArr : public clsMyQueueArr<T>
{
protected:
    // sdfdsf

public:
    void push(T Item)
    {
        clsMyQueueArr<T>::InsertAtFront(Item);
    }

    T Top()
    {
        return clsMyQueueArr<T>::front();
    }

    T Bottom()
    {
        return clsMyQueueArr<T>::back();
    }
};