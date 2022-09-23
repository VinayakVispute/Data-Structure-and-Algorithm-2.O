#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    if (n == 1)
    {
        cout << "1";
        return 0;
    }
    int noDays = 0;
    if (arr[0] > arr[1])
    {
        noDays++;
    }
    if (arr[n - 1] > arr[n - 2])
    {
        noDays++;
    }

    int maxSize = -9999;
    for (int i = 1; i < n - 1; i++)
    {
        if (arr[i] > maxSize)
        {
            maxSize = arr[i];
            if (arr[i] > arr[i + 1])
            {
                noDays++;
            }
        }
    }
    cout << noDays;
}