#include <iostream>
using namespace ::std;

int main()
{
    int num = 0, isPrime = 0;
    cin >> num;
    for (int i = 2; i < num; i++)
    {

        if (num % i == 0)
        {
            //cout << i << endl;
            cout << "Nope" << endl;
            isPrime = 1;
            break;
        }
    }
    if (isPrime != 1)
        cout << "Yes" << endl;

    return 0;
}