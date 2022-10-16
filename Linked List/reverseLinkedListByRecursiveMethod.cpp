#include <iostream>
#include <algorithm>
#include "singlyLinkedList.cpp"
using namespace std;

// This is only for List wit Head Only (2nd Code)
Node *returnReverse2nd(Node *Head)
{
    if (Head == NULL || Head->next == NULL)
    {
        return Head;
    }
    Node *chotaHead = returnReverse2nd(Head->next);
    Head->next->next = Head;
    Head->next = NULL;
    return chotaHead  ;
}
// This code is only for list with Head only  (1st Code)
Node *returnReverse(Node *curr, Node *prev)
{
    if (curr == NULL)
    {
        return prev;
    }
    Node *nextNode = curr->next;
    curr->next = prev;

    returnReverse(nextNode, curr);
}

Node *reverseList(Node *&Head)
{
    // For First Code
    /* if (Head == NULL || Head->next == NULL)
     {
         return Head;
     }
     Node *curr = Head;
     Node *prev = NULL;
     Node *nextNode = NULL;

     return returnReverse(curr, prev); */
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
    // Head = reverseList(Head);
    Head = returnReverse2nd(Head);
    print(Head);
}