// ranjha ke liy heer or majnu ke liy laila honi chahiye...
// madam make-up se kuch nahi hota,shkal bhi honi chahiye

// soul me goblin...god like me neyoo..bhoot bhi aapki shkal dekh ke bola...
// ohh mori maiya o ka dekh liooo
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
int main()
{
    cin >> n;
    int arr[n];
    cin >> arr;
    cout << "Before Sorting \n"
         << arr;

    int i, j;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < (n - 1 - i); j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    cout << "\nAfter Sorting\n"
         << arr;
}
