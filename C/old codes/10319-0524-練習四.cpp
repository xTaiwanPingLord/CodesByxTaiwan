#include <stdio.h>
int main()
{
    int score1[10] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 10; i++)
    {
        printf("%d\n", score1[i]);
    }

    printf("\n");
    int score2[10] = {0};
    for (int i = 0; i < 10; i++)
    {
        printf("%d\n", score2[i]);
    }

    printf("\n");
    int score3[] = {1, 2, 3, 4, 5, 6, 7};
    int arraylen = sizeof(score3) / sizeof(int);

    for (int i = 0; i < arraylen; i++)
    {
        printf("%d\n", score3[i]);
    }
}