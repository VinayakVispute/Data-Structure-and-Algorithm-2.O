// https://www.codingninjas.com/codestudio/problems/two-stacks_983634?leftPanelTab=1
// Two Stack Problem....Coding Ninjas
#include <bits/stdc++.h>
class TwoStack
{
    int *arr;
    int size;
    int top1;
    int top2;

public:
    // Initialize TwoStack.
    TwoStack(int s)
    {
        size = s;
        arr = new int[s];
        top1 = -1;
        top2 = s;
    }

    // Push in stack 1.
    void push1(int num)
    {
        // Write your code here.
        if ((top1 <= (size)-1) && (top1 + 1) != top2) // here we can also use top1-top2>1..So difference should be greater than 1
        // it mean atleast a empty space is avaliable
        {
            top1++;
            arr[top1] = num;
            return;
        }
        else
        {
            return;
        }
    }

    // Push in stack 2.
    void push2(int num)
    {
        // Write your code here.
        if ((top2 >= 0) && (top2 - 1) != top1) // Same here we can use top2-top1>1
        {
            top2--;
            arr[top2] = num;
            return;
        }
        else
        {
            return;
        }
    }

    // Pop from stack 1 and return popped element.
    int pop1()
    {
        if ((top1 >= 0))
        {
            int a = arr[top1];
            top1--;
            return a;
        }
        else
        {
            return -1;
        }
    }

    // Pop from stack 2 and return popped element.
    int pop2()
    {
        // Write your code here.
        if (top2 < size)
        {
            int a = arr[top2];
            top2++;
            return a;
        }
        else
        {
            return -1;
        }
    }
};
