#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// No of Elements in PowerSet are 2 the power n;

void solution(vector<int> nums, vector<int> output, int index, vector<vector<int>> &ans)
{ // Base Case
    if (index >= nums.size())
    {
        ans.push_back(output);
        return;
    }

    // Exclude
    solution(nums, output, index + 1, ans);
    // Include
    output.push_back(nums[index]);
    solution(nums, output, index + 1, ans);
}

int main()
{
    int n;
    cout << "Enter the Number:";
    cin >> n;
    vector<int> nums;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        nums.push_back(a);
    }

    vector<vector<int>> ans;
    vector<int> output;

    solution(nums, output, 0, ans);
    cout << endl
         << endl
         << " {";
    for (int i = 0; i < ans.size(); i++)
    {
        bool flag1 = false;
        cout << "(";
        bool flag = false;
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j];
            if (j == (ans[i].size() - 1))
            {
            }
            else
            {
                cout << ", ";
            }
        }

        cout << " ) ";
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