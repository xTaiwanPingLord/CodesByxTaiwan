#include <stdio.h>
int main()
{
    int key = 123, input, times = 0;
    printf("enter your password:");
    scanf("%d", &input);
    while (key != input && times < 2)
    {
        times++;
        printf("wrong password\n");
        printf("enter your password:");
        scanf("%d", &input);
    }
    if (key == input)
    {
        printf("correct password\n");
    }
    else
    {
        printf("Locked");
    }
}