#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int nextsmallerelement(int size, int arr[], int solutionarr[])
{
    stack<int> temp;
    temp.push(-1);
    cout << endl;
    for (int i = size - 1; i >= 0; i--)
    {

        if (arr[i] > temp.top())
        {
            solutionarr[i] = temp.top();
        }
        else
        {
            while (temp.top() != -1 && temp.top() >= arr[i])
            {
                temp.pop();
            }
            solutionarr[i] = temp.top();
        }
        temp.push(arr[i]);
    }
}

int main()
{
    int size;
    cin >> size;
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    int solutionarr[size];
    nextsmallerelement(size, arr, solutionarr);
    for (int i = 0; i < size; i++)
    {
        cout << "  " << solutionarr[i];
    }
}