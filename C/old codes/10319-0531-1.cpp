#include <iostream>
using namespace ::std;

int main()
{
    int a[15] = {0};
    a[0] = 1;
    a[1] = 1;

    cout << "a0=" << a[0] << endl;
    cout << "a1=" << a[1] << endl;

    for (int i = 1; i < 10; i++)
    {
        a[i + 1] = a[i] + a[i - 1];
        cout << "a" << i + 1 << "=" << a[i + 1] << endl;
    }

    return 0;
}