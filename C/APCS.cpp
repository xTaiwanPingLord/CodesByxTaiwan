#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int num;
    cin >> num;

    map<int, map<int, int>> mirrorX;
    map<int, map<int, int>> mirrorY;
    map<int, int>::iterator iter;
    int X, Y, type;
    int count = 0, dir = 3, posX = 0, posY = 0;
    for (int i = 0; i < num; i++)
    {
        cin >> X >> Y >> type;
        mirrorX[X][Y] = type;
        mirrorY[Y][X] = type;
    }

    if (mirrorY.count(0) == 0)
    {
        cout << count;
        return 0;
    }
    else // 第一次執行
    {
        iter = mirrorY[0].begin();
        posX = iter->first;
        iter->second == 0 ? dir = 0 : dir = 1;
        count++;
    }
    while (1)
    {
        // cout << "count: " << count << " | posX: " << posX << ", posY: " << posY << " | dir:" << dir << endl;
        if (dir == 0) // 上
        {
            iter = mirrorX[posX].find(posY);
            iter++;
            if (iter != mirrorX[posX].end())
            {
                posY = iter->first;
                iter->second == 0 ? dir = 3 : dir = 2;
            }
            else
            {
                cout << count;
                return 0;
            }
        }
        else if (dir == 1) // 下
        {
            iter = mirrorX[posX].find(posY);
            if (iter != mirrorX[posX].begin())
            {
                iter--;
                posY = iter->first;
                iter->second == 0 ? dir = 2 : dir = 3;
            }
            else
            {
                cout << count;
                return 0;
            }
        }
        else if (dir == 2) // 左
        {
            iter = mirrorY[posY].find(posX);
            if (iter != mirrorY[posY].begin())
            {
                iter--;
                posX = iter->first;
                iter->second == 0 ? dir = 1 : dir = 0;
            }
            else
            {
                cout << count;
                return 0;
            }
        }
        else // 右
        {
            iter = mirrorY[posY].find(posX);
            iter++;
            if (iter != mirrorY[posY].end())
            {
                posX = iter->first;
                iter->second == 0 ? dir = 0 : dir = 1;
            }
            else
            {
                cout << count;
                return 0;
            }
        }
        count++;
    }
}