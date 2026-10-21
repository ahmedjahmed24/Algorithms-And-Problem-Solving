// #pragma once

// #include <iostream>
// #include <stack>
// using namespace std;

// class clsMyString
// {
// private:
//     stack<string> _MyStack;
//     stack<string> _History;

// public:
//     clsMyString(string Value = " ")
//     {
//         _MyStack.push(Value);
//     }

//     void SetValue(string Value)
//     {
//         _MyStack.push(Value);
//     }

//     string Value()
//     {
//         return _MyStack.top();
//     }

//     void Undo()
//     {
//         _History.push(_MyStack.top());
//         _MyStack.pop();
//     }

//     string Redo()
//     {
//         _MyStack.push(_History.top());
//         _History.pop();
//     }
// };

#pragma once

#include <iostream>
#include <stack>
using namespace std;

class clsMyString
{
private:
    stack<string> _Undo;
    stack<string> _Redo;
    string _Value = "";

public:
    void SetValue(string Value)
    {
        _Undo.push(_Value);
        _Value = Value;
    }

    string Value()
    {
        return _Value;
    }

    void Undo()
    {
        if (!_Undo.empty())
        {
            _Redo.push(_Value);
            _Value = _Undo.top();
            _Undo.pop();
        }
    }

    void Redo()
    {
        if (!_Redo.empty())
        {
            _Undo.push(_Value);
            _Value = _Redo.top();
            _Redo.pop();
        }
    }
};