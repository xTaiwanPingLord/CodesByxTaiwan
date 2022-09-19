#include <iostream>
#include <math.h>
#include <vector>
using namespace ::std;

class test
{
public:
    void SetVar1(int set) { var1 = set; };
    int Test1 = [this](int a) -> auto { var1 += a; return var1; };
protected:
private:
    int var1;
};

int main()
{
    test t;
    t.SetVar1(10);

    cout << t.Test1(15);
}

