#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int kadane(int arr[], int n)
{
    int currSum = 0;
    int maxSum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        currSum += arr[i];
        maxSum = max(maxSum, currSum);
        if (currSum <= 0)
        {
            currSum = 0;
        }
    }
    return maxSum;
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int wrapsum;
    int nonwrapsum;
    nonwrapsum = kadane(arr, n);
    int totalSum = 0;
    for (int i = 0; i < n; i++)
    {
        totalSum += arr[i];
        arr[i] *= -1;
    }
    cout << kadane(arr, n);
    wrapsum = totalSum + kadane(arr, n);

    // cout << max(wrapsum, nonwrapsum);
}