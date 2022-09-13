#include <stdio.h>

int main(){
	int i = 0;
	i = i + 1;
	printf("%d\n", i);

	int c = 10, d = 5, temp;
	printf("c = %d d = %d temp = %d\n", c, d ,temp);
	temp = c;
	c = d;
	d = temp;
	printf("c = %d d = %d temp = %d\n", c, d ,temp);
	return 0;

}
