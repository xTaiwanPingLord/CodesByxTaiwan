#include <stdio.h>

int main()
{
    int a, b;
    char c;
    scanf("%d %c %d", &a, &c, &b);
    if (c == '+')
    {
        printf("%d", a + b);
    }
    else if (c == '-')
    {
        printf("%d", a - b);
    }
    else if (c == '*')
    {
        printf("%d", a * b);
    }
    else if (c == '/')
    {
        if( b == 0){
            printf("can not devide by zero");
        }else{
            printf("%d", a / b);
        }
        
    }
    return 0;
}
