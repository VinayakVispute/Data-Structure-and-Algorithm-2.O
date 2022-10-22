#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <climits>
using namespace std;

vector<int> nextsmallerelement(int size, vector<int> arr)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(size);

    for (int i = size - 1; i >= 0; i--)
    {
        int curr = arr[i];

        while (s.top() != -1 && arr[s.top()] >= curr)
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}
vector<int> previoussmallerelement(int size, vector<int> arr)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(size);

    for (int i = 0; i < size; i++)
    {
        int curr = arr[i];

        while (s.top() != -1 && arr[s.top()] >= curr)
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

int largestRectangle(vector<int> &heights)
{
    int n = heights.size();
    vector<int> smallest = previoussmallerelement(n, heights);
    vector<int> highest = nextsmallerelement(n, heights);
    int area = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        int l = heights[i];
        if (highest[i] == -1)
        {
            highest[i] = n;
        }
        int b = highest[i] - smallest[i] - 1;
        int newarea = l * b;
        area = max(area, newarea);
    }
    return area;
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << endl
         << largestRectangle(arr);
}