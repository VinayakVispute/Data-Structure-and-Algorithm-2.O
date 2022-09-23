#include <iostream>
#include <algorithm>

using namespace std;
void waysToNthStair(int nthStair, int currStair, int &count)
{
    if (currStair == nthStair)
    {
        count++;
        return;
    }
    if (currStair > nthStair)
    {
        return;
    }

    waysToNthStair(nthStair, currStair + 1, count);
    waysToNthStair(nthStair, currStair + 2, count);
}

int main()
{
    int n;
    cin >> n;
    int noOfCases = 0;
    waysToNthStair(n, 0, noOfCases);
    cout << endl;
    cout << noOfCases;
}