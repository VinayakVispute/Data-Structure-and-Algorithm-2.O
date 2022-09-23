#include <iostream>
#include <algorithm>

using namespace std;

int power(int base, int powerNo)
{
    if (powerNo == 0)
    {
        return 1;
    }

    return (base * power(base, powerNo - 1));
}

int main()
{

    int base, powerNo;
    cout << "Enter The Base & Power Respectively: ";
    cin >> base >> powerNo;
    cout << endl
         << power(base, powerNo);
}