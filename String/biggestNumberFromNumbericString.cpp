#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    string s;
    getline(cin, s);
    sort(s.begin(), s.end());
    reverse(s.begin(), s.end());
    cout << endl
         << s;
}