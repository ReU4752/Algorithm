// https://www.acmicpc.net/problem/2441
// 2018-04-22

#include <stdio.h>

int main()
{
	int n;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i > j)
				printf(" ");
			else
				printf("*");
		}
		printf("\n");
	}

	return 0;
}