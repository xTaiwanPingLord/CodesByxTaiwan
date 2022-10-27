#include <stdio.h>

int array[10000] = {0};
int f(int n)
{

	if (n < 3)
	{
		return array[n];
	}
	// if (n == 3)
	// {
	// 	return 2;
	// }
	if (array[n] != 0)
	{
		return array[n];
	}
	array[n] = f(n - 1) + f(n - 3);
	return array[n];
}

int main()
{
	array[0] = 0;
	array[1] = 1;
	array[2] = 1;
	int ans;
	int input;
	printf("請輸入數值");
	scanf("%d", &input);
	ans = f(input);
	printf("答案:%d \n", ans);
}