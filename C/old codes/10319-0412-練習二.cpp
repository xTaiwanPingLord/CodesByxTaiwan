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
    if (bmi < 18.5)
    {
        printf("�L��\n");
    }
    else if (bmi >= 18.5 && bmi < 24)
    {
        printf("�з�\n");
    }
    else if (bmi >= 24 && bmi < 27)
    {
        printf("�L��\n");
    }
    else if (bmi >= 27 && bmi < 30)
    {
        printf("���תέD\n");
    }
    else if (bmi >= 30 && bmi < 35)
    {
        printf("���תέD\n");
    }
    else
    {
        printf("���תέD\n");
    }

    return 0;
}
