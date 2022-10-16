#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;

int main()
{
    string str;
    cin >> str;
    stack<char> s;
    cout << endl
         << endl
         << "The String Before : " << str;
    for (int i = 0; i < str.length(); i++)
    {
        s.push(str[i]);
    }
    cout << endl
         << endl
         << "The String After Reverse : ";
    while (!s.empty())
    {
        cout << s.top();
        s.pop();
    }
}