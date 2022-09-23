#include <iostream>
#include <algorithm>

using namespace std;
long long int returnPower(long long int, long long int);
long long int evenpower(long long int power, long long int base)
{
    long long int p = returnPower((power / 2), base);
    return (p * p);
}

long long int oddpower(long long int power, long long int base)
{
    long long int p = returnPower(power / 2, base);

    return (base * (p * p));
}

long long int returnPower(long long int power, long long int base)
{
    if (power == 0)
    {
        return 1;
    }
    if (power == 1)
    {
        return base;
    }
    if (power % 2 == 0)
    {
        return evenpower(power, base);
    }
    else
    {
        return oddpower(power, base);
    }
}

int main()
{
    long long int power, base;

    cout << endl
         << "Enter the Power and Base Respectevly:";
    cin >> power >> base;
    cout << returnPower(power, base);
    cout << endl;
}