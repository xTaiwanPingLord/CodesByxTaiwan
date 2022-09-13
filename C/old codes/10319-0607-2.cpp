#include <iostream>
using namespace ::std;

#define swap(x, y) \
    int z = x;     \
    x = y;         \
    y = z;

int main()
{
    int a[] = {9, 7, 3, 1, 5};
    int min = 0;
    for (int k = 0; k < 4; k++){
        min = k;
        for (int j = k; j < 5; j++)
        {
            if (a[j] < a[min])
            {
                min = j;
            }
        }
        swap(a[min], a[k]);

        // for (int i = 0; i < 5; i++)
        // {
        //     cout << a[i] << " ";
        // }
        // cout << endl;
    }
    for (int i = 0; i < 5; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
}