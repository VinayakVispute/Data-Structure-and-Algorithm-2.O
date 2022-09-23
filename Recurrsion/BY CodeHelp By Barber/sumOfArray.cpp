#include <iostream>
#include <algorithm>

using namespace std;

int sumOfArray(int arr[], int sizeOfArray)
{
    if (sizeOfArray == 0)
    {
        return 0;
    }

    return (arr[0] + sumOfArray(arr + 1, sizeOfArray - 1));
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
    cout << sumOfArray(arr, n);
}