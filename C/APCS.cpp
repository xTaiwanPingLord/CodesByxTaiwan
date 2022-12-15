#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int people, num_eliminate, loop;
    uint64_t a, b, c, d;
    cin >> people >> num_eliminate;
    vector<uint64_t> S(people, 0), T(people, 0);
    vector<int> idx(people, 0), eliminate(people, 0);

    for (uint64_t &i : S)
    {
        cin >> i;
    }
    for (uint64_t &i : T)
    {
        cin >> i;
    }
    for (int &i : idx)
    {
        cin >> i;
        i--;
    }

    while (idx.size() != 1)
    {
        // loop = (uint64_t)idx.size();
        loop = (uint64_t)idx.size() / 2;
        for (int i = 0; i < loop; i++)
        {
            // cout << loop;
            a = S[idx[i]];
            b = T[idx[i]];
            c = S[idx[i + 1]];
            d = T[idx[i + 1]];

            if (a*b >= c*d)
            {
                S[idx[i]] = a + (c * d) / (2 * b);
                T[idx[i]] = b + (c * d) / (2 * a);
                S[idx[i + 1]] = c + c / 2;
                T[idx[i + 1]] = d + d / 2;
                eliminate[idx[i + 1]]++;
                if (eliminate[idx[i + 1]] < num_eliminate)
                {
                    // cout << " case1 " << endl;
                    idx.push_back(idx[i + 1]);
                    idx.erase(idx.begin() + i + 1);
                }
                else
                {
                    // cout << " case2 " << endl;
                    idx.erase(idx.begin() + i + 1);
                }
            }
            else
            {
                S[idx[i]] = a + a / 2;
                T[idx[i]] = b + b / 2;
                S[idx[i + 1]] = c + (a * b) / (2 * d);
                T[idx[i + 1]] = d + (a * b) / (2 * c);
                eliminate[idx[i]]++;
                if (eliminate[idx[i]] < num_eliminate)
                {
                    // cout << " case3 " << endl;
                    idx.push_back(idx[i]);
                    idx.erase(idx.begin() + i);
                }
                else
                {
                    // cout << " case4 " << endl;
                    idx.erase(idx.begin() + i);
                }
            }
        }
    }
    cout << idx[0] + 1;
}