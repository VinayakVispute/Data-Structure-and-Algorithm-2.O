#include <iostream>
#include <algorithm>
#include <vector>
#include "singlyLinkedList.cpp"
using namespace std;

bool isPalidrome(Node *Head)
{
    if (Head == NULL || Head->next == NULL)
    {
        return Head;
    }
    vector<int> arr;
    Node *iterator;
    bool palidromeOrNot = false;
    iterator = Head;
    while (iterator != NULL)
    {
        arr.push_back(iterator->data);
        iterator = iterator->next;
    }
    int cnt = 0;
    int size = arr.size();
    while (cnt < (size / 2))
    {
        if (arr[cnt] != arr[size - cnt - 1])
        {
            return false;
        }
        else
        {
            cnt++;
        }
    }
    return true;
}
int main()
{
    Node *n = new Node(1);
    Node *Head = n;
    Node *Tail = n;
    insertAtTail(1, Tail);
    insertAtTail(2, Tail);
    insertAtTail(3, Tail);
    insertAtTail(2, Tail);
    insertAtTail(1, Tail);
    Head = NULL;
    print(Head);
    cout << endl;
    isPalidrome(Head) ? cout << "True" : cout << "False";
}