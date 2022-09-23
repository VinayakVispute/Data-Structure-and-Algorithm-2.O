#include <iostream>
#include <algorithm>
#include "singlyLinkedList.cpp"

using namespace std;

// int getLength(Node *Head)
// {
//     Node *temp = Head;
//     int cnt = 0;

//     while (temp != NULL)
//     {
//         temp = temp->next;
//         cnt++;
//     }
//     return cnt;
// }

int getLength(Node *Head)
{
    Node *iterator = Head;
    int cnt = 0;
    while (iterator != NULL)
    {
        iterator = iterator->next;
        cnt++;
    }
    return cnt;
}

Node *findMiddle(Node *Head)
{
    Node *iterator = Head;
    int length = getLength(Head);
    int mid = (length / 2) + 1;

    for (int i = 1; i < mid; i++)
    {
        cout << endl
             << "1st " << i << " Data: " << iterator->data;
        iterator = iterator->next;

        cout << "    "
             << "2nd " << i << " Data: " << iterator->data;
    }
    return iterator;
}

// Node *middleNode(Node *Head)
// {

/* Vinayak Code
    int length = getLength(Head);
    int middleNodePosition = (length / 2) + 1;
    Node *iterator = Head;

    for (int i = 1; i < middleNodePosition; i++)
    {
        iterator = iterator->next;
    }
    return iterator;
*/

/* Babber Code

//    int length = getLength(Head);
    int middleNodePosition = (length / 2) ;
    Node *iterator = Head;

for(int i=0;i<middleNodePosition;i++){
    iterator=iterator.next;

}
return iterator;
*/
// }

Node *returnMiddleNode(Node *Head)
{
    Node *fastNode = Head;
    Node *slowNode = Head;
    if (Head == NULL || Head->next == NULL)
    {
         return Head;
    }
    while (fastNode->next != NULL)
    {
        if (fastNode->next->next == NULL)
        {
            if (fastNode->next != NULL)
            {
                slowNode = slowNode->next;
                fastNode = fastNode->next;
            }
            return slowNode;
        }
        fastNode = fastNode->next->next;
        slowNode = slowNode->next;
    }
    return slowNode;
}
int main()
{

    Node *n = new Node(6);
    Node *Head = n;
    Node *Tail = n;
    insertAtHead(48, Head);

    insertAtHead(5, Head);
    insertAtHead(32, Head);
    insertAtHead(0, Head);
    insertAtHead(4, Head);
    // insertAtHead(3, Head);
    // insertAtHead(4, Head);
    print(Head);

    cout << endl
         << "Length of Linked List is :" << getLength(Head);
    cout << endl
         << endl;
    // Node *middleHead = findMiddle(Head);
    cout << returnMiddleNode(Head)->data;
}