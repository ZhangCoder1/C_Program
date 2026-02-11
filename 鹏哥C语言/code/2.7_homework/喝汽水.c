#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，给20元，可以喝多少汽水
int main()
{
	int money = 20;
	int b = money;
	int eb = b;
	while (eb >= 2)
	{
		int nb = eb / 2;
		b += nb;
		eb = eb %2+nb;
	}
	printf("20元最多可喝%d瓶汽水\n", b);
	return 0;
}