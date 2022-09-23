#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

void toUpperCase(string &s)
{
    for (int i = 0; i < s.length(); i++)
    {
        if ((int(s[i])) >= 97 && (int(s[i])) <= 122)
        {
            int n = ((int(s[i])) - 32);

            s[i] = char(n);
        }
    }
}
void toLowerCase(string &s)
{
    for (int i = 0; i < s.length(); i++)
    {
        if ((int(s[i])) >= 65 && (int(s[i])) <= 90)
        {
            int n = ((int(s[i])) + 32);

            s[i] = char(n);
        }
    }
}

void toOppCase(string &s)
{
    for (int i = 0; i < s.length(); i++)
    {
        if ((int(s[i])) >= 97 && (int(s[i])) <= 122)
        {
            int n = ((int(s[i])) - 32);

            s[i] = char(n);
        }
        else if ((int(s[i])) >= 65 && (int(s[i])) <= 90)
        {
            int n = ((int(s[i])) + 32);

            s[i] = char(n);
        }
    }
}

void checkinput(int n, string &s)
{

    if (n == 1)
    {
        toUpperCase(s);
        return;
    }
    else if (n == 2)
    {
        toLowerCase(s);
        return;
    }
    else if (n == 3)
    {
        toOppCase(s);
        return;
    }
    else
    {
        cout << endl
             << endl
             << "Invalid Entry";
        return;
    }
}
int main()
{
    string s1;
    getline(cin, s1);
    cout << "Your Current String :: " << s1 << endl;
    cout << endl
         << "Do you want to" << endl
         << "1) TO UPPER CASE" << endl
         << "2) TO LOWER CASE " << endl
         << "3) TO OPPOSITE CASE";
    cout << endl;
    int n;
    cin >> n;
    checkinput(n, s1);
}