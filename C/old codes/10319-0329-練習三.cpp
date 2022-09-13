#include <stdio.h>

int main()
{
    int score;
    printf("input score: ");
    scanf("%d", &score);
    if (score >= 60)
        printf("score: %.0f", score * 1.1);
    else
        printf("score: %.0f", score * 1.2);
    
    return 0;
}
