// 2018-03-25
// https://www.acmicpc.net/problem/1260

#include <stdio.h>
#include <string.h>

int n; // 정점의 개수
int m; // 간선의 개수
int map[1001][1001]; // 인접 행렬
int visit[1001]; // 방문 배열

void DFS(int v)
{
	visit[v] = 1;
	printf("%d ", v);

	for (int i = 1; i <= n; i++)
	{
		// 정점 v와 i가 연결되어있고, 정점 i를 방문하지않았을경우
		if (map[v][i] == 1 && !visit[i])
		{
			DFS(i);
		}
	}
}

int front, rear; // 전단, 후단
int queue[1001]; // 큐

void BFS(int v)
{
	// 점점 v를 방문했다 표시
	visit[v] = 1;
	printf("%d ", v);

	// 큐에 v를 삽입하고 후단을 1증가시킴
	queue[rear++] = v;
	while (front < rear) // 전단이 후단과 같거나 작으면 루프탈출
	{
		// 큐의 첫번째에 있는 데이터를 가져오고, 1 증가
		v = queue[front++];
		for (int i = 1; i <= n; i++)
		{
			// 정점 v와 정점 i가 연결되어있고, 정점i를 방문하지않았을경우
			if (map[v][i] == 1 && !visit[i])
			{
				visit[i] = 1; // 정점 i를 방문했다고 표시
				printf("%d ", i);
				queue[rear++] = i; // 큐에 i를 삽입하고 1증가.
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