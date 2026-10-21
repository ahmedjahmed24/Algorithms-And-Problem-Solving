#include<iostream>
#include"clsQueueLine.h"
using namespace std;

int main()
{
    // clsQueueLine PayBillsQueue("A0", 10);
    clsQueueLine SubscriptionsQueue("B0", 5);

    // PayBillsQueue.IssueTicket();
    // PayBillsQueue.IssueTicket();
    // PayBillsQueue.IssueTicket();
    // PayBillsQueue.IssueTicket();
    // PayBillsQueue.IssueTicket();

    SubscriptionsQueue.IssueTicket();
    SubscriptionsQueue.IssueTicket();
    SubscriptionsQueue.IssueTicket();
    SubscriptionsQueue.IssueTicket();

    // cout << "\nPay Bills Queue Info:\n";
    // PayBillsQueue.PrintInfo();

    cout << "\nSubscriptions Queue Info:\n";
    SubscriptionsQueue.PrintInfo();

    // PayBillsQueue.PrintTicketsLineRTL();
    // PayBillsQueue.PrintTicketsLineLTR();

    SubscriptionsQueue.PrintTicketsLineRTL();
    SubscriptionsQueue.PrintTicketsLineLTR();

    // PayBillsQueue.PrintAllTickets();
    SubscriptionsQueue.PrintAllTickets();

    // cout << "\n\nPay Bills Queue After Serving One Client :\n";
    // PayBillsQueue.ServeNextClient();
    // PayBillsQueue.PrintInfo();

    // cout << "\n\nPay Bills Queue After Serving One Client :\n";
    // PayBillsQueue.ServeNextClient();
    // PayBillsQueue.PrintInfo();

    cout << "\n\nSubscriptions Queue After Serving One Client :\n";
    SubscriptionsQueue.ServeNextClient();
    SubscriptionsQueue.PrintInfo();

    cout << "\n\nPay Bills Queue After Serving One Client :\n";
    SubscriptionsQueue.ServeNextClient();
    SubscriptionsQueue.PrintInfo();
}