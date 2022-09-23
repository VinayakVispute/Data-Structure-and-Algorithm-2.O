#include <iostream>
#include <algorithm>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *previous;

    Node(int val)
    {
        data = val;
        next = NULL;
        previous = NULL;
    }
    ~Node()
    {
        int val = this->data;
        if (next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << endl
             << "Memory is Freed for Value : " << val;
    }
};

void print(Node *&Head)
{
    Node *iterator = Head;
    cout << endl;
    while (iterator != NULL)
    {
        cout << iterator->data << " ";
        iterator = iterator->next;
    }
}
int getLength(Node *Head)
{
    int cnt = 0;
    Node *iterator = Head;
    while (iterator != NULL)
    {
        iterator = iterator->next;
        cnt++;
    }
    return cnt;
}

void insertAtHead(Node *&Head, Node *&Tail, int key)
{
    Node *temp = new Node(key);
    if (Head == NULL)
    {
        Head = temp;
        Tail = temp;
        return;
    }
    temp->next = Head;
    Head->previous = temp;
    Head = temp;
}

void insertAtTail(Node *&Head, Node *&Tail, int key)
{
    Node *temp = new Node(key);
    if (Head == NULL)
    {
        Head = temp;
        Tail = temp;
        return;
    }
    Tail->next = temp;
    temp->previous = Tail;
    Tail = temp;
}
void reversePrint(Node *&Tail)
{
    Node *iterator = Tail;
    cout << endl
         << "Reverse : ";
    while (iterator != NULL)
    {
        cout << iterator->data << " ";
        iterator = iterator->previous;
    }
}

void insert(Node *&Head, Node *&Tail, int key, int position)
{
    Node *temp = new Node(key);
    if (Head == NULL)
    {
        Head = temp;
        Tail = temp;
        return;
    }
    Node *iterator = Head;
    if (position == 1)
    {
        insertAtHead(Head, Tail, key);
        return;
    }
    for (int i = 1; i < (position - 1); i++)
    {
        iterator = iterator->next;
    }
    if (iterator == Tail)
    {
        insertAtTail(Head, Tail, key);
        return;
    }
    iterator->next->previous = temp;
    temp->next = iterator->next;
    iterator->next = temp;
    temp->previous = iterator;
}
void deleteAtPosition(Node *&Head, Node *&Tail, int position)
{
    Node *iterator = Head;
    if (position == 1)
    {
        Head = iterator->next;
        Head->previous = NULL;
        iterator->next = NULL;
        delete iterator;
        return;
    }
    else
    {
        int cnt = 1;
        Node *prev = NULL;
        while (cnt < position)
        {
            prev = iterator;
            iterator = iterator->next;
            cnt++;
        }
        iterator->previous = NULL;
        prev->next = iterator->next;
        if (iterator->next == NULL)
        {
            Tail = prev;
            delete iterator;
            return;
        }
        iterator->next->previous = prev;
        iterator->next = NULL;

        delete iterator;
    }
}


int main()
{
    // Node *n = new Node(5);
    Node *Head = NULL;
    Node *Tail = NULL;
    // print(Head);
    insertAtHead(Head, Tail, 4);
    // print(Head);
    insertAtHead(Head, Tail, 3);
    // print(Head);
    insertAtHead(Head, Tail, 2);
    // print(Head);
    insertAtHead(Head, Tail, 1);
    // print(Head);
    insertAtTail(Head, Tail, 6);
    // print(Head);
    insertAtTail(Head, Tail, 7);
    // print(Head);
    insert(Head, Tail, 5, 5);
    print(Head);
    int a;
    cin >> a;
    deleteAtPosition(Head, Tail, a);
    print(Head);
    reversePrint(Tail);
    cout << endl;
    cout << endl
         << " H==>" << Head->data << " T==>" << Tail->data;
}