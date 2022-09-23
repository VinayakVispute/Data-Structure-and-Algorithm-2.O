#include <iostream>
using namespace std;

bool reverseString(string &s, int start = 0)
{
    int end = s.length() - 1 - start;
    if (start > end)
    {
        return 1;
    }
    if (s[start] != s[end])
    {
        return 0;
    };
    return reverseString(s, start + 1);
}
int main()
{
    string str;

    cin >> str;
    int len = str.length();
    reverseString(str) ? cout << "True Its Palidrome" : cout << "False Its Not Palidrome";
}