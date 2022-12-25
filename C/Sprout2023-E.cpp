#include <bits/stdc++.h>
using namespace std;

int main()
{
    int Num, K;
    cin >> Num >> K;

    int people, Min = 1000000001, Max = 0;
    for (int i = 0; i < Num; i++)
    {
        cin >> people;
        if ((float)people < (float)K / 2.0) // 往上或往下都可以吧 反正往同一個方向就好
            people = K - people;
        if (people < Min)
            Min = people;
        if (people > Max)
            Max = people;
    }
    cout << (Max - Min);
}