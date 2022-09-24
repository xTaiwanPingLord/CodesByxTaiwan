#include <iostream>
#include <math.h>
#include <vector>
using namespace ::std;

int main()
{
    // while (1)
    //     cout << [](){static int a; a *= 2; return a; };
    for(int i=1;; i=i*2)printf("%d ", i);
}

