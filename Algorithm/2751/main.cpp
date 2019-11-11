// https://www.acmicpc.net/problem/2751
// 2019-11-11

#include <stdio.h>
#include <string.h>

int arr[1000001];
int temp[1000001];
int N;

void Merge(int left, int mid, int right)
{
	int i = left;
	int j = mid + 1;
	int insertIdx = left;

	// merge partitiated list
	while (i <= mid && j <= right)
	{
		if (arr[i] <= arr[j])
			temp[insertIdx++] = arr[i++];
		else
			temp[insertIdx++] = arr[j++];
	}

	// merge remaining things.
	if (i > mid)
	{
		for (int l = j; l <= right; l++)
		{
			temp[insertIdx++] = arr[l];
		}
	}
	else
	{
		for (int l = i; l <= mid; l++)
		{
			temp[insertIdx++] = arr[l];
		}
	}

	// copy
	for (insertIdx = left; insertIdx <= right; insertIdx++)
	{
		arr[insertIdx] = temp[insertIdx];
	}
}

void MergeSort(int left, int right)
{
	if (left < right)
	{
		int mid = (left + right) / 2;

		// partition
		MergeSort(left, mid);
		MergeSort(mid + 1, right);
		// combine
		Merge(left, mid, right);
	}
}

int main()
{
	memset(arr, 0, sizeof(arr));
	memset(temp, 0, sizeof(temp));
	N = 0;

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}

	MergeSort(0, N - 1);

	for (int i = 0; i < N; i++)
	{
		printf("%d\n", arr[i]);
	}

	return 0;
}