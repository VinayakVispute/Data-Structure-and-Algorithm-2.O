#include <iostream>
#include <algorithm>
#include "circularLinkedList.cpp"
using namespace std;
void printa(Node *&Head)
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
bool isCircularLL(Node *Tail)
{
    if (Tail == NULL)
    {
        return true;
    }
    Node *iterator = Tail->next;

    while (iterator != NULL && iterator != Tail)
    {
        iterator = iterator->next;
    }

    if (iterator == Tail)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    Node *Tail = NULL;
    insertNode(Tail, 0, 1);
    Tail->next = NULL;
    // insertNode(Tail, 1, 2);
    // insertNode(Tail, 2, 3);
    // insertNode(Tail, 3, 4);
    // insertNode(Tail, 4, 5);

    // insertNode(Tail, 5, 6);
    cout << endl;
    isCircularLL(Tail) ? cout << "True" : cout << "False";
}