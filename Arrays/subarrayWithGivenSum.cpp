#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    int sum;
    cin >> sum;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int start = 0, end = 0, currSum = 0;

    while (currSum + arr[end] <= sum && end < n)
    {
        currSum += arr[end];
        end++;
    }

    if (currSum == sum)
    {
        cout << start + 1 << " " << end;
        return 0;
    }
    while (end < n)
    {

        currSum += arr[end];
        while (currSum > sum)
        {
            currSum -= arr[start];
            start++;
        }
        if (sum == currSum)
        {
            cout << start + 1 << " " << end + 1;
            return 0;
        }
        end++;
    }
    cout << "-1 -1";
}