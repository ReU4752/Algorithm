// https://www.acmicpc.net/problem/2750
// 2019-11-11

#include <stdio.h>
#include <string.h>

int N;
int g_arr[1001];

void InsertionSort()
{
	for (int keyIdx = 1; keyIdx < N; keyIdx++)
	{
		for (int i = keyIdx - 1; i >= 0; i--)
		{
			if (g_arr[i] > g_arr[i + 1])
			{
				int temp = g_arr[i];
				g_arr[i] = g_arr[i + 1];
				g_arr[i + 1] = temp;
			}
		}
	}
}

int main()
{
	N = 0;
	memset(g_arr, 0, sizeof(g_arr));

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		int num = 0;
		
		scanf("%d", &num);
		g_arr[i] = num;
	}

	InsertionSort();

	for (int i = 0; i < N; i++)
	{
		printf("%d\n", g_arr[i]);
	}

	return 0;
}