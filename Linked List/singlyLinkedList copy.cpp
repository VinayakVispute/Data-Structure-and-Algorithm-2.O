#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
    ~Node()
    {
        int value = this->data;

        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << endl
             << "Memory is free for node with data " << value << endl;
    }
};
void insertAtHead(int val, Node *&Head)
{
    Node *temp = new Node(val);
    temp->next = Head;
    Head = temp;
}

void print(Node *&Head)
{
    Node *temp;

    temp = Head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insertAtTail(int val, Node *&Tail)
{
    Node *temp = new Node(val);

    Tail->next = temp;
    Tail = temp;
}

void insertAtMidde(int val, int position, Node *&Head, Node *&Tail)
{
    if (position == 1)
    {
        insertAtHead(val, Head);
        return;
    }
    else
    {
        Node *iterator = Head;
        Node *temp = new Node(val);
        for (int i = 1; i < (position - 1); i++)
        {
            iterator = iterator->next;
        }

        // Little Different from Code Help with Babbar
        if (iterator == Tail)
        {
            insertAtTail(val, Tail);
            return;
        }
        temp->next = iterator->next;
        iterator->next = temp;
    }
}
void deleteAtPosition(Node *&Head, Node *&Tail, int position)
{
    Node *iterator = Head;
    if (position == 1)
    {
        Head = Head->next;
        delete iterator;
        return;
    }
    int cnt = 1;
    Node *prev = NULL;
    while (cnt < position)
    {
        prev = iterator;
        iterator = iterator->next;
        cnt++;
    }
    if (iterator->next == NULL)
    {
        Tail = prev;
    }
    prev->next = iterator->next;
    delete iterator;
}

int main()
{
    Node *n = new Node(5);
    Node *Head = n;
    Node *Tail = n;
    insertAtHead(4, Head);
    // print(Head);
    insertAtHead(2, Head);
    // print(Head);
    insertAtHead(1, Head);
    // print(Head);
    insertAtTail(7, Tail);
    // print(Head);
    insertAtMidde(3, 3, Head, Tail);
    // print(Head);
    insertAtMidde(8, 7, Head, Tail);
    // print(Head);
    insertAtMidde(-1, 1, Head, Tail);
    // print(Head);
    insertAtMidde(0, 0, Head, Tail);
    print(Head); //
    int a;
    cin >> a;
    deleteAtPosition(Head, Tail, a);
    print(Head);
    cout << endl
         << "==> " << Head->data << " " << Tail->data << " ";
}