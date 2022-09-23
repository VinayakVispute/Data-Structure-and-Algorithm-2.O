#include <iostream>
#include <algorithm>

using namespace std;

int returnPower(int base, int power)
{
    if (power == 0)
    {
        return 1;
    }

    int previousPower = returnPower(base, power - 1);
    return base * previousPower;
}

int main()
{
    cout << returnPower(4, 3);
}