#include <iostream>
#include <algorithm>
using namespace std;
int size;
istream &operator>>(istream &in, int arr[])
{
    for (int i = 0; i < size; i++)
    {
        in >> arr[i];
    }
}
ostream &operator<<(ostream &out, int arr[])
{
    for (int i = 0; i < size; i++)
    {
        out << arr[i] << " ";
    }
}

void bubbleSort(int arr[], int size)
{
    if (size == 1 || size==0)
    {
        return;
    }
    for (int j = 0; j < size - 1; j++)
    {
        if (arr[j] > arr[j + 1])
        {
            swap(arr[j], arr[j + 1]);
        }
    }
    bubbleSort(arr, size - 1);
    return;
}
int main()
{
    cin >> size;
    int arr[size];

    cin >> arr;
    cout << endl
         << "Before Sorting:" << endl
         << arr;
    bubbleSort(arr, size);
    cout << endl
         << "After Sorting:" << endl
         << arr;
}