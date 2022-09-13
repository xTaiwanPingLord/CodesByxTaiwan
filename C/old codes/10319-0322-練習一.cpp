#include <stdio.h>

int main(){
	int a, num;
	float num2;
	char c;
	printf("input a: ");
	scanf("%d", &a);
	printf("a = %d \n", a);

	printf("input num1, num2, c: ");
	scanf("%d %f %c", &num, &num2, &c);
	printf("num= %d \n", num);
	printf("num2 = %f \nc = %c \n", num2, c);


	scanf(" %c", &c);
	printf("c = %c \n", c);

	char d[10];
	scanf("%s", d);
	printf("d = %s", d);

	return 0;

}
