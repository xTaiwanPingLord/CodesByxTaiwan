#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int main()
{
    // vector<int> b = {0, 1, 4, 3};
    // vector<int> p = {0, 1500, 3000, 2000};
    // vector<vector<int>> dp(4, vector<int>(5));

    vector<int> b = {0, 15, 30, 20, 29, 1};
    vector<int> p = {0, 1500, 3000, 2000, 2999, 200};
    vector<vector<int>> dp(6, vector<int>(36));

    int n, m;
    for (int i = 1; i <= 5; i++)
    {
        for (int j = 1; j <= 35; j++)
        {
            n = dp[i - 1][j];
            if (j - b[i] >= 0) // 放得下
                m = p[i] + dp[i - 1][j - b[i]];
            else
                m = 0;
            dp[i][j] = max(n, m);
        }
    }

    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 36; j++)
            printf("%d\t", dp[i][j]);
        printf("\n");
    }
}
