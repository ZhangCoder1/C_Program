#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/*Task and Objectives
Objective : Find the difference between the ¡°square of the sum¡± and the ¡°sum of the
squares¡± of the first N natural numbers.
Task : Given an unsigned integer input number(N), implement the following three
functions to accomplish the above goal.
unsigned int sum_of_squares(unsigned int number);
unsigned int square_of_sum(unsigned int number);
unsigned int difference_of_squares(unsigned int number);*/
unsigned int sum_of_squares(unsigned int input)
{
	unsigned int s = 0;
	for (unsigned int m = 0; m <= input; m++)
	{
		s += m*m;
	}
	return s;
}
unsigned int square_of_sum(unsigned int input)
{
	unsigned int s = 0;
	for (unsigned int m = 0; m <= input; m++)
	{
		s += m ;
	}
	
	return s*s;
}
unsigned int difference_of_squares(unsigned int input)
{
	return square_of_sum(input) - sum_of_squares(input);
}
int main()
{
	unsigned int input;
	scanf("%d",&input);
	printf("%d", difference_of_squares(input));
	return 0;
}