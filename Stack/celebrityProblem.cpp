#include <iostream>
#include <stack>
#include <vector>
using namespace std;

bool knows(vector<vector<int>> &arr, int a, int b)
{
    return (arr[a][b] == 1);
}

int celebrity(vector<vector<int>> &arr, int n)
{
    stack<int> s;
    // step 1: push all element in stack
    for (int i = 0; i < n; i++)
    {
        s.push(i);
    }

    while (s.size() > 1)
    {
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();
        // Step 2:
        if (knows(arr, a, b))
        {
            s.push(b);
        }
        else
        {
            s.push(a);
        }
    }
    // step 3: single element in stack so verify it
    int candinate = s.top();
    bool rowCheck = false;
    int zeroCount = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[candinate][i] == 0)
        {
            zeroCount++;
        }
        if (zeroCount == n)
        {
            rowCheck = true;
        }
    }

    bool colCheck = false;
    int oneCount = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i][candinate] == 1)
        {
            oneCount++;
        }
        if (oneCount == n - 1)
        {
            colCheck = true;
        }
    }
    if (colCheck && rowCheck)
    {
        return candinate;
    }
    else
    {
        return -1;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> arr;
    for (int i = 0; i < n; i++)
    {
        vector<int> temp;
        for (int j = 0; j < n; j++)
        {
            int a;
            cin >> a;
            temp.push_back(a);
        }
        arr.push_back(temp);
        temp.clear();
    }
    cout << endl
         << celebrity(arr, n);
}