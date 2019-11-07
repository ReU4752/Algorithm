// https://www.acmicpc.net/problem/1008
// 2019-11-07

#include <stdio.h>

int main()
{
	int a, b;
	
	scanf("%d %d", &a, &b);
	// Memo : 상대오차가 10^-9 이하이어야한다면
	// 상대오차가 10^-7 정도인 float이 아닌 10^-15정도인 double을 쓰라는 이야기.
	printf("%.15g", (double)a / b);

	return 0;
}