#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
int minimimNumberReversal(string str)
{
    if (str.length() % 2 != 0)
    {
        return -1;
    }
    stack<int> temp;
    int coast = 0;
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        if (ch == '{')
        {
            temp.push(ch);
        }
        else if (ch == '}')
        {
            if (!temp.empty() && temp.top() == '{')
            {
                temp.pop();
            }
            else
            {
                temp.push(ch);
            }
        }
    }
    // Now Stack contains Invalid Expression
    int openbrac = 0, closebrac = 0;

    while (!temp.empty())
    {
        if (temp.top() == '{')
        {
            openbrac++;
        }
        else
        {
            closebrac++;
        }
        temp.pop();
    }
    return (((closebrac + 1) / 2) + ((openbrac + 1) / 2));
}

int main()
{
    string str;
    cin >> str;
    cout << minimimNumberReversal(str);
}