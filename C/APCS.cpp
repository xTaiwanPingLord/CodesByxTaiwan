#include <iostream>
#include <vector>
using namespace std;

int R, C, n, pos, blocks, ins, Max;
char type;

int main()
{
    cin >> R >> C >> n;
    vector<int> peak(R);

    for (int i = 0; i < n; i++)
    {
        cin >> type >> pos;
        Max = -1;

        if (type == 'A')
        {
            for (int j = 0; j < 4; j++)
            {
                Max = max(Max, peak[pos + j]);
            }
            if (Max < C)
            {
                ins++;
                for (int j = 0; j < 4; j++)
                {
                    blocks++;
                    peak[pos + j] = Max + 1;
                }
            }
        }
        else if (type == 'B')
        {
            if ((peak[pos] + 2) < C)
            {
                ins++;
                blocks += 3;
                peak[pos] += 3;
            }
        }
        else if (type == 'C')
        {
            Max = max(peak[pos], peak[pos + 1]);
            if ((Max + 1) < C)
            {
                ins++;
                blocks += 4;
                peak[pos] = Max + 2;
                peak[pos + 1] = Max + 2;
            }
        }
        else if (type == 'D')
        {
            Max = max(peak[pos], peak[pos + 1] + 2);
            if (Max < C)
            {
                ins++;
                blocks += 4;
                peak[pos] = Max + 1;
                peak[pos + 1] = peak[pos];
            }
        }
        else if (type == 'E')
        {
            Max = max(peak[pos + 1], peak[pos + 2]) + 1;
            Max = max(Max, peak[pos]);
            if (Max < C)
            {
                ins++;
                blocks += 5;
                peak[pos] = Max + 1;
                peak[pos + 1] = peak[pos];
                peak[pos + 2] = peak[pos];
            }
        }
    }

    cout << R * C - blocks << " " << n - ins;
}