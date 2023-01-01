#include <bits/stdc++.h>
using namespace std;

void print(const vector<vector<int>> &input)
{
    cout << "area: \n";
    for (auto &i : input)
    {
        for (auto &j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

int calc(const vector<vector<int>> &input)
{
    int count = 0;
    for (auto &i : input)
    {
        for (auto &j : i)
        {
            if (j != 0)
            {
                count++;
            }
        }
    }
    return count;
}

bool checkLR(const vector<vector<int>> &input, int &row, int &col)
{
    if (col == 0 || row == input[0].size() || input[row][col] == 0)
        return false;
    bool first = false, last = false;
    for (int i = col + 1; i < input[0].size(); i++)
    {
        if (input[row][i] == 1)
            first = true;
    }
    for (int i = col - 1; i >= 0; i--)
    {
        if (input[row][i] == 1)
            last = true;
    }
    return first && last;
}

bool checkUD(const vector<vector<int>> &input, int &row, int &col)
{
    if (row == 0 || row == input.size() || input[row][col] == 0)
        return false;
    bool first = false, last = false;
    for (int i = row + 1; i < input.size(); i++)
    {
        if (input[i][col] == 1)
            first = true;
    }
    for (int i = row - 1; i >= 0; i--)
    {
        if (input[i][col] == 1)
            last = true;
    }
    return first && last;
}

int main()
{
    int m, n, h;
    cin >> m >> n >> h;
    vector<vector<int>> field(m, vector<int>(n, 0));

    int r, c, t, area_now = 0, area_max = -1, target_r, target_c;
    for (int i = 0; i < h; i++)
    {
        cin >> r >> c >> t;

        field[r][c] = (t == 0) ? 1 : 0;
        if (c != n - 1)
        {
            target_c = -1;
            for (int j = c + 1; j < n; j++) // 向右
            {
                if (field[r][j] == 1)
                {
                    target_c = j;
                    break;
                }
            }
            if (target_c != -1)
            {
                for (int j = c + 1; j < target_c; j++)
                {
                    if (!checkUD(field, r, j) && t == 1)
                        field[r][j] = 0;
                    else if (t == 0)
                        field[r][j] = 2;
                }
            }
        }

        if (c != 0)
        {
            target_c = -1;
            for (int j = c - 1; j >= 0; j--) // 向左
            {
                if (field[r][j] == 1)
                {
                    target_c = j;
                    break;
                }
            }
            if (target_c != -1)
            {
                for (int j = c - 1; j > target_c; j--)
                {
                    if (!checkUD(field, r, j) && t == 1)
                        field[r][j] = 0;
                    else if (t == 0)
                        field[r][j] = 2;
                }
            }
        }

        if (r != m - 1)
        {
            target_r = -1;
            for (int j = r + 1; j < m; j++) // 向下
            {
                if (field[j][c] == 1)
                {
                    target_r = j;
                    break;
                }
            }
            if (target_r != -1)
            {
                for (int j = r + 1; j < target_r; j++)
                {
                    if (!checkLR(field, j, c) && t == 1)
                        field[j][c] = 0;
                    else if (t == 0)
                        field[j][c] = 2;
                }
            }
        }
        if (r != 0)
        {
            target_r = -1;
            for (int j = r - 1; j >= 0; j--) // 向上
            {
                if (field[j][c] == 1)
                {
                    target_r = j;
                    break;
                }
            }
            if (target_r != -1)
            {
                for (int j = r - 1; j > target_r; j--)
                {
                    if (!checkLR(field, j, c) && t == 1)
                        field[j][c] = 0;
                    else if (t == 0)
                        field[j][c] = 2;
                }
            }
        }
        // print(field);
        area_now = calc(field);
        area_max = max(area_now, area_max);
    }
    cout << area_max << "\n"
         << area_now;
}