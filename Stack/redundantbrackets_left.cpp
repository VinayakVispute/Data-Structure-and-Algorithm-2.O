#include <iostream>
#include <vector>
#include <stack>
using namespace std;

bool findRedundantBrackets(string &s)
{
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];

        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            st.push(ch);
        }
        else
        {
            // ch ya toh ')' hai or lowercase letter

            if (ch == ')')
            {
                bool isRedundant = true;

                while (st.top() != '(')
                {
                    char top = st.top();
                    if (top == '+' || top == '-' || top == '*' || top == '/')
                    {
                        isRedundant = false;
                    }
                    st.pop();
                }

                if (isRedundant == true)
                    return true;
                st.pop();
            }
        }
    }
    return false;
}
int main()
{
    vector<string> v;
    v.push_back("(a+b)");
    v.push_back("(a+c*b)+(c))");
    v.push_back("(a*b+(c/d))");
    v.push_back("((a/b))");

    for (int i = 0; i < 4; i++)
    {
        cout << v[i] << "  ";
        findRedundantBrackets(v[i]) ? cout << "True" : cout << "False";
        cout << endl;
    }
}