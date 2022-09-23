#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n];
    int mx = -999;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        mx = max(mx, arr[i]);
    }
    mx++;
    int temp[mx];
    for (int i = 0; i < mx; i++)
    {
        temp[i] = -1;
    }
    int mindx = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (temp[arr[i]] > -1)
        {
            mindx = min(mindx, temp[arr[i]]);
        }
        else
        {
            temp[arr[i]] = i;
        }
    }
    if (mindx == INT_MAX)
    {
        cout << -1;
    }
    else
    {
        cout << mindx + 1 << " th Position";
    }
}