#include <iostream>
using namespace ::std;

int main()
{
    int num, sum = 0;
    cout << "1+2+3+4+....?" << endl;
    cin >> num;
    for (int i = 0; i <= num; i++)
    {
        sum += i;
    }
    cout << "1+2+3+4+....+" << num << "=" << sum << endl;

    return 0;
}