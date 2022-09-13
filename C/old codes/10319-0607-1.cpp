#include <iostream>
using namespace ::std;

int main()
{
    int a[] = {1, 2, 3, 4, 5, 8, 7, 4, 7, 4, 0};
    int min = 0;

    for (int i = 0; i < 11; i++)
    {
        if (a[i] < a[min])
        {
            min = i;
        }
    }

    cout << "index: " << min << ", min: " << a[min] << endl;
}