#include <bits/stdc++.h>
using namespace std;

void InputVector(vector<vector<int>> &small, vector<vector<int>> &big, int &area)
{
    for (auto &i : small)
    {
        for (auto &j : i)
        {
            cin >> j;
        }
    }
    for (auto &i : big)
    {
        for (auto &j : i)
        {
            cin >> j;
            area += j;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int r1, c1, r2, c2, A = 0, max_delta, min_delta = 100000, delta = 0, sum_delta = 0, num_delta = 0, num_submatrix = 0;
    cin >> r1 >> c1 >> r2 >> c2 >> max_delta;
    vector<vector<int>> small(r1, vector<int>(c1, 0)), big(r2, vector<int>(c2, 0));

    InputVector(small, big, A);

    for (int i = 0; i < int(big.size() - small.size() + 1); i++)
    {
        for (int j = 0; j < int(big[i].size() - small[0].size() + 1); j++)
        {
            sum_delta = 0;
            num_delta = 0;
            for (int m = 0; m < int(small.size()); m++)
            {
                for (int n = 0; n < int(small[m].size()); n++)
                {
                    delta = big[i + m][j + n] - small[m][n];
                    if (delta != 0)
                    {
                        num_delta++;
                        sum_delta += delta;
                    }
                }
            }
            if (num_delta <= max_delta)
            {
                num_submatrix++;
                min_delta = min(min_delta, abs(sum_delta));
            }
        }
    }

    cout << num_submatrix << endl;
    cout << (num_submatrix == 0 ? -1 : min_delta);
}