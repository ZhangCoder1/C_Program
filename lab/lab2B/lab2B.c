#include<stdio.h>
#include<stdlib.h>
#define max(a, b)((a) > (b)) ? (a) : (b)
void transpose(int* matrix, int m, int n, int ld)
{
	for (int i = 0; i < ld; i++)
	{
		for (int j = i + 1; j< ld; j++)
		{
			matrix[i * ld + j] = matrix[i * ld + j] ^ matrix[j * ld + i];
			matrix[j * ld + i] = matrix[j * ld + i] ^ matrix[i * ld + j];
			matrix[i * ld + j] = matrix[i * ld + j] ^ matrix[j * ld + i];
		}
	}
}
int main()
{
	int m, n;
	scanf_s("%d%d", &m, &n);
	int ld = max(m, n);//leading dimension
	int* matrix;
	matrix = (int*)malloc(ld * ld * sizeof(int));

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf_s("%d", &matrix[i * ld + j]);
		}
	}
	transpose(matrix, m, n, ld);
	for (int j = 0; j < n; ++j) {
		for (int i = 0; i < m; ++i) {
			printf("%d", matrix[j * ld + i]);
		}
	}
	return 0;
}