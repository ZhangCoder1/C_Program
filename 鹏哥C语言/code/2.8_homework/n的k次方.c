#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
long long pow(int n, int k)
{
	if (k == 0)
		return 1;
	else
		return pow(n, k - 1) * n;
}
int main()
{
	int n,k;
	scanf("%d%d", &n,&k);
	printf("%d", pow(n, k));
	return 0;
}