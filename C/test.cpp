#include <cstring> //memset()
#include <iostream>
#include <queue> //queue
#include <tuple> //tuple
#define int long long

using namespace std;
int min_high = 1e9, n;
int area[305][305] = {0};
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
bool inrange(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < n;
}

queue<tuple<int, int, int>> q;
int visited[305][305] = {0};
int bfs(int m)
{
    q.push({0, 0, 0});
    visited[0][0] = 1;
    while (!q.empty())
    {
        int x = get<0>(q.front());
        int y = get<1>(q.front());
        int step = get<2>(q.front());
        visited[x][y] = 1;
        q.pop();
        if (x == n - 1 && y == n - 1)
        {
            return step; // true
        }
        for (int i = 0; i < 4; i++)
        {
            int newx = x + dir[i][0];
            int newy = y + dir[i][1];
            if (inrange(newx, newy) && !visited[newx][newy])
            {
                int high = abs(area[x][y] - area[newx][newy]);
                if (high <= m)
                {
                    visited[newx][newy] = 1;
                    q.push({newx, newy, step + 1});
                }
            }
        }
    }
    return -1; // false
}
void init()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> area[i][j];
        }
    }
}
void clean()
{
    while (!q.empty())
        q.pop();
    memset(visited, 0, sizeof(visited));
}
signed main()
{
    init();
    int L = 0, R = 1e7;
    while (R - L > 1)
    {
        int m = L + (R - L) / 2;
        clean();
        int step = bfs(m);
        if (step != -1)
        {
            R = m;
        }
        else
            L = m;
    }
    clean();
    cout << R << "\n"
         << bfs(R) << "\n";
    return 0;
}