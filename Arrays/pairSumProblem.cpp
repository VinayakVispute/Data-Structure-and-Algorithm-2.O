/*Chech if there exists two elements in an anttay such that their sum is equal to given k;*/
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
    int sum;
    cout << endl
         << "ENter the Sum :";
    cin >> sum;
    int start = 0, end = n - 1;
    while (end >= 0 && start < n && start < end)
    {
        int currSum = arr[start] + arr[end];

        if (currSum > sum)
        {
            end--;
        }
        else if (currSum < sum)
        {
            start++;
        }
        else if (currSum == sum)
        {
            cout << ++start << ++end;
            cout << endl;
            return 0;
        }
    }
    cout << "\nInvalid\n";
    cout << endl;
}