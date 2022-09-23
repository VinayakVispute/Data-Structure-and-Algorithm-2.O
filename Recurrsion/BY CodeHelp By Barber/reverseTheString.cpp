#include <iostream>
#include <string>
using namespace std;

// through Normal Function
/*void reverseString(string s)
{
    int len = s.length();
    int start = 0, end = len - 1;

    while (start < end)
    {
        swap(s[start], s[end]);
        start++;
        end--;
    }
    cout << s;
}*/

// NOw Throught Recurssion

void reverseString(string &s, int start, int end)
{
    if (start > end)
    {
        return;
    }
    swap(s[start], s[end]);
    reverseString(s, start + 1, end - 1);
    return;
}
int main()
{
    string unreverseString;

    cin >> unreverseString;
    int len = unreverseString.length();
    reverseString(unreverseString, 0, len - 1);
    cout << unreverseString;
}