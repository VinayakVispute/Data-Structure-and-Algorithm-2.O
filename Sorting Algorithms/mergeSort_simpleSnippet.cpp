/*
Based on Divide and Conquer Algorithm

Divides array in two parts then call itself for that two halves
and then mergers the two sorted Halves

A Seperate merge function is used for merging two halves...

Time Complexitiy : O(nlog(n));
*/
#include <iostream>
#include <algorithm>
using namespace std;
int n;
istream &operator>>(istream &in, int arr[])
{
    for (int i = 0; i < n; i++)
    {
        in >> arr[i];
    }
}
ostream &operator<<(ostream &out, int arr[])
{
    for (int i = 0; i < n; i++)
    {
        out << arr[i] << " ";
    }
}
void merge(int arr[], int start, int mid, int end)
{
    int i = start;   // for first index of leftmost array
    int j = mid + 1; // for first index of Rightmost Array
    int k = start;   // for First index of Temporary array

    int temp[end + 1];

    while (i <= mid && j <= end)
    {
        if (arr[i] <= arr[j])
        {
            temp[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }
    while (j <= end)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }
    for (int p = start; p <= end; p++)
    {
        arr[p] = temp[p];
    }
}
void mergeSort(int arr[], int start, int end)
{
    if (start < end)
    {
        int mid = (start + ((end - start) / 2));
        // int mid = (start + end) / 2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}
int main()
{
    cin >> n;
    int arr[n];
    cin >> arr;
    cout << endl
         << "Before Sorting:" << endl
         << arr;

    mergeSort(arr, 0, n - 1);
    cout << endl
         << "After Sorting:" << endl
         << arr;
}