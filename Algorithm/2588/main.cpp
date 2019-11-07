// https://www.acmicpc.net/problem/2588
// 2019-11-07

#include <stdio.h>

int main()
{
	int nA, nB;

	scanf("%d %d", &nA, &nB);

	int tempNB = nB;
	int r3 = nA * (tempNB / 100);
	tempNB = tempNB % 100;
	int r2 = nA * (tempNB / 10);
	tempNB = tempNB % 10;
	int r1 = nA * (tempNB / 1);

	printf("%d\n%d\n%d\n%d\n", r1, r2, r3, nA*nB);

	return 0;
}