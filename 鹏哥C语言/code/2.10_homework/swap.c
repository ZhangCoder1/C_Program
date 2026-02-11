#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//不允许创建临时变量，交换两个整数的内容
int main() {
	int a, b;
	printf("请输入两个整数：");
	scanf("%d %d", &a, &b);
	printf("交换前：a = %d, b = %d\n", a, b);
	a = a ^ b; // a now holds the result of a XOR b
	b = a ^ b; // b now holds the original value of a
	a = a ^ b; // a now holds the original value of b
	printf("交换后：a = %d, b = %d\n", a, b);
	return 0;
}