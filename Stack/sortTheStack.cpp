#include <iostream>
#include <stack>

using namespace std;

void insertAtPosition(stack<int> &s, int num)
{
    if (s.empty() == 1 || s.top() < num)
    {
        s.push(num);
        return;
    }
    int a = s.top();
    s.pop();
    insertAtPosition(s, num);
    s.push(a);
}

void sortSack(stack<int> &s)
{
    if (s.size() == 1 || s.empty() == 1)
    {
        return;
    }

    int num = s.top();
    s.pop();
    sortSack(s);
    insertAtPosition(s, num);
}

int main()
{
    stack<int> s;
    // s.push(5);

    sortSack(s);
    while (!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }
}