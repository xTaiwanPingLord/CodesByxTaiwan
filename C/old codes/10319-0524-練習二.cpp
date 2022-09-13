#include <stdio.h>
int main()
{
    int score[3], people;
    printf("請輸入人數\n");
        scanf("%d", &people);
    printf("請輸入成績\n");
    for (int i = 0; i < people; i++)
    {
       scanf("%d", &score[i]); 
    }
    for (int i = 0; i < people; i++)
    {
       if (score[i] < 60)
        {
            score[i] *= 1.2;
        } 
        printf("分數為 %d\n", score[i]);
    }


    return 0;
}