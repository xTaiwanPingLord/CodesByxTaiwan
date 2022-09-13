#include <stdio.h>

int main(){
	int xuehao, year, month, day;
	char name[15];

	printf("請輸入學號:");
	scanf("%d", &xuehao);

	printf("\n請輸入姓名:");
	scanf("%s", name);

	printf("\n請輸入出生年月日:");
	scanf("%d %d %d", &year, &month, &day);

	printf("\n 學號: %d", xuehao);
	printf("\n 姓名: %s", name);
	printf("\n 出生年月日: %d %d %d", year - 1911, month, day);
	printf("\n 年紀: %d", 2021 - year);

	return 0;

}
