// https://www.acmicpc.net/problem/1008
// 2019-11-07

#include <stdio.h>

int main()
{
	int a, b;
	
	scanf("%d %d", &a, &b);
	// Memo : �������� 10^-9 �����̾���Ѵٸ�
	// �������� 10^-7 ������ float�� �ƴ� 10^-15������ double�� ����� �̾߱�.
	printf("%.15g", (double)a / b);

	return 0;
}