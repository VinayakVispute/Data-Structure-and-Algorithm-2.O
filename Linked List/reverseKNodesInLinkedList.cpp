#include <iostream>
#include <algorithm>
#include "singlyLinkedList.cpp"
using namespace std;

Node *reverseKNode(Node *Head, int kNodes)
{
    if (Head == NULL)
    {
        // cout << "\nreturned ";
        return Head;
    }

    Node *curr = Head;
    Node *prev = NULL;
    Node *nextNode = NULL;
    int cnt = 0;
    // for (int i = 0; i < kNodes; i++)
    cout << endl;
    // print(Head);
    // cout << endl
    //  << cnt << " " << kNodes << " " << curr->data << " " << curr->next->data << endl;
    // bool isCondition = (cnt < kNodes && curr->next != NULL);
    // cout << endl
    //  << isCondition << endl;
    while (cnt < kNodes && curr != NULL)
    {
        // cout << endl
        //  << cnt << " times"
        //  << " " << isCondition;

        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
        // cout << endl
        //  << prev->data << " " << curr->data << " " << nextNode->data << " " << endl;
        cnt++;
    }

    // cout << "ok";
    if (nextNode != NULL)
    {
        Node *chotaHead = reverseKNode(curr, kNodes);
        Head->next = chotaHead;
    }
    return prev;
}

int main()
{
    int a;
    cout << "Enter the Last Number of Linked LIst :";
    cin >> a;
    Node *n = new Node(a);
    Node *Head = n;
    cout << endl
         << "Enter the lenght of NOde :" << endl;
    int no;
    cin >> no;

    cout << endl;
    for (int i = 0; i < (no - 1); i++)
    {
        int b;
        cin >> b;
        insertAtHead(b, Head);
    }
    print(Head);
    cout << endl
         << "Enter the KNodes :";
    int kNodes;
    cin >> kNodes;
    Node *newHead = reverseKNode(Head, kNodes);
    cout << endl
         << "SOlution is : " << endl;
    print(newHead);
}