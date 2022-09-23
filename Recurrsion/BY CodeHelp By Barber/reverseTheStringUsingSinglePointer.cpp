#include <iostream>
using namespace std;

void reverseString(string &s, int start)
{
    int end = s.length() - 1 - start;
    if (start > end)
    {
        return;
    }
    swap(s[start], s[end]);
    reverseString(s, start + 1);
    return;
}
int main()
{
    string unreverseString;

    cin >> unreverseString;
    int len = unreverseString.length();
    reverseString(unreverseString, 0);
    cout << unreverseString;
}