#include <stdio.h>
int main()
{

    printf("%d\n", sizeof(int));
    printf("%d\n", sizeof(float));
    printf("%d\n", sizeof(char));
    printf("%d\n", sizeof(double));
    char c2[3] = "§A";
    printf("c=%s\n", c2);
    char c3[5] = "§A¦n";
    printf("c=%s\n", c3);

    return 0;
}
