#include <iostream>
using namespace ::std;

int main()
{
    for (int HP = 1000; HP <= 5000; HP += 300)
    {
        cout << HP << endl;
    }

    for (int i = 1; i <= 5; i++)
    {
        cout << i << endl;
    }
    for (int i = 5; i >= 1; i--)
    {
        cout << i << endl;
    }
    for (int i = 1; i <= 9; i += 2)
    {
        cout << i << endl;
    }
    for (int i = 9; i >= 1; i -= 2)
    {
        cout << i << endl;
    }

    return 0;
}