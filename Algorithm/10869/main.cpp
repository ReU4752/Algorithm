// https://www.acmicpc.net/problem/10869
// 2019-11-07

#include <stdio.h>

int main()
{
	int a, b;

	scanf("%d %d", &a, &b);
	printf("%d\n%d\n%d\n%d\n%d", a + b, a - b, a*b, a / b, a%b);

	return 0;
}