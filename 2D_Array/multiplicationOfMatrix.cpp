#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    cout << "Enter Rows and Columns Respectively for Matrix 1 Acc. to Rules of Multiplication:";
    int n1, n2;
    cin >> n1 >> n2;
    int arr1[n1][n2];
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            cin >> arr1[i][j];
        }
    }
    cout << "Enter Rows and Columns Respectively for Matrix 2 Acc. to Rules of Multiplication:";
    int a1, a2;
    cin >> a1 >> a2;
    int arr2[a1][a2];
    for (int i = 0; i < a1; i++)
    {
        for (int j = 0; j < a2; j++)
        {
            cin >> arr2[i][j];
        }
    }
    if (n2 != a1)
    {
        cout << endl
             << "Invalid";
        return 0;
    }
    int soln[n1][a2];
    system("cls");
    cout << endl
         << endl;
    int currSum = 0;
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < a2; j++)
        {
            currSum = 0;
            for (int k = 0; k < a1; k++)
            {
                currSum += ((arr1[i][k]) * (arr2[k][j]));
            }
            soln[i][j] = currSum;
        }
    }
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < a2; j++)
        {
            cout << soln[i][j] << " ";
        }
        cout << endl;
    }
}