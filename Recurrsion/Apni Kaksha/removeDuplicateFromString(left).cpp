#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string removeDuplicate(string str)
{
    if (str.length() == 0)
    {
        return "";
    }
    char lastChar = str[0];
    string previousString = removeDuplicate(str.substr(1));
    if (previousString[0] == lastChar)
    {
        return previousString;
    }
    return (previousString + lastChar);
}

int main()
{
    // string str = "VVVVVVVVViiiiiinaaaaaaaaaaaaaayaaaaaaaakkkkkk Visssssspppppuuuuuute";
    cout << removeDuplicate("aaabbbccccccdeeee");
}