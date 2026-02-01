#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
float series(float r1, float r2)//calculate serie resistance
{
    return r1 + r2;
}
float parallel(float r1, float r2)//calculate parallel resistance
{
    float a = 1.0f / r1 + 1.0f / r2;
    return 1.0f / a;
}
float Ohm_law(float total_r)//calculate electricity current in mA
{
    float U = 12.0f;
    return (U / total_r) * 1000.0f;
}
int main()
{
    int r1, r2, r3, r4, r5, r6, r7, r8;
    scanf("%d %d %d %d %d %d %d %d", &r1, &r2, &r3, &r4, &r5, &r6, &r7, &r8);
    float r67 = parallel((float)r6, (float)r7);
    float r567 = series((float)r5, (float)r67);
    float r5678 = series((float)r567, (float)r8);
    float r45678 = parallel((float)r4, (float)r5678);
    float r12 = series((float)r1, (float)r2);
    float r123 = parallel((float)r12, (float)r3);
    float total_r = parallel((float)r123, (float)r45678);
    float I = Ohm_law(total_r);//calculate current
    printf("%.2f\n", I);
    return 0;
}