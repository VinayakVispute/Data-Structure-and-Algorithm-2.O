#include <iostream>
#include <algorithm>

using namespace std;

int sum(int n)
{

    if (n == 0)
    {
        return 0;
    }
    int previousSum = sum(n - 1);

    return (n + previousSum);
}

int main()
{
    int n;
    cin >> n;
    cout << endl
         << sum(n);
}