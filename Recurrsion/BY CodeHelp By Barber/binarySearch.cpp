#include <iostream>
#include <algorithm>

using namespace std;

bool binarySearch(int arr[], int size, int key, int start, int end)
{
    // int mid = ((start + end) / 2);//This is not Right it will show bug at some point so right is mid = (start+(-start+end)/2).........Refer GreekForGreek Binary Search .
    int mid = (start + (end - start) / 2);
    if (arr[mid] == key)
    {
        return true;
    }
    if (start > end)
    {
        return false;
    }

    if (arr[mid] > key)
    {
        return binarySearch(arr, size, key, start, mid - 1);
    }
    else
    {
        return binarySearch(arr, size, key, mid + 1, end);
    }
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
    cout << endl
         << "Enter the Key:";
    int key;
    cin >> key;

    binarySearch(arr, n, key, 0, n - 1) ? cout << "True" : cout << "False";
}