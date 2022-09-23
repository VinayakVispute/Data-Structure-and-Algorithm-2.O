/*
Quick Sort is Divide and Conquer Algorithm

Its picks an element as pivot and partitions the given array arounf picked pivot;

Different Ways of Picking Pivot:-
1. Always First Element ,2. Always pick last element as pivot(This Example), 3.Pick a Random element;

>>Quick Sort is considered as a in *place sorting algortihm*.
  It reduces the space complexity and removet the use of the auxiliary subarray
  that is used in merge sort
>>Quick Sort is one of the most efficient sorting algorithms
  Time Complexity & Space complexity: O(nlog(n))
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
int partition(int arr[], int start, int end)
{
    int pivot = arr[end];
    int pindex = start;
    for (int i = start; i < end; i++)
    {
        if (arr[i] <= pivot)
        {
            swap(arr[i], arr[pindex]);
            pindex++;
        }
    }
    swap(arr[end], arr[pindex]);
    return pindex;
}
void quickSort(int arr[], int start, int end)
{

    if (start < end)
    {
        int privot = partition(arr, start, end);

        quickSort(arr, start, privot - 1);
        quickSort(arr, privot + 1, end);
    }
}

int main()
{
    cin >> n;
    int arr[n];
    cin >> arr;
    cout << endl
         << "Before Sorted Array:" << endl
         << arr;
    quickSort(arr, 0, n - 1);
    cout << endl
         << "Sorted Array:" << endl
         << arr;
}