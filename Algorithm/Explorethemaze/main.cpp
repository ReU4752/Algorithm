#include <stdio.h>
#include <queue>

int n, m; // n x m 맵 크기
std::vector<std::vector<int>> map; // 맵
std::vector<std::vector<bool>> visit; // 방문했는지
int min; // 최소값

struct Path
{
	// 좌표정보, 길이
	int x, y, l;

	Path() {}
	Path(int _x, int _y, int _l)
	{
		x = _x;
		y = _y;
		l = _l;
	}
};
std::queue<Path> Q;

void BFS(Path p)
{
	Path nP = p;
	Q.push(p);

	// 비어있지않고 도착했다면 나가기
	while (!Q.empty() && (nP.x != m - 1 || nP.y != n - 1))
	{
		nP = Q.front();
		Q.pop();
		 
		visit[nP.y][nP.x] = true;

		// 위쪽으로 이동가능하면 그리고 이미 방문하지않았으면 ㄱㄱ 
		if (nP.y > 0 && map[nP.y - 1][nP.x] != 0 && visit[nP.y - 1][nP.x] == false)
		{
			Q.push(Path(nP.x, nP.y - 1, nP.l + 1));
			visit[nP.y - 1][nP.x] = true;
		}
		// 아래쪽으로 이동가능하면 ㄱㄱ
		if (nP.y < n - 1 && map[nP.y + 1][nP.x] != 0 && visit[nP.y + 1][nP.x] == false)
		{
			Q.push(Path(nP.x, nP.y + 1, nP.l + 1));
			visit[nP.y + 1][nP.x] = true;
		}
		// 왼쪽으로 이동가능하면 ㄱㄱ
		if (nP.x > 0 && map[nP.y][nP.x - 1] != 0 && visit[nP.y][nP.x - 1] == false)
		{
			Q.push(Path(nP.x - 1, nP.y, nP.l + 1));
			visit[nP.y][nP.x - 1] = true;
		}
		// 오른쪽으로 이동가능하면 ㄱㄱ
		if (nP.x < m - 1 && map[nP.y][nP.x + 1] != 0 && visit[nP.y][nP.x + 1] == false)
		{
			Q.push(Path(nP.x + 1, nP.y, nP.l + 1));
			visit[nP.y][nP.x + 1] = true;
		}
	}

	min = nP.l;
}

int main()
{
	scanf("%d%d", &n, &m);
	min = n * m; // 모든 경로를 돌아다녀도 n * m 이니 이를 최소값으로 해둔다.
	map.resize(n);
	for(int i = 0; i < n; i++)
		map[i].resize(m);

	visit.resize(n);
	for (int i = 0; i < n; i++)
		visit[i].resize(m);

	for (int i = 0; i < n; i++)
	{
		char str[101];
		scanf("%s", str);

		for (int j = 0; j < m; j++)
			map[i][j] = str[j] - '0';
	}
	BFS(Path(0, 0, 1));


	printf("%d", min);

	return 0;
}