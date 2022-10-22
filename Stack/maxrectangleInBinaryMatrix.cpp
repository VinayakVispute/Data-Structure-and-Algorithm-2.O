#include <iostream>
#include <vector>
#include <stack>
#define MAX 1000
using namespace std;

vector<int> nextSmallerElement(int size, vector<int> arr)
{
    stack<int> temp;
    temp.push(-1);
    vector<int> ans(size);
    for (int i = size - 1; i >= 0; i--)
    {
        int curr = arr[i];
        while (temp.top() != -1 && arr[temp.top()] >= curr)
        {
            temp.pop();
        }
        ans[i] = temp.top();
        temp.push(i);
    }
    return ans;
}
vector<int> previousSmallerElement(int size, vector<int> arr)
{
    stack<int> temp;
    temp.push(-1);
    vector<int> ans(size);
    for (int i = 0; i < size; i++)
    {
        int curr = arr[i];
        while (temp.top() != -1 && arr[temp.top()] >= arr[i])
        {
            temp.pop();
        }
        ans[i] = temp.top();
        temp.push(i);
    }
    return ans;
}

int largestRectangle(vector<int> arr, int n)
{

    vector<int> next(n);
    next = nextSmallerElement(n, arr);
    vector<int> prev(n);
    prev = previousSmallerElement(n, arr);
    int area = -99999;
    for (int i = 0; i < n; i++)
    {
        int l = arr[i];
        if (next[i] == -1)
        {
            next[i] = n;
        }
        int b = next[i] - prev[i] - 1;
        int newarea = l * b;
        area = max(area, newarea);
    }
    return area;
}

int maxArea(vector<vector<int>> M, int n, int m)
{

    int area = largestRectangle(M[0], m);
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (M[i][j] != 0)
            {
                M[i][j] += M[i - 1][j];
            }
            else
            {
                M[i][j] = 0;
            }
        }
        // Entire Row is updated
        area = max(area, largestRectangle(M[i], m));
    }
    return area;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr;
    for (int i = 0; i < n; i++)
    {
        vector<int> temp;
        for (int j = 0; j < m; j++)
        {
            int a;
            cin >> a;
            temp.push_back(a);
        }
        arr.push_back(temp);
        temp.clear();
    }
    cout << maxArea(arr, n, m);
}
// ehuege gejhbhdgd