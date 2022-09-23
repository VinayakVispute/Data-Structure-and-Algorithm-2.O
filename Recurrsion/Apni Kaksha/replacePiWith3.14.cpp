#include <iostream>
#include <algorithm>

using namespace std;

void replacePI(string str)
{
    if (str.length() == 0)
    {
        return;
    }

    if (str[0] == 'p' && str[1] == 'i')
    {
        str = str.substr(1);
        cout << "3.14";
    }
    else
    {
        cout << str[0];
    }
    replacePI(str.substr(1));
}

int main()
{
    string str = "pippxxppiixipi";
    cout << endl;
    replacePI(str);
}