#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int main()
{
    int c1, c2, c3;//define credits
    int g1, g2, g3;//define grades
    scanf("%d %d %d", &c1, &c2, &c3);//input credits
    scanf("%d %d %d", &g1, &g2, &g3);//input grades
    float gpa = (float)(c1 * g1 + c2 * g2 + c3 * g3) / (c1 + c2 + c3);//calculate GPA
    int result = (int)round(gpa);//round the GPAto the nearest whole number
    printf("%d\n", result);//output GPA
    return 0;
}