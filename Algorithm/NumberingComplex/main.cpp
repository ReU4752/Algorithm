// 2018-03-26
// https://www.acmicpc.net/problem/2667

#include <stdio.h>
#include <algorithm>
#include <queue>

int n; // 지도의 크기
std::vector<std::vector<int>> map;
std::vector<int> complex; // 단지

struct House
{
	int x, y;

	House() {}
	House(int _x, int _y)
	{
		x = _x;
		y = _y;
	}
};
std::queue<House> Q;

void Calc()
{
	for (int i = 0; i < n * n; i++)
	{
		int x = i % n;
		int y = i / n;

		if (map[y][x] != 0)
		{
			int houseNum = 0;

			Q.push(House(x, y));

			map[y][x] = 0;
			houseNum++;

			while (!Q.empty()) // 큐가 비어있으면 루프탈출
			{
				House h = Q.front();
				Q.pop();

				// 위에 집이 있다면
				if (h.y > 0 && map[h.y - 1][h.x] != 0)
				{
					Q.push(House(h.x, h.y - 1));
					houseNum++;
					map[h.y - 1][h.x] = 0;
				}

				// 아래에 집이 있다면
				if (h.y < n - 1 && map[h.y + 1][h.x] != 0)
				{
					Q.push(House(h.x, h.y + 1));
					houseNum++;
					map[h.y + 1][h.x] = 0;
				}

				// 왼쪽에 집이 있다면
				if (h.x > 0 && map[h.y][h.x - 1] != 0)
				{
					Q.push(House(h.x - 1, h.y));
					houseNum++;
					map[h.y][h.x - 1] = 0;
				}

				// 오른쪽에 집이 있다면
				if (h.x < n - 1 && map[h.y][h.x + 1] != 0)
				{
					Q.push(House(h.x + 1, h.y));
					houseNum++;
					map[h.y][h.x + 1] = 0;
				}
			}

			complex.push_back(houseNum);
		}
	}
}

int main()
{
	scanf("%d", &n);
	map.reserve(n);

	for (int i = 0; i < n; i++)
	{
		char str[26];
		std::vector<int> vec;

		vec.reserve(n);

		scanf("%s", str);

		for (int j = 0; j < n; j++)
		{
			vec.push_back(str[j] - '0');
		}
		map.push_back(vec);
	}

	Calc();
	
	std::sort(complex.begin(), complex.end()); // 단지의 속하는 집의 수를 기준으로 정렬
	
	int size = complex.size();
	printf("%d\n", size); // 총단지수 
	for (auto i : complex)
		printf("%d\n", i); // 단지의 속하는 집의 수를 출력

	return 0;
}