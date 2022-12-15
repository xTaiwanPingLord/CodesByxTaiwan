#include <bits/stdc++.h>
using namespace std;

int main()
{
    int num_cargo, volume, money;
    vector<int> v, c;

    cin >> num_cargo;

    for (int i = 0; i < num_cargo; i++)
    {
        cin >> volume >> money;
        v.push_back(volume);
        c.push_back(money);
    }

    vector<vector<int>> profit(num_cargo + 1, vector<int>(101, 0));

    for (int i = 1; i < num_cargo + 1; i++)
    {
        for (int j = 1; j < 101; j++)
        {
            if (v[i - 1] > j)
            {
                profit[i][j] = profit[i - 1][j];
            }
            else
            {
                profit[i][j] = max(profit[i - 1][j], (c[i - 1] + profit[i - 1][j - v[i - 1]]));
            }
        }
    }
    cout << profit[num_cargo][100];
}
