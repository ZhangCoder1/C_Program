#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//获取一个整数二进制序列中所有的偶数位和奇数位，分别打印出二进制序列
void printBits(unsigned num) 
{
    // 偶数位：按从高位到低位顺序打印，位编号以最低位为 0
    printf("偶数位：");
    for (int i = 31; i >= 0;i--) {
        if ((i % 2) == 0) {
            printf("%d", (num >> i) & 1);
        }
        else
        {
			printf("%d",0);
        }
	}
    // 奇数位
    printf("\n奇数位：");
    for (int i = 31; i >= 0;i--) {
        if ((i % 2) != 0) {
            printf("%d", (num >> i) & 1);
        }
        else
            {
            printf("%d",0);
		}
    }
    printf("\n");
}
int main() 
{
	int n;
	printf("请输入一个整数：");
	scanf("%d", &n);
	printBits(n);
	return 0;
}