// https://www.acmicpc.net/problem/2440
// 2018-04-22

#include <stdio.h>

int main()
{
	int n = 0;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		for (int j = n - i; j > 0; j--)
		{
			printf("*");
		}
		printf("\n");
	}

	return 0;
}