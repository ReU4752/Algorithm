// https://www.acmicpc.net/problem/9461
// 2018-04-22

#include <stdio.h>

long long dp[101];

long long Padoban(long long n)
{
	if (n > 0 && n < 4)
		return 1;
	else if (n > 3 && n < 6)
		return 2;

	if (dp[n] != 0)
		return dp[n];

	return dp[n] = Padoban(n - 1) + Padoban(n - 5);
}

int main()
{
	int t;

	scanf("%d", &t);

	for (int i = 0; i < t; i++)
	{
		int n;

		scanf("%d", &n);

		printf("%lld\n", Padoban(n));
	}

	return 0;
}