#include <iostream>
#include <algorithm>
#define n 5
using namespace std;

class Stack
{
private:
    int top;
    int *arr;

public:
    Stack()
    {
        arr = new int[n];
        top = -1;
    }

    void push(int val)
    {
        if (top <= (n - 1))
        {
            cout << endl
                 << "Stack Overflow.." << endl;

            return;
        }

        top++;
        arr[top] = val;
    }

    void pop()
    {

        if (top < 0)
        {
            cout << "Stack is Empty" << endl;
            return;
        }
        else
        {
            top--;
        }
    }

    int peek()
    {
        if (top >= 0 && top < n)
        {
            return arr[top];
        }
        else
        {
            cout << "Stack is Empty" << endl;
            return -1;
        }
    }

    bool empty() { return (top == -1); }
};

int main()
{
    Stack n1;
    n1.push(22);
    n1.push(43);
    n1.push(44);
    n1.push(44);
    n1.push(44);
    n1.push(44);
    n1.push(44);
    cout << endl
         << endl;
    cout << n1.peek() << endl; // 44 -43 -22
    n1.pop();
    cout << n1.peek() << endl; // 43 -22
    n1.pop();
    cout << n1.peek() << endl; // 22
    // n1.pop();
    cout << n1.peek() << endl; // 0

    n1.empty() ? cout << endl
                      << "True"
               : cout << endl
                      << "False";
}