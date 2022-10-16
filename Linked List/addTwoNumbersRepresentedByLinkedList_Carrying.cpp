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

Node *add(Node *Head1, Node *Head2)
{
    int carry = 0;
    Node *ansHead = NULL;
    Node *ansTail = NULL;
    while (Head1 != NULL && Head2 != NULL)
    {
        int ans = (Head1->data) + (Head2->data) + carry;
        int digit = ans % 10;
        insertAtTail(digit, ansHead, ansTail);
        carry = ans / 10;

        Head1 = Head1->next;
        Head2 = Head2->next;
    }
    while (Head1 != NULL)
    {
        int ans = carry + Head1->data;
        int digit = ans % 10;
        insertAtTail(digit, ansHead, ansTail);
        carry = ans / 10;
        Head1 = Head1->next;
    }
    while (Head2 != NULL)
    {
        int ans = carry + Head2->data;
        int digit = ans % 10;
        insertAtTail(digit, ansHead, ansTail);
        carry = ans / 10;
        Head2 = Head2->next;
    }

    while (carry != 0)
    {
        int ans = carry;
        int digit = ans % 10;
        insertAtTail(digit, ansHead, ansTail);
        carry = ans / 10;
    }
    return ansHead;
}

// Generic Code
Node *add(Node *Head1, Node *Head2)
{
    int carry = 0;
    Node *ansHead = NULL;
    Node *ansTail = NULL;
    while (Head1 != NULL || Head2 != NULL || carry != 0)
    {
        int val1 = 0;
        if (Head1 != NULL)
        {
            val1 = Head1->data;
        }
        int val1 = 0;
        if (Head2 != NULL)
        {
            val2 = Head2->data;
        }
        int ans = carry + val1 + val2;
        int digits = val % 10;
        insertAtTail(digits, ansHead, ansTail);
        carry = ans / 10;
        if (Head1 != NULL)
        {
            Head1 = Head1->next;
        }
        if (Head2 != NULL)
        {
            Head2 = Head2->next;
        }
    }
    return ansHead;
}
Node *solution(Node *Head1, Node *Head2)
{
    // Step 1 : Reverse Both Linked List
    Head1 = reverseLinkedList(Head1);
    Head2 = reverseLinkedList(Head2);

    // Step 2: Add Both Linked List
    Node *ans = add(Head1, Head2);

    // step 3: Revese the answer and return the answer
    return reverseLinkedList(ans);
}

int main()
{
    Node *n1 = NULL;
    Node *Head1 = n1;
    Node *Tail1 = n1;
    Node *n2 = NULL;
    Node *Head2 = n2;
    Node *Tail2 = n2;

    cout << endl
         << "Enter the Numbers of Digits in First Number: ";
    int no1;
    cin >> no1;

    cout << endl
         << "Now Enter the Numbers : ";
    for (int i = 0; i < no1; i++)
    {
        int a;
        cin >> a;
        insertAtTail(a, Head1, Tail1);
    }
    cout << endl
         << "Enter the Numbers of Digits in First Number: ";
    int no2;
    cin >> no2;
    cout << endl
         << "Now Enter the Numbers : ";
    for (int i = 0; i < no2; i++)
    {
        int a;
        cin >> a;
        insertAtTail(a, Head2, Tail2);
    }

    cout << endl
         << "First Number : ";

    print(Head1);
    cout << endl
         << "Second Number : ";
    print(Head2);
    Node *sol = solution(Head1, Head2);
    print(sol);
}