#include <iostream>
#include <algorithm>

using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n];
    int mx = -9999;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        mx = max(mx, arr[i]);
    }
    mx++;
    bool temp[mx] = {0};
    // std::fill_n(temp, mx, -1);
    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= 0)
        {
            temp[arr[i]] = 1;
        }
    }
    for (int i = 0; i < mx; i++)
    {
        if (temp[i] == 0)
        {
            cout << i;
            return 0;
        }
    }
    cout << "-1";
}