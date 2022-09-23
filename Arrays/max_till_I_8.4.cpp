// Given an Array of size n. For Every i from 0 to n-1 out max(a[0],a[1],....a[i]).
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    int mx = -999;
    int mxarr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        mx = max(mx, arr[i]);
        mxarr[i] = mx;
    }
    cout << endl;
    for (int i = 0; i < n; i++)
        cout << mxarr[i] << " ";
}