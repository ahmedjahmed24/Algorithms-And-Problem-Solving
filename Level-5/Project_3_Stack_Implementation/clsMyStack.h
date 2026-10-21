#pragma once

#include <iostream>
#include "clsMyQueue.h"
using namespace std;

template <class T>
class clsMyStack : public clsMyQueue<T>
{
private:
public:
    void push(T Value)
    {
        clsMyQueue<T>::InsertAtFront(Value);
        //clsMyQueue<T>::_MyList.InsertAtBeginning(Value);
    }

    T Top()
    {
        return clsMyQueue<T>::front();
    }

    T Bottom()
    {
        return clsMyQueue<T>::back();
    }
};