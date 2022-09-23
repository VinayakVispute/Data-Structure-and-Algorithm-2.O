#include <iostream>
#include <algorithm>

using namespace std;

int fibonacci(int n)
{
    if (n == 1)
    {
        return 0;
    }
    if (n == 2)
    {
        return 1;
    } // 0 1 1 2 3 5 8

    return (fibonacci(n - 1) +
            fibonacci(n - 2));
}

int main()
{
    int n;
    cin >> n;
    cout << endl
         << fibonacci(n);
}