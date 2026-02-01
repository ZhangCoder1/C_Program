#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int gcd(int a, int b)
{
    if (b == 0) return a;
    return gcd(b, a % b);
}//Calculate the greatest common divisor of two numbers.
int main()
{
    int n, a0;
    scanf_s("%d %d", &n, &a0);
    int d = 0;
    srand(time(NULL));
    int num;
    if (n - 1 <= 30)
    {
        num = n - 1;
    }
    else
    {
        num = 30;
    }
    int differ[30] = { 0 }; //Store the queried index
    for (int count = 0; count < num; count++)
    {
        int idx = rand() % (n - 1) + 1; //Randomly generate index
        int used_idx = 0;
        for (int i = 0; i < count; i++)
        {
            if (differ[i] == idx)
            {
                used_idx = 1;
                break;
            }
        }//Check if the index has been queried before
        if (used_idx)
        {
            continue;
        }//Skip duplicate indexes
        printf("? %d\n", idx);
        fflush(stdout);
        int a_i;
        scanf_s("%d", &a_i);
        int diff = a_i - a0;
        d = gcd(d, abs(diff));//Renew gcd
        differ[count] = idx; //Recorded query index
    }
    printf("! %d\n", d);
    fflush(stdout);
    return 0;
}
