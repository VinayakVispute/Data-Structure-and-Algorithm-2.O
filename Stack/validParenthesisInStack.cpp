#include <iostream>
#include <stack>

using namespace std;

bool isValidParenthesis(string str)
{
    stack<char> temp;
    for (int i = 0; i < str.length(); i++)
    {
        char a = str[i];
        bool isOpeningBracket = (a == '(' || a == '{' || a == '[');
        bool isClosingBracket = (a == ']' || a == '}' || a == ')');
        if (isOpeningBracket)
        {
            temp.push(a);
        }
        else
        {
            if (!temp.empty())
            {
                int b = temp.top();
                if (b == '(' && a == ')')
                {
                    temp.pop();
                    continue;
                }
                else if (b == '{' && a == '}')
                {
                    temp.pop();
                    continue;
                }
                else if (b == '[' && a == ']')
                {
                    temp.pop();
                    continue;
                }
                else
                {
                    return 0;
                }
            }
            else
            {
                return 0;
            }
        }
    }

    if (temp.empty())
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    string str;
    cin >> str;
    cout << isValidParenthesis(str);
}