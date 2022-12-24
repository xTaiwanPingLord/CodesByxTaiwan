#include <bits/stdc++.h>
using namespace std;

void DrawColor(vector<vector<int>> &blocks, const int &size, const int &op, const int &line, const int &color)
{
    int ver, hor;
    if (op == 1)
    {
        if (line <= size) // get starting point
        {
            ver = 0;
            hor = size - line;
        }
        else
        {
            ver = line - size;
            hor = 0;
        }

        while (ver < size && hor < size) // iterate
        {
            if (blocks[ver][hor] < color)
                blocks[ver][hor] = color;
            hor++;
            ver++;
        }
    }
    else if (op == 2)
    {
        if (line <= size) // get starting point
        {
            ver = 0;
            hor = line - 1;
        }
        else
        {
            ver = line - size;
            hor = size - 1;
        }

        while (ver < size && hor >= 0) // iterate
        {
            if (blocks[ver][hor] < color)
                blocks[ver][hor] = color;
            hor--;
            ver++;
        }
    }
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int size, count;
    cin >> size >> count;

    vector<vector<int>> blocks(size, vector<int>(size, 0));

    int op, line, color;
    for (int loop = 0; loop < count; loop++)
    {
        cin >> op >> line >> color;
        DrawColor(blocks, size, op, line, color);
    }

    for (const vector<int> &i : blocks)
    {
        for (const int &j : i)
        {
            cout << j << " ";
        }
        cout << "\n";
    }
}