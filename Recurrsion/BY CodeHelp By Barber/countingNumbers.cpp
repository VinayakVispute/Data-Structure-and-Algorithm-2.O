#include <iostream>
#include <algorithm>

using namespace std;

void counting(int n)
{
    if (n == 0)
    {
        cout << "0 ";
        return;
    }
    counting(n - 1);
    cout << n << " ";
}

int main()
{
    int n;
    cin >> n;

    cout << endl;
    counting(n);
}