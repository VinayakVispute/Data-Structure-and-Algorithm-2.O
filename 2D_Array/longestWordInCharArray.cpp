#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.ignore();
    char arr[n + 1];
    cin.getline(arr, n);
    cin.ignore();
    int i = 0;
    int maxSum = INT_MIN;
    int end = 0;
    cout << endl
         << arr << endl
         << endl;
    int currSum = 0;
    while (1)
    {
        if (arr[i] == ' ' || arr[i] == '\0')
        {
            if (currSum > maxSum)
            {
                maxSum = max(currSum, maxSum);
                end = i;
            }
            currSum = 0;
        }
        else
        {
            currSum++;
        }
        if (arr[i] == '\0')
        {
            break;
        }
        i++;
    }
    cout << endl;
    cout << endl;
    cout << maxSum;
    cout << endl;
    cout << endl;
    cout << endl;

    for (int i = end - maxSum; i <= end; i++)
    {
        cout << arr[i];
    }
}