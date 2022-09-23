#include <iostream>
using namespace std;

// An Abstract Class

class Test
{
private:
    int *a;

public:
    // default constructor
    Test()
    {
        a=new int;
        *a=0;
    }

    Test(int x){
        a=new int;
        *a=x;
    }
};

int main(){

    Test a;
    Test b(10,43);
    Test c=b;
}