#include <iostream>
#include <algorithm>
#include "singlyLinkedList.cpp"
using namespace std;

Node *reverseKNodes(Node *Head, int noOfKNodes)
{
    if (Head == NULL)
    {
        return NULL;
    }

    Node *curr = Head;
    Node *prev = NULL;
    Node *nextNode = NULL;
    int cnt = 0;
    while (curr != NULL && cnt < noOfKNodes)
    {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
        cnt++;
    }

    if (nextNode != NULL)
    {
        Head->next = reverseKNodes(nextNode, noOfKNodes);
    }

    return prev;
}

int main()
{
    Node *n = new Node(6);
    Node *Head = n;
    insertAtHead(5, Head);
    insertAtHead(4, Head);
    insertAtHead(3, Head);
    insertAtHead(8, Head);
    insertAtHead(9, Head);
    print(Head);
    cout << endl
         << "Enter Number of Nodes to Be Operate : ";
    int noOfKNodes;
    cin >> noOfKNodes;
    cout << endl;
    Node *newHead = reverseKNodes(Head, noOfKNodes);
    print(newHead);
}