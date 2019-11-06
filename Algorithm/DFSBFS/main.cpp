// 2018-03-25
// https://www.acmicpc.net/problem/1260

#include <stdio.h>
#include <string.h>

int N; // 정점의 개수
int M; // 간선의 개수

int adjMat[1001][1001]; // 인접행렬
int visit[1001]; // 방문 배열

void DFS(int VisitVertexNum)
{
	visit[VisitVertexNum] = 1;
	printf("%d ", VisitVertexNum);

	for (int i = 1; i <= N; i++)
	{
		if (adjMat[VisitVertexNum][i] == 1 && visit[i] == 0)
		{
			DFS(i);
		}
	}
}

int front, rear;
int queue[1001];

void BFS(int VisitVertexNum)
{
	front = rear = 0;

	queue[rear++] = VisitVertexNum;
	visit[VisitVertexNum] = 1;

	int v = 0;
	while (front < rear)
	{
		v = queue[front++];
		printf("%d ", v);

		for (int i = 1; i <= N; i++)
		{
			if (adjMat[v][i] == 1 && visit[i] == 0)
			{
				queue[rear++] = i;
				visit[i] = 1;
			}
		}
	}
}

int main()
{
	memset(adjMat, 0, sizeof(adjMat));
	memset(visit, 0, sizeof(visit));

	int StartVertexNum;

	scanf("%d %d %d", &N, &M, &StartVertexNum);

	for (int i = 0; i < M; i++)
	{
		int conV1, conV2;
		scanf("%d %d", &conV1, &conV2);

		// 양방향 그래프라서 둘다 true
		adjMat[conV1][conV2] = adjMat[conV2][conV1] = 1;
	}

	DFS(StartVertexNum);

	memset(visit, 0, sizeof(visit));
	printf("\n");

	BFS(StartVertexNum);

	return 0;
}