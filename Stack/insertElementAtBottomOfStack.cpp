#include <iostream>
#include <stack>

using namespace std;

void solve(stack<int> &myStack, int x)
{
    if (myStack.empty())
    {
        myStack.push(x);
        return;
    }
    int a = myStack.top();
    myStack.pop();
    solve(myStack, x);
    myStack.push(a);
}

int main()
{

    stack<int> s;
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    solve(s, 1);
    while (!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }
}