#include <iostream>
#include <algorithm>

using namespace std;

void solution(string str, int i, string output)
{
    if (i >= str.length())
    {
        cout << endl
             << output << endl;
        return;
    }
    // Exclude
    solution(str, i + 1, output);
    char a = str[i];
    int b = a;
    // include
    solution(str, i + 1, output + a);
    solution(str, i + 1, output + to_string(a));
}

int main()
{

    string str;
    cin >> str;
    solution(str, 0, "");
}