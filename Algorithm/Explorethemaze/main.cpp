#include <stdio.h>
#include <queue>

int n, m; // n x m �� ũ��
std::vector<std::vector<int>> map; // ��
std::vector<std::vector<bool>> visit; // �湮�ߴ���
int min; // �ּҰ�

struct Path
{
	// ��ǥ����, ����
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

	// ��������ʰ� �����ߴٸ� ������
	while (!Q.empty() && (nP.x != m - 1 || nP.y != n - 1))
	{
		nP = Q.front();
		Q.pop();
		 
		visit[nP.y][nP.x] = true;

		// �������� �̵������ϸ� �׸��� �̹� �湮�����ʾ����� ���� 
		if (nP.y > 0 && map[nP.y - 1][nP.x] != 0 && visit[nP.y - 1][nP.x] == false)
		{
			Q.push(Path(nP.x, nP.y - 1, nP.l + 1));
			visit[nP.y - 1][nP.x] = true;
		}
		// �Ʒ������� �̵������ϸ� ����
		if (nP.y < n - 1 && map[nP.y + 1][nP.x] != 0 && visit[nP.y + 1][nP.x] == false)
		{
			Q.push(Path(nP.x, nP.y + 1, nP.l + 1));
			visit[nP.y + 1][nP.x] = true;
		}
		// �������� �̵������ϸ� ����
		if (nP.x > 0 && map[nP.y][nP.x - 1] != 0 && visit[nP.y][nP.x - 1] == false)
		{
			Q.push(Path(nP.x - 1, nP.y, nP.l + 1));
			visit[nP.y][nP.x - 1] = true;
		}
		// ���������� �̵������ϸ� ����
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
	min = n * m; // ��� ��θ� ���ƴٳ൵ n * m �̴� �̸� �ּҰ����� �صд�.
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