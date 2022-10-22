#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

void insertAtBottom(stack<int> &myStack, int x)
{
    if (myStack.empty())
    {
        myStack.push(x);
        return;
    }
    int a = myStack.top();
    myStack.pop();
    insertAtBottom(myStack, x);
    myStack.push(a);
}

void reverseTheStack(stack<int> &s)
{

    if (s.size() == 1 || s.empty() == 1)
    {
        return;
    }

    int a = s.top();
    s.pop();
    reverseTheStack(s);
    insertAtBottom(s, a);
}

int main()
{
    stack<int> s;

    reverseTheStack(s);
    while (!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }
}