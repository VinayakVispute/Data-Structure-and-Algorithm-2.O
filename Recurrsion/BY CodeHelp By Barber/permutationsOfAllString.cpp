#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int count = 0;
void solve(string str, int index, vector<string> &ans)
{
    ::count++;

    if (index >= str.size())
    {
        ans.push_back(str);
        return;
    }

    for (int i = index; i < str.size(); i++)
    {
        swap(str[index], str[i]);
        solve(str, index + 1, ans);
        swap(str[index], str[i]);
    }
}

vector<string> returnPermutation(string str)
{
    vector<string> ans;
    string output;
    solve(str, 0, ans);
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