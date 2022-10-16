#include <iostream>
#include <algorithm>
#include <vector>
#include "singlyLinkedList.cpp"
using namespace std;

Node *middleNode(Node *Head)
{
    Node *slow = Head;
    Node *fast = Head->next;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}
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

bool isPalidrome(Node *Head)
{
    if (Head->next == NULL)
    {
        return true;
    }
    // Step 1-> Find Middle Node
    Node *middleElement = middleNode(Head);

    // Step 2-> Reverse List afer middle Node

    Node *temp = middleElement->next;
    middleElement->next = reverseLinkedList(temp);

    // Step 3 - Compare Both Halfs

    Node *Head1 = Head;
    Node *Head2 = middleElement->next;

    while (Head2 != NULL)
    {
        if (Head1->data != Head2->data)
        {
            return false;
        }
        else
        {
            Head1 = Head1->next;
            Head2 = Head2->next;
        }
    }

    // Step 4 : Repeat Step 2
    temp = middleElement->next;
    middleElement->next = reverseLinkedList(temp);
    return true;
}
int main()
{
    Node *n = new Node(1);
    Node *Head = n;
    Node *Tail = n;
    insertAtTail(2, Tail);
    insertAtTail(3, Tail);
    insertAtTail(3, Tail);
    insertAtTail(1, Tail);
    print(Head);
    cout << endl;
    isPalidrome(Head) ? cout << "True" : cout << "False";
}