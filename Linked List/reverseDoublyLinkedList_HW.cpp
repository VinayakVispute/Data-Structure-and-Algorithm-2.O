#include <iostream>
#include <algorithm>
#include "doublyLinkedList.cpp"
using namespace std;

void reverseLinkList(Node *&Head, Node *&Tail)
{
    Node *curr = Head;
    Node *nextNode = NULL;
    Node *prev = NULL;
    Tail = Head;
    while (curr != NULL)
    {
        nextNode = curr->next;
        curr->next = prev;
        curr->previous = nextNode;
        prev = curr;
        curr = nextNode;
    }
    Head = prev;
}

int main()
{
    Node *n = new Node(5);
    Node *Head = n;
    Node *Tail = n;

    insertAtHead(Head, Tail, 4);
    insertAtHead(Head, Tail, 3);
    insertAtHead(Head, Tail, 2);
    insertAtHead(Head, Tail, 1);
    print(Head);
    reversePrint(Tail);
    reverseLinkList(Head, Tail);
    print(Head);
    reversePrint(Tail);
}