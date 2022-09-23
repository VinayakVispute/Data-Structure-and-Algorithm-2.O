#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{

    vector<int> v;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    // Through For Loop
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    } // Output : 1 2 3
    cout << endl;
    vector<int>::iterator it;

    for (it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    } // output 1 2 3
    cout << endl;

    for (auto key : v)
    {
        cout << key << " ";
    }

    // POP back function for removing last elemment
    v.pop_back();
    cout << endl;
    for (auto key : v)
    {
        cout << key << " ";
    }

    vector<int> v2(3, 50);
    // Elements are 50 50 50
    cout << endl;
    for (auto key : v2)
    {
        cout << key << " ";
    }

    // Swap Function...
    swap(v, v2);

    cout << endl
         << "For V" << endl;
    for (auto key : v)
    {
        cout << key << " ";
    }

    cout << endl
         << "For V2" << endl;
    for (auto key : v2)
    {
        cout << key << " ";
    }

    // Sorting Function
    sort(v.begin(), v.end());

    // Left.....
}