#include <stdio.h>
int main()
{
    int score[3], people;
    printf("�п�J�H��\n");
        scanf("%d", &people);
    printf("�п�J���Z\n");
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
        printf("���Ƭ� %d\n", score[i]);
    }


    return 0;
}