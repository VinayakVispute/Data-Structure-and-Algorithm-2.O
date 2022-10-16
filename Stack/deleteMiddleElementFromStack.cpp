#include <iostream>
#include <stack>
// Bruteforce Method
// space complexity O(N/2)
using namespace std;

int main()
{
    stack<int> s;
    s.push(5); //
    s.push(9); //
    s.push(12);
    s.push(8); //
    s.push(4); //
    stack<int> temp;
    int count = 0;
    for (int i = 0; i <= (s.size() / 2); i++)
    {

        int a = s.top();
        s.pop();
        temp.push(a);
        count++;
    }
    s.pop();
    while (!temp.empty())
    {
        s.push(temp.top());
        temp.pop();
    }
    cout << endl
         << endl
         << " | ";
    while (!s.empty())
    {
        cout << s.top() << " | ";
        s.pop();
    }
}