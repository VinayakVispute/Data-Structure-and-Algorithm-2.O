#include <iostream>
#include <algorithm>

using namespace std;

int returnFibonacci(int n)
{
    if (n == 1)
    {
        return 0;
    }
    if (n == 2)
    {
        return 1;
    }

    return (returnFibonacci(n - 1) + returnFibonacci(n - 2));
}

int main()
{

    cout << returnFibonacci(15);
}