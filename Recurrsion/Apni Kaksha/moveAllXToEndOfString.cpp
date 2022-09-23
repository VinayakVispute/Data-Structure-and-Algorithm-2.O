#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
string moveAllXToEndOfString(string str, int i)
{
    if (i == str.length() - 1)
    {
        return str;
    }
    char ch = str[i];
    if (ch == 'x')
    {
        string str1 = str.substr(0, i);
        str = str.substr(i + 1);

        str = str1 + str;
        str += "x";
    }
    return moveAllXToEndOfString(str, i + 1);
}
int main()
{
    string str = "axbdxxxcefxhix";
    cout << endl
         << moveAllXToEndOfString(str, 0);
}