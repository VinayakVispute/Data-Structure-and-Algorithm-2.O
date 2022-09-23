#include <iostream>
#include <algorithm>

using namespace std;
long long returnFactorial(long long n)
{
    if (n == 0)
    {
        return 1;
    }

    return (returnFactorial(n - 1) * n);
}

int main()
{

    long long n;
    cin >> n;

    cout << returnFactorial(n);
}