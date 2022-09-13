#include <iostream>
using namespace ::std;

int main()
{
    int a[10];
    int arraylen = sizeof(a) / sizeof(int);
    int maxL = 0, minL = 0, sum = 0;
    float avg = 0;

    for (int i = 0; i < arraylen; i++)
    {
        cout << "輸入第" << i + 1 << "位成績" << endl;
        cin >> a[i];
    }

    int min = a[0];
    int max = a[0];
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
        sum += a[i];
    }



    avg = sum / 10;
    cout << "班總分:" << sum << endl;
    cout << "班平均:" << avg << endl;
    cout << "max:" << max << ", 第" << maxL + 1 << "個數" << endl;
    cout << "min:" << min << ", 第" << minL + 1 << "個數" << endl;

    return 0;
}