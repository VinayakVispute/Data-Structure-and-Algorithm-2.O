#include "singlyLinkedList.cpp"
#include <iostream>
using namespace std;

// This code is only for Linked with only Head
Node *reverseLink(Node *&Head)
{
    Node *curr = Head;
    Node *prev = NULL;
    Node *nextNode = NULL;
    if (Head == NULL || Head->next == NULL)
    {
        return Head;
    }
    while (curr != NULL)
    {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
} 

int main()
{
    Node *n = new Node(6);
    Node *Head = n;
    Node *Tail = n;
    insertAtHead(5, Head);
    insertAtHead(4, Head);
    insertAtHead(3, Head);
    insertAtHead(2, Head);
    insertAtHead(1, Head);
    print(Head);
    Head = reverseLink(Head);
    print(Head);
}