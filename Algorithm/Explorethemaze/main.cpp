#include <stdio.h>

int n, m; // n x m 맵 크기
int map[100][100]; // 맵
int min; // 최소값

void DFS(int x, int y, int l)
{
	// 도착했을 경우
	if (x == m - 1 && y == n - 1)
	{
		if (min > l) min = l;
		return;
	}

	// 방문했음을 표시
	map[y][x] = 0;

	// 위로 갈수있으면 고고
	if (y > 0 && map[y - 1][x] != 0) DFS(x, y - 1, l + 1);
	// 아래로 갈수있으면 고고
	if (y < n - 1 && map[y + 1][x] != 0) DFS(x, y + 1, l + 1);
	// 왼쪽으로 갈수있으면 고고
	if (x > 0 && map[y][x - 1] != 0) DFS(x - 1, y, l + 1);
	// 오른쪽으로 갈수있으면 고고
	if (x < m - 1 && map[y][x + 1] != 0) DFS(x + 1, y, l + 1);

	map[y][x] = 1; // 지나간자리를 원상태로 되돌리기 위해 1을 대입
}

int main()
{
	scanf("%d%d", &n, &m);
	min = n * m; // 모든 경로를 돌아다녀도 n * m 이니 이를 최소값으로 해둔다.

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