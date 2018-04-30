// https://www.acmicpc.net/problem/1463
// 2018-05-01

#include <stdio.h>
#include <memory.h>

template <typename T>
const T Min(const T& left, const T& right)
{
	return (left < right) ? left : right;
}

int GetMinCount(int n, int* dp)
{
	if (n == 1) // Àç±Í Å»ÃâÁ¶°Ç
		return 0;

	int minCount = -1;

	if (dp[n] != 0)
	{
		return dp[n];
	}

	// Á¡È­½Ä
	if (n % 3 == 0)
	{
		minCount = (minCount == -1) ? GetMinCount(n / 3, dp) : Min(minCount, GetMinCount(n / 3, dp));
	}
	if (n % 2 == 0)
	{
		minCount = (minCount == -1) ? GetMinCount(n / 2, dp) : Min(minCount, GetMinCount(n / 2, dp));
	}
	
	minCount = (minCount == -1) ? GetMinCount(n - 1, dp) : Min(minCount, GetMinCount(n - 1, dp));

	return dp[n] = minCount + 1;
}

int main() 
{
	int n;
	int dp[1000001];
	
	memset(dp, 0, sizeof(int) * 1000001);

	scanf("%d", &n);

	printf("%d\n", GetMinCount(n, dp));

	return 0;
}