#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, c, d;
    a = int(1e+9);
    b = int(1.2e+9);
    c = int(1.1e+9);
    d = int(1.3e+9);
    cout << a << endl;
    cout << (a * b < c * d) << endl;
    cout << a * b << " " << c * d << endl;
    cout << uint64_t(a) * uint64_t(b) << " " << uint64_t(c) * uint64_t(d) << endl;
    cout << (uint64_t(a) * uint64_t(b) < uint64_t(c) * uint64_t(d));

    return 0;
}