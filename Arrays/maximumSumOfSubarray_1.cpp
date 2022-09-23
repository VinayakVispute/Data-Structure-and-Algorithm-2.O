/*Maximum Sum of SubArrary
   USING KADEN'S ALGORITHM
   TIME COMPLEXITY : O(N);

*/
#include <iostream>
#include <algorithm>
#include <climits>
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
    int currSum = 0, maxSum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        currSum += arr[i];
        maxSum = max(maxSum, currSum);
        if (currSum <= 0)
        {
            currSum = 0;
        }
    }
    cout << maxSum;
}