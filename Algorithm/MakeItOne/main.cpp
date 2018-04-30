#include <stdio.h>

template <typename T>
const T Min(const T& left, const T& right)
{
	return (left < right) ? left : right;
}

int GetMinCount(int n)
{
	if (n == 1) // Àç±Í Å»ÃâÁ¶°Ç
		return 0;

	int minCount = -1;

	// Á¡È­½Ä
	if (n % 3 == 0)
	{
		minCount = (minCount == -1) ? GetMinCount(n / 3) : Min(minCount, GetMinCount(n / 3));
	}
	if (n % 2 == 0)
	{
		minCount = (minCount == -1) ? GetMinCount(n / 2) : Min(minCount, GetMinCount(n / 2));
	}
	
	minCount = (minCount == -1) ? GetMinCount(n - 1) : Min(minCount, GetMinCount(n - 1));

	return minCount + 1;
}

int main() 
{
	int n;

	scanf("%d", &n);

	printf("%d\n", GetMinCount(n));

	return 0;
}