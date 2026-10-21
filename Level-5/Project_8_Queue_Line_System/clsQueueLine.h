#pragma once

#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include "clsDate.h"

using namespace std;

class clsQueueLine
{
private:
    string _QueuePrefix = "";
    short _AverageServeTime = 0;
    short _TotalTickets = 0;

    class clsTicket
    {
    private:
        string _Prefix = "";
        short _Number = 0;
        short _WaitingClients = 0;
        string _TicketTime = "";
        short _AverageServeTime = 0;

    public:
        clsTicket(string Prefix, short Number, short AverageServeTime, short WaitingClients)
        {
            _Prefix = Prefix;
            _Number = Number;
            _AverageServeTime = AverageServeTime;
            _WaitingClients = WaitingClients;
            _TicketTime = clsDate::GetCurrentDateAndTime();
        }

        string FullNumber()
        {
            return _Prefix + to_string(_Number);
        }

        string Prefix()
        {
            return _Prefix;
        }

        short Number()
        {
            return _Number;
        }

        short AverageTimeToServe()
        {
            return _AverageServeTime;
        }

        short ExpectedTimeToServe()
        {
            return _AverageServeTime * _WaitingClients;
        }

        short WaitingClients()
        {
            return _WaitingClients;
        }

        void Print()
        {
            cout << "\n\t\t\t  _______________________\n";
            cout << "\n\t\t\t\t    " << FullNumber();
            cout << "\n\n\t\t\t    " << _TicketTime;
            cout << "\n\t\t\t    Waiting Clients = " << _WaitingClients;
            cout << "\n\t\t\t      Serve Time In";
            cout << "\n\t\t\t       " << ExpectedTimeToServe() << " Minutes.";
            cout << "\n\t\t\t  _______________________\n";
        }
    };

public:
    queue<clsTicket> QueueLine;

    clsQueueLine(string QueuePrefix, short AverageTimeToServe)
    {
        _QueuePrefix = QueuePrefix;
        _AverageServeTime = AverageTimeToServe;
        _TotalTickets = 0;
    }

    short WaitingClients()
    {
        return QueueLine.size();
    }

    void IssueTicket()
    {
        _TotalTickets++;
        clsTicket Ticket(_QueuePrefix, _TotalTickets, _AverageServeTime, WaitingClients());
        QueueLine.push(Ticket);
    }

    short ServedClients()
    {
        return _TotalTickets - WaitingClients();
    }

    void PrintInfo()
    {
        cout << "\n\t\t\t _________________________\n";
        cout << "\n\t\t\t\tQueue Info";
        cout << "\n\t\t\t _________________________\n";
        cout << "\n\t\t\t    Prefix          = " << _QueuePrefix;
        cout << "\n\t\t\t    Total Tickets   = " << _TotalTickets;
        cout << "\n\t\t\t    Served Clients  = " << ServedClients();
        cout << "\n\t\t\t    Waiting Clients = " << WaitingClients();
        cout << "\n\t\t\t _________________________\n\n";
    }

    void PrintTicketsLineRTL()
    {
        if (QueueLine.empty())
        {
            cout << "\n\t\tTickets: No Tickets.";
        }
        else
            cout << "\n\t\tTickets: ";

        queue<clsTicket> TempQueueLine = QueueLine;

        while (!TempQueueLine.empty())
        {
            cout << TempQueueLine.front().FullNumber() << " <-- ";
            TempQueueLine.pop();
        }

        cout << endl;
    }

    void PrintTicketsLineLTR()
    {
        if (QueueLine.empty())
        {
            cout << "\n\t\tTickets: No Tickets.";
        }
        else
            cout << "\n\t\tTickets: ";

        queue<clsTicket> TempQueueLine = QueueLine;
        stack<clsTicket> TempStackLine;

        while (!TempQueueLine.empty())
        {
            TempStackLine.push(TempQueueLine.front());
            TempQueueLine.pop();
        }

        while (!TempStackLine.empty())
        {
            cout << TempStackLine.top().FullNumber() << " --> ";
            TempStackLine.pop();
        }

        cout << endl;
    }

    void PrintAllTickets()
    {
        cout << "\n\n\t\t\t       ---Tickets---";

        if (QueueLine.empty())
            cout << "\n\n\t\t\t     ---No Tickets---\n";

        queue<clsTicket> TempQueue = QueueLine;

        while (!TempQueue.empty())
        {
            TempQueue.front().Print();
            TempQueue.pop();
        }

        cout << endl;
    }

    bool ServeNextClient()
    {
        if (QueueLine.empty())
        {
            return false;
        }

        QueueLine.pop();
        return true;
    }

    string WhoIsNext()
    {
        if (QueueLine.empty())
        {
            return "No Clients Left.";
        }

        return QueueLine.front().FullNumber();
    }
};