#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

void reverseString(string str)
{
    if (str.length() == 0)
    {
        return;
    }
    char firstChar = str[0];
    reverseString(str.substr(1));
    cout << firstChar;
}

int main()
{

    string str;
    cin >> str;
    cout << endl;
    reverseString(str);
    cout << endl;
}