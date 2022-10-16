// C++ code to implement the approach

#include <bits/stdc++.h>
#include <map>
using namespace std;

// Structure of a node of linked list

struct Node
{
    int val;
    Node *next;
    Node *random;

    // Constructor
    Node(int x)
    {
        this->val = x;
        this->next = NULL;
        this->random = NULL;
    }
};

void insertAtTail(int val, Node *&Head, Node *&Tail)
{
    Node *temp = new Node(val);
    if (Head == NULL)
    {
        Head = temp;
        Tail = temp;
        return;
    }

    Tail->next = temp;
    Tail = temp;
}

// void print(Node *&Head)
// {
//     Node *temp;

//     temp = Head;
//     while (temp != NULL)
//     {
//         cout << temp->val << " ";
//         temp = temp->next;
//     }
//     cout << endl;
// }
void print(Node *head)
{
    cout << head->val << "("
         << head->random->val << ")";
    head = head->next;
    while (head != NULL)
    {
        cout << " -> " << head->val << "("
             << head->random->val << ")";
        head = head->next;
    }
    cout << endl;
}
// Function to clone the linked list
Node *cloneLinkedList(Node *Head)
{
    Node *iterator = Head;
    Node *cloneHead = NULL;
    Node *cloneTail = NULL;
    print(Head);
    while (iterator != NULL)
    {
        insertAtTail(iterator->val, cloneHead, cloneTail);
        iterator = iterator->next;
    }
    iterator = Head;
    Node *iteratorSoln = cloneHead;
    Node *nextItr = NULL;
    while (iterator != NULL)
    {
        nextItr = iterator->next;
        iterator->next = iteratorSoln;
        iterator = nextItr;
        nextItr = iteratorSoln->next;
        iteratorSoln->next = iterator;
        iteratorSoln = nextItr;
    }

    iterator = Head;
    while (iterator != NULL)
    {
        if (iterator->next != NULL)
        {
            iterator->next->random = iterator->random ? iterator->random->next : iterator->random;
        }

        iterator = iterator->next->next;
    }
    iterator = Head;
    iteratorSoln = cloneHead;
    while (iterator != NULL && iteratorSoln != NULL)
    {
        iterator->next = iteratorSoln->next;
        iterator = iterator->next;
        if (iterator != NULL)
        {
            iteratorSoln->next = iterator->next;
        }
        iteratorSoln = iteratorSoln->next;
    }

    return cloneHead;
}
// Driver code
int main()
{
    // Creating a linked list with random pointer
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->random = head->next->next;
    head->next->random = head;
    head->next->next->random = head->next->next->next->next;
    head->next->next->next->random = head->next->next;
    head->next->next->next->next->random = head->next;

    // Print the original list
    cout << "The original linked list:\n";
    print(head);

    cloneLinkedList(head);

    cout << "The cloned linked list:\n";
    // print(sol);

    return 0;
}
