#include <iostream>
using namespace ::std;

int main()
{
    for (int HP = 1000; HP <= 5000; HP += 300)
    {
        cout << HP << endl;
        if (HP > 4000)
            cout << "safe" << endl;
    }

    return 0;
}