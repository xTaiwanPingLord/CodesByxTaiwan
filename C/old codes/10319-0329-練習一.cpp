#include <stdio.h>

int main()
{
    float weight, height, bmi;

    printf("input height:");
    scanf("%f", &height);
    printf("input weight:");
    scanf("%f", &weight);

    height = height / 100;
    bmi = (weight / (height * height));
    printf("BMI: %.2f\n", bmi);
    printf("�O�_�L��: %d\n", (bmi < 18.5));
    printf("�O�_�з�: %d\n", (bmi >= 18.5 && bmi < 24));
    printf("�O�_�L��: %d\n", (bmi >= 24 && bmi < 27));
    printf("�O�_���תέD: %d\n", (bmi >= 27 && bmi < 30));
    printf("�O�_���תέD: %d\n", (bmi >= 30 && bmi < 35));
    printf("���׭��תέD: %d\n", (bmi >= 35));
    return 0;
}
