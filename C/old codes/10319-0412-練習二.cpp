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
        printf("過輕\n");
    }
    else if (bmi >= 18.5 && bmi < 24)
    {
        printf("標準\n");
    }
    else if (bmi >= 24 && bmi < 27)
    {
        printf("過重\n");
    }
    else if (bmi >= 27 && bmi < 30)
    {
        printf("輕度肥胖\n");
    }
    else if (bmi >= 30 && bmi < 35)
    {
        printf("中度肥胖\n");
    }
    else
    {
        printf("重度肥胖\n");
    }

    return 0;
}
