#include <stdio.h>
int main()
{
    float input = 0, count = 0, sum = 0, max = 0;
    while (1)
    {
        printf("input a number:");
        scanf("%f", &input);
        if (input == -1)
        {
            break;
        }

        sum = sum + input;
        count++;
        if (input > max)
        {
            max = input;
        }
    }
    printf("\n Sum=%f", sum);
    printf("\n Avg=%f", sum / count);
    printf("\n Max:%f", max);
}