#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void removeDuplicate(string str, char previousChar)
{
    if (str.length() == 0)
    {
        return;
    }
    if (str[0] == previousChar)
    {
        removeDuplicate(str.substr(1), previousChar);
    }
    else
    {
        previousChar = str[0];
        cout << previousChar;
        removeDuplicate(str.substr(1), previousChar);
    }
}
int main()
{
    string str = "VVVVVVVVViiiiiinaaaaaaaaaaaaaayaaaaaaaakkkkkk Visssssspppppuuuuuute";
    removeDuplicate(str, 'z');
}