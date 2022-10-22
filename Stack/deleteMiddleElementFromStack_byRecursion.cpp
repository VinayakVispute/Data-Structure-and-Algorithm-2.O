#include <iostream>
#include <stack>
// Bruteforce Method
// space complexity O(N/2);
using namespace std;

void solve(stack<int> &inputStack, int N, int count)
{
}

void deleteMiddle(stack<int> &inputStack, int N)
{

    solve(inputStack, N, 0);
}

int main()
{
    stack<int> s;
    s.push(5); //
    s.push(9); //
    s.push(12);
    s.push(8); //
    deleteMiddle(s, s.size());
    while (!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }
}