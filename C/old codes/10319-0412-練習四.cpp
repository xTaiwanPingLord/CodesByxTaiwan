#include <stdio.h>
#include <stdlib.h>

int main()

{

    int select, count;

    printf("(1)排骨便當 (buy >=4 20 percent off)\n");

    printf("(2)海鮮便當\n");

    printf("(3)雞腿便當\n");

    printf("(4)魚排便當 (buy >=4 20 percent off)\n");

    printf("請輸入選項\n");

    scanf("%d", &select);

    system("cls");

    if (select == 1)
    {
        printf("排骨便當 一份75元\n");
        printf("How many do u want?\n");
        scanf("%d", &count);
        if (count >= 4)
        {
            printf("total: %f", count * 75 * 0.8);
        }
        else
        {
            printf("total: %d", count * 75);
        }
    }
    else if (select == 2)
    {

        printf("海鮮便當 一份85元\n");
        printf("How many do u want?\n");
        scanf("%d", &count);
        printf("total: %d", count * 85);
    }
    else if (select == 3)
    {

        printf("雞腿便當 一份85元\n");
        printf("How many do u want?\n");
        scanf("%d", &count);
        printf("total: %d", count * 85);
    }
    else if (select == 4)
    {

        printf("魚排便當 一份95元\n");
        printf("How many do u want?\n");
        scanf("%d", &count);
        if (count >= 4)
        {
            printf("total: %f", count * 95 * 0.8);
        }
        else
        {
            printf("total: %d", count * 95);
        }
    }
    else
    {

        printf("無此選項\n");
    }

    return 0;
}