#include <iostream>
#include <algorithm>
#include "singlyLinkedList.cpp"
using namespace std;

void makeCycle(Node *Head, Node *Tail, int position)
{
    Node *iterator = Head;
    for (int i = 0; i < (position - 1); i++)
    {
        iterator = iterator->next;
    }
    Tail->next = iterator;
}

Node *detectCycle(Node *Head)
{

    if (Head == NULL)
    {
        return NULL;
    }
    Node *faster = Head;
    Node *slower = Head;

    while (faster->next != NULL)
    {

        if (faster->next->next == NULL)
        {
            return NULL;
        }
        faster = faster->next->next;
        slower = slower->next;
        if (faster == slower)
        {
            return slower;
        }
    }
}
Node *startingNodeLL(Node *Head)
{
    if (Head == NULL)
    {
        return Head;
    }

    Node *faster = detectCycle(Head);
    Node *slower = Head;
    while (slower != faster)
    {
        slower = slower->next;
        faster = faster->next;
    }
    return faster;
}
void removeCycle(Node *Head)
{
    if (Head == NULL)
    {
        return;
    }

    Node *startNode = startingNodeLL(Head);
    Node *iterator = startNode;

    while (iterator->next != startNode)
    {
        iterator = iterator->next;
    }
    iterator->next = NULL;
}

int main()
{
    Node *n = new Node(893);
    Node *Head = n;
    Node *Tail = n;
    cout << endl
         << "Enter the Size : ";
    int size;
    cin >> size;
    cout << endl
         << "Enter the Linked List: " << endl;
    for (int i = 0; i < (size - 1); i++)
    {
        int a;
        cin >> a;
        insertAtTail(a, Tail);
    }
    cout << endl
         << "Enter the Position for Cycle: ";
    int pos;
    cin >> pos;
    makeCycle(Head, Tail, pos);
    cout << endl;
    (detectCycle(Head) != NULL) ? cout << "True" : cout << "False";

    Node *startingNode = startingNodeLL(Head);
    cout << endl
         << "Starting NOde of Cycle in Linked List is : " << startingNode->data << endl
         << endl;
    removeCycle(Head);
    print(Head);
}