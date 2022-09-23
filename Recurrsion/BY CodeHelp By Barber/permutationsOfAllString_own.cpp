#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int count = 0;
void solve(string str, string output, int index, vector<string> &ans)
{
    ::count++;

    swap(str[0], str[index]);
    output.push_back(str[0]);
    for (int i = 0; i < (str.length() - 1); i++)
    {
        solve(str.substr(1), output, i, ans);
    }
    if (str.length() == 1)
    {
        ans.push_back(output);
        return;
    }
}

vector<string> returnPermutation(string str)
{
    string output;
    vector<string> ans;
    for (int i = 0; i < str.length(); i++)
    {
        solve(str, output, i, ans);
    }
    return ans;
}

int main()
{

    string str;
    cin >> str;

    vector<string> ans = returnPermutation(str);

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
    cout << ::count;
}