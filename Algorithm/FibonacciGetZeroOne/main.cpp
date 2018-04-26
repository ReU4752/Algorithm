// https://www.acmicpc.net/problem/1003
// 2018-04-22

#include <stdio.h>
#include <tuple>

using namespace std;

tuple<int, int, int> dp[50];

int Fibonacci(int n)
{
	if (get<0>(dp[n]) != 0)
		return get<0>(dp[n]);
	else if (n == 0)
	{
		get<1>(dp[0]) = 1;
		return 0;
	}
	else if (n == 1)
	{
		get<2>(dp[1]) = 1;
		return 1;
	}

	get<0>(dp[n]) = Fibonacci(n - 1) + Fibonacci(n - 2);
	get<1>(dp[n]) = get<1>(dp[n - 1]) + get<1>(dp[n - 2]);
	get<2>(dp[n]) = get<2>(dp[n - 1]) + get<2>(dp[n - 2]);

	return get<0>(dp[n]);
}

int main()
{
	int t;

	scanf("%d", &t);

	for (int i = 0; i < t; i++)
	{
		int n;
		scanf("%d", &n);

		Fibonacci(n);

		printf("%d %d\n", get<1>(dp[n]), get<2>(dp[n]));
	}

	return 0;
}