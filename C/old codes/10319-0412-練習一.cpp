#include <stdio.h>

int main()
{
	int score;
	printf("input score:");
	scanf("%d", &score);

	if (score >= 80)
	{
		score *= 1.05;
	}
	else if (score >= 60)
	{
		score *= 1.1;
	}
	else
	{
		score *= 1.2;
	}
	printf("score = %d\n", score);
	return 0;
}
