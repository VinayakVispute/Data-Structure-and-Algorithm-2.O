#include <iostream>

using namespace std;

int firstOccurence(int arr[], int size, int key, int pointer)
{
    if (size == 0)
    {
        return -1;
    }
    if (arr[0] == key)
    {
        return pointer;
    }
    firstOccurence(arr, size, key, pointer + 1);
}

int lastOccurence(int arr[], int size, int key, int pointer)
{
    if (pointer == size)
    {
        return -1;
    }
    int restArray = lastOccurence(arr, size, key, pointer + 1);
    if (restArray != -1)
    {
        return restArray;
    }
    if (arr[pointer] == key)
    {
        return pointer;
    }
    return -1;
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
    int key;
    cout << endl
         << "Enter the Number For Which You Want To Operate On : ";
    cin >> key;
    cout << endl;
    cout << firstOccurence(arr, n, key, 0); // DOne
    cout << endl
         << endl;
    cout << lastOccurence(arr, n, key, 0); // DOne
}