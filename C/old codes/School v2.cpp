#include <iostream>
#include <math.h>
using namespace ::std;

int main()
{
    int wish = 0, pity = 73, hardPity = 90;
    float wCeli = 10000, w5star = 60, w5starPity = 600, expected = 0, expectedUP = 0;
    float chanceCalc[hardPity - 1], totalChanceCalc[hardPity - 1];
    float chance[hardPity * 2 - 1] = {0}, totalChance[hardPity * 2 - 1] = {0};

    for (wish = 0; wish < pity; wish++)
    {
        chanceCalc[wish] = (w5star / wCeli) * pow(1 - (w5star / wCeli), wish); //本抽機率(等比級數)
        totalChanceCalc[wish] = 1 - pow(1 - (w5star / wCeli), wish + 1);       //累積機率
        expected = expected + chanceCalc[wish] * (wish + 1);
    }

    for (wish = pity; wish < hardPity; wish++) //開始不是等比級數了，需要用正常的機率算法
    {
        chanceCalc[wish] = ((1 - totalChanceCalc[wish - 1]) * (w5star + w5starPity * (wish + 1 - pity))) / wCeli;
        totalChanceCalc[wish] = totalChanceCalc[wish - 1] + chanceCalc[wish];
        expected = expected + chanceCalc[wish] * (wish + 1);
    }

    chance[0] = chanceCalc[0] / 2;
    totalChance[0] = chance[0];
    cout << "第1抽時的機率: " << chance[0] * 100 << "%, 累積機率:" << totalChance[0] * 100 << "%" << endl;

    for (int i = 1; i < hardPity*2; i++)
    {
        if (i < hardPity)
        {
            chance[i] = chanceCalc[i] / 2;
            for (int j = 0; j < i; j++)
            {
                chance[i] = chance[i] + chanceCalc[j] * chanceCalc[i - j - 1] / 2; // sum of chance of (1+3 2+2 3+1)....
            }
        }
        else
        {
            for (int j = i - hardPity; j < hardPity; j++) //超過90抽 就會變成從 i - 90 到 i。 如93 = (93 - 90) + 90 / (93 - 90 + 1) + 89..... (93 - 90 + 93) + 3
            {
                chance[i] = chance[i] + chanceCalc[j] * chanceCalc[i - j - 1] / 2;
                // cout << j << "   i: " << i << " : " << chance[i] << "  calc: " << chanceCalc[j] << " * " << chanceCalc[i - j - 1] << endl; //sum of chance of (1+90 2+89 3+88)....
            }
        }

        totalChance[i] = totalChance[i - 1] + chance[i];
        cout << "第" << i + 1 << "抽時的機率: " << chance[i] * 100 << "%, 累積機率:" << totalChance[i] * 100 << "%" << endl;
        expectedUP = expectedUP + chance[i] * (i + 1);
    }
    cout << "五星期望抽數:" << expected << "   UP五星期望抽數:" << expectedUP << endl;

    return 0;
}
