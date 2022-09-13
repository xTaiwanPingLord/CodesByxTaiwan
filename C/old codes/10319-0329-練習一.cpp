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
    printf("是否過輕: %d\n", (bmi < 18.5));
    printf("是否標準: %d\n", (bmi >= 18.5 && bmi < 24));
    printf("是否過重: %d\n", (bmi >= 24 && bmi < 27));
    printf("是否輕度肥胖: %d\n", (bmi >= 27 && bmi < 30));
    printf("是否中度肥胖: %d\n", (bmi >= 30 && bmi < 35));
    printf("輕度重度肥胖: %d\n", (bmi >= 35));
    return 0;
}
