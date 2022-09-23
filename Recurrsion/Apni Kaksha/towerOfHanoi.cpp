#include <iostream>
#include <algorithm>

using namespace std;

void towerOfHanoi(int n, string source, string destination, string helper)
{
    if (n == 0)
    {
        return;
    }
    towerOfHanoi(n - 1, source, helper, destination);

    cout << endl
         << n << "th is shifted from " << source << " to " << destination;
    towerOfHanoi(n - 1, helper, destination, source);
}

int main()
{

    towerOfHanoi(3, "A", "C", "B");
}