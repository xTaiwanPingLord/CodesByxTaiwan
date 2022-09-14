#include <iostream>
#include <math.h>
#include <vector>
using namespace ::std;

class test
{
public:
    void SetVar1(int set) { var1 = set; };
    auto Lambda = [this]() -> int{ var 1 = 20; return var1; };
protected:
private:
    int var1;
};

int main()
{
    test t;
    t.SetVar1(10);

    cout << t.Lambda;
}

