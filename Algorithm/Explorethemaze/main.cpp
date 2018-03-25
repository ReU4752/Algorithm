#include <stdio.h>

int n, m; // n x m �� ũ��
int map[100][100]; // ��
int min; // �ּҰ�

void DFS(int x, int y, int l)
{
	// �������� ���
	if (x == m - 1 && y == n - 1)
	{
		if (min > l) min = l;
		return;
	}

	// �湮������ ǥ��
	map[y][x] = 0;

	// ���� ���������� ���
	if (y > 0 && map[y - 1][x] != 0) DFS(x, y - 1, l + 1);
	// �Ʒ��� ���������� ���
	if (y < n - 1 && map[y + 1][x] != 0) DFS(x, y + 1, l + 1);
	// �������� ���������� ���
	if (x > 0 && map[y][x - 1] != 0) DFS(x - 1, y, l + 1);
	// ���������� ���������� ���
	if (x < m - 1 && map[y][x + 1] != 0) DFS(x + 1, y, l + 1);

	map[y][x] = 1; // �������ڸ��� �����·� �ǵ����� ���� 1�� ����
}

int main()
{
	scanf("%d%d", &n, &m);
	min = n * m; // ��� ��θ� ���ƴٳ൵ n * m �̴� �̸� �ּҰ����� �صд�.

	for (int i = 0; i < n; i++)
	{
		char str[101];
		scanf("%s", str);
		
		for (int j = 0; j < m; j++)
			map[i][j] = str[j] - '0';
	}	
	DFS(0, 0, 1);

	printf("%d", min);

	return 0;
}