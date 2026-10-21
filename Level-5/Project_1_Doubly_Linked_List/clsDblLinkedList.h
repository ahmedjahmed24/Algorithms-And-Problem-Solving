#pragma once

#include <iostream>
using namespace std;

template <class T>
class clsDblLinkedList
{
protected:
    int _Size = 0;

public:
    class Node
    {
    public:
        T Value;
        Node *next;
        Node *prev;
    };

    Node *head = NULL;

    void InsertAtBeginning(T Value)
    {
        Node *new_node = new Node();

        new_node->Value = Value;
        new_node->prev = NULL;
        new_node->next = head;

        if (head != NULL)
        {
            head->prev = new_node;
        }

        head = new_node;
        _Size++;
    }

    Node *FindNode(T Value)
    {
        Node *Current = head;

        while (Current != NULL)
        {
            if (Current->Value == Value)
            {
                return Current;
            }
            Current = Current->next;
        }

        return NULL;
    }

    void InsertAfter(Node *PrevNode, T Value)
    {
        if (PrevNode == NULL)
        {
            cout << "\nThe Prev Node Cannot Be NULL !";
            return;
        }

        Node *new_node = new Node();

        new_node->Value = Value;
        new_node->prev = PrevNode;
        new_node->next = PrevNode->next;

        if (PrevNode->next != NULL)
        {
            PrevNode->next->prev = new_node;
        }

        PrevNode->next = new_node;
        _Size++;
    }

    void InsertAtEnd(T Value)
    {
        Node *new_node = new Node();

        new_node->Value = Value;
        new_node->next = NULL;

        if (head == NULL)
        {
            new_node->prev = NULL;
            head = new_node;
            _Size++;
            return;
        }

        Node *LastNode = head;
        while (LastNode->next != NULL)
        {
            LastNode = LastNode->next;
        }

        new_node->prev = LastNode;
        LastNode->next = new_node;

        _Size++;
    }

    void DeleteNode(Node *&NodeToDelete)
    {
        if (head == NULL || NodeToDelete == NULL)
        {
            return;
        }

        if (head == NodeToDelete)
        {
            head = NodeToDelete->next;
            if (head != NULL)
            {
                head->prev = NULL;
            }
            delete NodeToDelete;
            NodeToDelete = NULL;
            _Size--;
            return;
        }

        if (NodeToDelete->next != NULL)
        {
            NodeToDelete->next->prev = NodeToDelete->prev;
        }

        if (NodeToDelete->prev != NULL)
        {
            NodeToDelete->prev->next = NodeToDelete->next;
        }

        delete NodeToDelete;
        NodeToDelete = NULL;
        _Size--;
    }

    void DeleteFirstNode()
    {
        if (head == NULL)
        {
            return;
        }

        Node *temp = head;
        head = head->next;

        if (head != NULL)
        {
            head->prev = NULL;
        }

        delete temp;
        _Size--;
    }

    void DeleteLastNode()
    {
        if (head == NULL)
        {
            return;
        }

        if (head->next == NULL)
        {
            delete head;
            head = NULL;
            _Size--;
            return;
        }

        Node *Current = head;
        while (Current->next->next != NULL)
        {
            Current = Current->next;
        }

        Node *temp = Current->next;
        Current->next = NULL;
        delete temp;
        _Size--;
    }

    int Size()
    {
        return _Size;
    }

    bool IsEmpty()
    {
        return (_Size == 0);
    }

    void Clear()
    {
        while (_Size > 0)
        {
            DeleteFirstNode();
        }
    }

    void Reverse()
    {
        Node *Current = head;
        Node *temp = nullptr;

        while (Current != NULL)
        {
            temp = Current->prev;
            Current->prev = Current->next;
            Current->next = temp;

            Current = Current->prev;
        }

        if (temp != nullptr)
        {
            head = temp->prev;
        }
    }

    Node *GetNode(int Index)
    {
        if (Index < 0 || Index >= _Size)
        {
            return NULL;
        }

        Node *Current = head;
        int Counter = 0;

        while (Current != NULL)
        {
            if (Counter == Index)
            {
                return Current;
            }
            Current = Current->next;
            Counter++;
        }

        return NULL;
    }

    T GetItem(int Index)
    {
        Node *N = GetNode(Index);

        if (N == NULL)
        {
            return T();
        }
        else
            return N->Value;
    }

    bool UpdateItem(int Index, T NewValue)
    {
        Node *N1 = GetNode(Index);

        if (N1 != NULL)
        {
            N1->Value = NewValue;
            return true;
        }
        else
            return false;
    }

    bool InsertAfter(int Index, T NewValue)
    {
        Node *PrevNode = GetNode(Index);

        if (PrevNode != NULL)
        {
            InsertAfter(PrevNode, NewValue);
            return true;
        }
        else
            return false;
    }

    void PrintList()
    {
        Node *Current = head;

        while (Current != NULL)
        {
            cout << Current->Value << " ";
            Current = Current->next;
        }
        cout << "\n";
    }
};