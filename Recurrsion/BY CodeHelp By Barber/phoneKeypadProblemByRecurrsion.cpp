/*Phone Keypad Problem Recursion */
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

void solve(string digits, string output, string mapping[], int index, vector<string> &ans)
{
    if (index >= digits.length())
    {
        ans.push_back(output);

        return;
    }
    int num = digits[index] - '0';
    string valueOfKeypad = mapping[num];

    for (int i = 0; i < valueOfKeypad.length(); i++)
    {
        output.push_back(valueOfKeypad[i]);
        solve(digits, output, mapping, index + 1, ans);
        output.pop_back();
    }
}

vector<string> letterCombinations(string digits)
{
    vector<string> ans;
    string output;
    string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "lmno", "pqrs", "tuv", "wxyz"};

    solve(digits, output, mapping, 0, ans);

    return ans;
}

int main()
{
    string inputKeypad;
    cin >> inputKeypad;
    vector<string> ans;
    ans = letterCombinations(inputKeypad);
  cout << endl
         << endl
         << " {";
    for (int i = 0; i < ans.size(); i++)
    {
        bool flag1 = false;
        cout << " `` ";
        bool flag = false;
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j];
        }

        cout << " `` ";
        if (i == (ans.size() - 1))
        {
        }
        else
        {
            cout << ", ";
        }
    }
    cout << " }\n\n\n";
}