#include <stdio.h>
#include <stdlib.h>

int main()

{

    int select, count;

    printf("(1)�ư��K�� (buy >=4 20 percent off)\n");

    printf("(2)���A�K��\n");

    printf("(3)���L�K��\n");

    printf("(4)���ƫK�� (buy >=4 20 percent off)\n");

    printf("�п�J�ﶵ\n");

    scanf("%d", &select);

    system("cls");

    if (select == 1)
    {
        printf("�ư��K�� �@��75��\n");
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

        printf("���A�K�� �@��85��\n");
        printf("How many do u want?\n");
        scanf("%d", &count);
        printf("total: %d", count * 85);
    }
    else if (select == 3)
    {

        printf("���L�K�� �@��85��\n");
        printf("How many do u want?\n");
        scanf("%d", &count);
        printf("total: %d", count * 85);
    }
    else if (select == 4)
    {

        printf("���ƫK�� �@��95��\n");
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

        printf("�L���ﶵ\n");
    }

    return 0;
}