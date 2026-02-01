#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/*Task and Objectives
Implement a function int count_leap_years(int start_year, int end_year); that takes a
given year and span and counts the total number of leap years within the range of
[start_year, end_year].Also, note that you are advised to implement a helper function,
bool is_leap_year(int year); that determines whether a year is a leap year.*/
int count = 0;
int is_leap_year(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		return year;
	else 
		return 0;
	}		
int count_leap_years(int start_year, int end_year)
{
	for (int n = start_year; n <= end_year; n++)
	{
		if (is_leap_year(n) != 0)
		{
			printf("%d\n", n);
			count++;
		}
	}
	return count;
}
int main()
{
	int s,e;
	scanf("%d %d", &s,&e);
	count_leap_years(s,e);
	printf("%d", count);
	return 0;
}
