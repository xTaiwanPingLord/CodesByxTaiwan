#include <iostream>
using namespace ::std;

int main()
{
    int a[] = {1, 2, 3, 4, 5, 8, 7, 4, 7, 4, 0};
    int arraylen = sizeof(a) / sizeof(int);
    int min = a[0];
    int max = a[0];
    int maxL = 0, minL = 0;

    for (int i = 0; i < arraylen; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
            maxL = i;
        }

        if (min > a[i])
        {
            min = a[i];
            minL = i;
        }
    }
    cout << "max:" << max << ", 第" << maxL + 1 << "個數" << endl;
    cout << "min:" << min << ", 第" << minL + 1 << "個數" << endl;

    return 0;
}