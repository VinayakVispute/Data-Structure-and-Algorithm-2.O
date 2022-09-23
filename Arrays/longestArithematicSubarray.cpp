#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    int pd = 0,
        currlen = 2,
        maxlen = 2;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    pd = arr[1] - arr[0];
    for (int i = 2; i < n; i++)
    {
        if (pd == (arr[i] - arr[i - 1]))
        {
            currlen++;
        }
        else
        {
            pd = arr[i] - arr[i - 1];
            currlen = 2;
        }
        maxlen = max(maxlen, currlen);
    }
    cout << maxlen;
}
