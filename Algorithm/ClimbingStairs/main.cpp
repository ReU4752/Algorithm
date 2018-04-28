// https://www.acmicpc.net/problem/2579
// 2018-04-29

#include <stdio.h>
#include <memory.h>

template <typename T>
const T& MAX(const T& l, const T& r)
{
	return (l > r) ? l : r;
}

int main()
{
	int stair[301];
	int cache[301];
	int numStairs = 0;

	memset(stair, 0, sizeof(int) * 301);
	memset(cache, 0, sizeof(int) * 301);

	scanf("%d", &numStairs);

	for (int i = 0; i < numStairs; i++)
	{
		scanf("%d", &stair[i]);
	}

	cache[0] = stair[0];
	cache[1] = MAX(stair[0] + stair[1], stair[1]);
	cache[2] = MAX(stair[0] + stair[2], stair[1] + stair[2]);
	for (int i = 3; i < numStairs; i++)
	{
		cache[i] = MAX(cache[i - 3] + stair[i - 1] + stair[i], cache[i - 2] + stair[i]);
	}

	printf("%d\n", cache[numStairs - 1]);

	return 0;
}