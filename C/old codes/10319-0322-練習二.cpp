#include <stdio.h>

int main(){
	int xuehao, year, month, day;
	char name[15];

	printf("�п�J�Ǹ�:");
	scanf("%d", &xuehao);

	printf("\n�п�J�m�W:");
	scanf("%s", name);

	printf("\n�п�J�X�ͦ~���:");
	scanf("%d %d %d", &year, &month, &day);

	printf("\n �Ǹ�: %d", xuehao);
	printf("\n �m�W: %s", name);
	printf("\n �X�ͦ~���: %d %d %d", year - 1911, month, day);
	printf("\n �~��: %d", 2021 - year);

	return 0;

}
