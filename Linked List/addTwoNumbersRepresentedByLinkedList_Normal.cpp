#include <iostream>
#include <algorithm>
#include "singlyLinkedList.cpp"
using namespace std;
Node *reverseLinkedList(Node *Head)
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
Node *addLinkedList(Node *Head1, Node *Head2)
{
    Node *temp1 = reverseLinkedList(Head1);
    Node *temp2 = reverseLinkedList(Head2);
    Node *solution = NULL;
    Node *HeadS = NULL, *TailS = NULL;
    while (temp1 != NULL && temp2 != NULL)
    {
        int ans = temp1->data + temp2->data;
        insertAtTail(ans, HeadS, TailS);
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    while (temp1 != NULL)
    {
        int ans = temp1->data;
        insertAtTail(ans, HeadS, TailS);
        temp1 = temp1->next;
    }

    while (temp2 != NULL)
    {
        int ans = temp2->data;
        insertAtTail(ans, HeadS, TailS);
        temp2 = temp2->next;
    }
    return reverseLinkedList(HeadS);
}

int main()
{
    Node *n1 = new Node(1);
    Node *Head1 = n1;
    Node *Tail1 = n1;
    insertAtTail(2, Head1, Tail1);
    insertAtTail(3, Head1, Tail1);
    Node *n2 = new Node(1);
    Node *Head2 = n2;
    Node *Tail2 = n2;
    insertAtTail(2, Head2, Tail2);
    insertAtTail(2, Head2, Tail2);
    insertAtTail(2, Head2, Tail2);
    cout << endl
         << "First Number : ";
    print(Head1);
    cout << endl
         << "Second Number : ";
    print(Head2);
    Node *solution = addLinkedList(Head1, Head2);
    print(solution);
}