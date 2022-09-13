#include <stdio.h>
int main()
{
    int count = 0, num, output = 0;
    printf("1+2+3....?");
    scanf("%d", &num);
    while (count < num)
    {
        count++;
        output = output + count;
        //printf("%d\n", output);
    }
    printf("1+2+3...+%d=%d\n", num, output);
}