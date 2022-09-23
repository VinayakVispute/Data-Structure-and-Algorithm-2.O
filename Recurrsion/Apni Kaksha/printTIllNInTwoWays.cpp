#include <iostream>
#include <algorithm>

using namespace std;

void printTillNDec(int n)
{
    if (n == 0)
    {
        cout << 0;
        return;
    }
    cout << n << " ";
    printTillNDec(n - 1);
}
void printTillNInc(int n)
{
    if (n == 0)
    {
        cout << 0 << " ";
        return;
    }
    printTillNInc(n - 1);
    cout << n << " ";
}

int main()
{
    int n;
    cin >> n;
    cout << endl;
    printTillNDec(n);
    cout << endl;
    printTillNInc(n);
}