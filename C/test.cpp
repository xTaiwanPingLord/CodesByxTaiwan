#include <stdio.h>

int F[33][33]; //陣列開在函式外面，大小比x和y的極限稍微大一點就可以了
int f(int x, int y)
{
    if (F[x][y] != -1)
        return F[x][y];

    if (x == 0)
        F[x][y] = f(x, y - 1);
    else if (y == 0)
        F[x][y] = f(x - 1, y);
    else
        F[x][y] = f(x - 1, y) + f(x, y - 1);
    return F[x][y];
}

int main()
{

    for (int i = 0; i < 33; i++)
    {

        for (int j = 0; j < 33; j++)
        {

            F[i][j] = -1;
        }
    }

    //終止條件在這裡了

    F[0][0] = 0;

    F[1][0] = 1;

    F[0][1] = 1;

    //

    printf("請輸入數值");

    int x, y, ans;

    scanf("%d %d", &x, &y);

    ans = f(x, y);

    printf("ans:%d\n", ans);

    for (int i = 0; i <= x; i++)
    {

        for (int j = 0; j <= y; j++)
        {

            printf("%d\t", F[i][j]);
        }

        printf("\n");
    }
}