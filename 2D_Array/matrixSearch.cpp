#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int arr[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    int key;
    cout << endl
         << "Enter Key to be Search :";
    cin >> key;
    int row = 0, col = n - 1;
    while (row < n && col >= 0)
    {
        if (arr[row][col] < key)
        {
            row++;
        }
        else if (arr[row][col] > key)
        {
            col--;
        }
        else if (arr[row][col] == key)
        {
            cout << row + 1 << " " << col + 1;
            return 0;
        }
    }
    cout << "Invalid";
    return 0;
}