#include <iostream>
#include <algorithm>

using namespace std;

int returnFactorial(int n)
{

    if (n == 1 || n == 0)
    {
        return 1;
    }
    int previous = returnFactorial(n - 1);

    return n * previous;
}

int main()
{
    int n;
    cin >> n;
    cout << endl
         << returnFactorial(n);
}