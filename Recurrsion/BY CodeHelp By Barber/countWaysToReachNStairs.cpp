#include <iostream>
#include <algorithm>

using namespace std;
int waysToNthStair(int nthStair)
{
    if (nthStair < 0)
    {
        return 0;
    }
    if (nthStair == 0)
    {
        return 1;
    }

    return waysToNthStair(nthStair - 2) + waysToNthStair(nthStair - 1);
}

int main()
{
    int n;
    cin >> n;
    cout << endl
         << waysToNthStair(n);
}