#include <iostream>
#include <algorithm>

using namespace std;
string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "lmno", "pqrs", "tuv", "wxyz"};

void solution(string str, int index, string output)
{
    if (index >= str.length())
    {
        cout << endl
             << output;
    }
    int num = str[index] - '0';
    string digit = mapping[num];

    for (int i = 0; i < (digit.length()); i++)
    {

        output.push_back(digit[i]);
        solution(str, index + 1, output);
        output.pop_back();
    }
}

int main()
{
    string str;
    cin >> str;

    solution(str, 0, "");
}