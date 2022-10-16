#include <iostream>
#include <algorithm>

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
        cout << "Memory is free for the Node with data : " << value << endl;
    }
};
// void insertAtHead(int val, Node *&Tail)
// {
//     Node *temp = new Node(val);
//     Node *Head = Tail->next;
//     Tail->next = temp;
//     temp->next = Head;
// }

void insertNode(Node *&Tail, int reference, int key)
{
    // Assuming that the reference is present in the Linked List
    Node *temp = new Node(key);
    if (Tail == NULL)
    {
        Tail = temp;
        temp->next = temp;
        return;
    }
    else
    {
        Node *iterator = Tail;
        while (iterator->data != reference)
        {

            iterator = iterator->next;
            if (iterator == Tail)
            {
                cout << endl
                     << "Element not Found";
                return;
            }
        }
        // Now Element is found
        temp->next = iterator->next;
        iterator->next = temp;
    }
}
void print(Node *Tail)
{
    cout << endl;
    if (Tail == NULL)
    {
        cout << " Empty..." << endl;
        return;
    }
    Node *temp = Tail;
    do
    {
        cout << Tail->data << " ";
        Tail = Tail->next;
    } while (Tail != temp);
    cout << endl;
}
void deleteByElement(Node *&Tail, int key)
{

    if (Tail == NULL)
    {
        cout << endl
             << "Empty List" << endl;
        return;
    }
    else
    {
        Node *prev = Tail;
        Node *iterator = prev->next;
        // if (prev->data == key)
        // {
        //     Tail = prev->next;
        // }
        if (iterator == prev)
        {
            Tail = NULL;
            return;
        }
        while (iterator->data != key)
        {
            prev = iterator;
            iterator = iterator->next;
        }
        prev->next = iterator->next;
        if (iterator == Tail)
        {
            Tail = prev;
        }
        iterator->next = NULL;
        delete iterator;
    }
}

// int main()
// {
//     Node *Tail = NULL;
//     print(Tail);
//     insertNode(Tail, 5, 1);
//     deleteByElement(Tail, 1);

//     print(Tail);
//     insertNode(Tail, 1, 3);
//     print(Tail);
//     cout << endl
//          << "Tail  => " << Tail->data << endl;
//     insertNode(Tail, 3, 5);
//     print(Tail);
//     cout << endl
//          << "Tail  => " << Tail->data << endl;
//     insertNode(Tail, 1, 2);
//     print(Tail);
//     cout << endl
//          << "Tail  => " << Tail->data << endl;
//     insertNode(Tail, 3, 4);
//     print(Tail);
//     cout << endl
//          << "Tail  => " << Tail->data << endl;
//     insertNode(Tail, 5, 9);
//     print(Tail);
//     cout << endl
//          << "Tail  => " << Tail->data << endl;
//     insertNode(Tail, 1, 11);
//     print(Tail);
//     cout << endl
//          << "Tail  => " << Tail->data << endl;

//     deleteByElement(Tail, 9);
//     print(Tail);
// }