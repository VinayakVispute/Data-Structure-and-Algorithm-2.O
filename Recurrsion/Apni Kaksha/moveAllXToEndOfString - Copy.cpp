#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
string moveAllXToEndOfString(string str)
{
    if (str.length() == 0)
    {
        return "";
    }
    char ch = str[0];
    string ans = moveAllXToEndOfString(str.substr(1));
    if (ch == 'x')
    {
        return (ans + ch);
    }
    return ch + ans;
}
int main()
{
    string str = "axbdxxxcefxhix";
    cout << endl
         << moveAllXToEndOfString(str);
}