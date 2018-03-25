// 2018-03-25
// https://www.acmicpc.net/problem/1260

#include <stdio.h>
#include <string.h>

int n; // ������ ����
int m; // ������ ����
int map[1001][1001]; // ���� ���
int visit[1001]; // �湮 �迭

void DFS(int v)
{
	visit[v] = 1;
	printf("%d ", v);

	for (int i = 1; i <= n; i++)
	{
		// ���� v�� i�� ����Ǿ��ְ�, ���� i�� �湮�����ʾ������
		if (map[v][i] == 1 && !visit[i])
		{
			DFS(i);
		}
	}
}

int front, rear; // ����, �Ĵ�
int queue[1001]; // ť

void BFS(int v)
{
	// ���� v�� �湮�ߴ� ǥ��
	visit[v] = 1;
	printf("%d ", v);

	// ť�� v�� �����ϰ� �Ĵ��� 1������Ŵ
	queue[rear++] = v;
	while (front < rear) // ������ �Ĵܰ� ���ų� ������ ����Ż��
	{
		// ť�� ù��°�� �ִ� �����͸� ��������, 1 ����
		v = queue[front++];
		for (int i = 1; i <= n; i++)
		{
			// ���� v�� ���� i�� ����Ǿ��ְ�, ����i�� �湮�����ʾ������
			if (map[v][i] == 1 && !visit[i])
			{
				visit[i] = 1; // ���� i�� �湮�ߴٰ� ǥ��
				printf("%d ", i);
				queue[rear++] = i; // ť�� i�� �����ϰ� 1����.
			}
		}
	}
}

int main()
{
	int start;
	int v1, v2;

	scanf("%d%d%d", &n, &m, &start);

	for (int i = 0; i < m; i++)
	{
		scanf("%d%d", &v1, &v2);

		map[v1][v2] = map[v2][v1] = 1;
	}
	DFS(start);

	printf("\n");
	memset(visit, 0, sizeof(visit));

	BFS(start);

	return 0;
}