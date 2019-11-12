// https://www.acmicpc.net/problem/10989
// 2019-11-12

#include <stdio.h>
#include <string.h>

int counting[10001];
int maxNum;

int main()
{
	memset(counting, 0, sizeof(counting));

	int N = 0;

	scanf("%d", &N);
	
	maxNum = 0;
	for (int i = 0; i < N; i++)
	{
		int number;
		scanf("%d", &number);

		counting[number]++;

		if (number > maxNum)
			maxNum = number;
	}

	for (int i = 0; i <= maxNum; i++)
	{
		for (int j = 0; j < counting[i]; j++)
			printf("%d\n", i);
	}

	return 0;
}