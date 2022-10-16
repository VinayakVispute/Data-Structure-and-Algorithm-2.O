#include <iostream>
#include <algorithm>
#include "singlyLinkedList.cpp"
using namespace std;
 By Vinayak Vispute
void removeDuplicate(Node *Head)
{
    if (Head == NULL)
    {
        return;
    }

    Node *curr = Head->next;
    Node *prev = Head;
    Node *nextNode = NULL;
    while (curr != NULL)
    {
        nextNode = curr->next;
        if ((curr->data) == (prev->data))
        {
            curr->next = NULL;
            delete curr;
        }
        else
        {
            prev->next = curr;
            prev = curr;
        }
        curr = nextNode;
    }
    prev->next = curr;
}

//Code of Babber

// Node *removeDuplicate(Node *Head)
// {

//     if (Head == NULL)
//     {
//         return NULL;
//     }

//     Node *curr = Head;

//     while (curr != NULL)
//     {
//         if ((curr->next != NULL) && (curr->data == curr->next->data))
//         {

//             Node *nextNode = curr->next->next;
//             Node *nodeToDelete = curr->next;
//             delete (nodeToDelete);
//             curr->next = nextNode;
//         }
//         else
//         {
//             curr = curr->next;
//         }
//     }
//     return Head;
// }

int main()
{

    Node *n = new Node(1);
    Node *Tail = n;
    Node *Head = n;
    insertAtTail(1, Tail);
    insertAtTail(1, Tail);
    insertAtTail(1, Tail);
    insertAtTail(1, Tail);
    insertAtTail(2, Tail);
    insertAtTail(2, Tail);
    insertAtTail(2, Tail);
    insertAtTail(2, Tail);
    insertAtTail(3, Tail);
    insertAtTail(3, Tail);
    print(Head);
    // removeDuplicate(Head);
    print(Head);
}