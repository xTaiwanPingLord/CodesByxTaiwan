#include <iostream>
#include <math.h>
using namespace ::std;

int main()
{
    int wish = 0, pity = 73;
    float wCeli = 10000, w5star = 60, w5starPity = 600, chance = 0, totalChance = 0, expected = 0;

    for (wish = 0; wish < pity; wish++)
    {
        chance = (w5star / wCeli) * pow(1 - (w5star / wCeli), wish); //本抽機率(等比級數)
        totalChance = 1 - pow(1 - (w5star / wCeli), wish+1);         //累加機率
        expected = expected + chance * (wish + 1);
        cout << "第" << wish + 1 << "抽時的機率: " << chance * 100 << "%, 累進機率:" << totalChance * 100 << "%" << endl;
    }

    cout << "機率提升" << endl;

    for (wish = pity; totalChance < 1; wish++) //開始不是等比級數了，需要用正常的機率算法
    {
        chance = ((1 - totalChance) * (w5star + w5starPity * (wish + 1 - pity))) / wCeli;
        totalChance = totalChance + chance;
        expected = expected + chance * (wish + 1);
        cout << "第" << wish + 1 << "抽時的機率: " << chance * 100 << "%, 累進機率:" << totalChance * 100 << "%" << endl;
    }
    cout << "期望抽數:" << expected << endl;
    return 0;
}