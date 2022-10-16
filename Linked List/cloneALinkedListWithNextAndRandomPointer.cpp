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

void print(Node *head)
{
    cout << head->val << "("
         << head->random->val << ")";
    head = head->next;
    while (head != NULL)
    {
        cout << " -> " << head << "("
             << head->random  << ")";
        head = head->next;
    }
    cout << endl;
}
// Function to clone the linked list
Node *cloneLinkedList(Node *Head)
{
    Node *iterator = Head;
    Node *HeadSoln = NULL;
    Node *TailSoln = NULL;
    while (iterator != NULL)
    {
        insertAtTail(iterator->val, HeadSoln, TailSoln);
        iterator = iterator->next;
    }

    unordered_map<Node *, Node *> mapping;

    iterator = Head;
    Node *iteratorSoln = HeadSoln;
    while (iterator != NULL)
    {
        mapping[iterator] = iteratorSoln;
        iterator = iterator->next;
        iteratorSoln = iteratorSoln->next;
    }

    iteratorSoln = HeadSoln;
    iterator = Head;
    while (iterator != NULL)
    {
        iteratorSoln->random = mapping[iterator->random];
        iterator = iterator->next;
        iteratorSoln = iteratorSoln->next;
    }

    return HeadSoln;
}

// Driver code
int main()
{
    // Creating a linked list with random pointer
    Node *head = new Node(9);
    head->next = new Node(8);
    head->next->next = new Node(4);
    head->next->next->next = new Node(99);
    head->next->next->next->next = new Node(52);
    head->random = head->next->next;
    head->next->random = head;
    head->next->next->random = head->next->next->next->next;
    head->next->next->next->random = head->next->next;
    head->next->next->next->next->random = head->next;

    // Print the original list
    cout << "The original linked list:\n";
    print(head);

    Node *sol = cloneLinkedList(head);

    cout << "The cloned linked list:\n";
    print(sol);

    return 0;
}
