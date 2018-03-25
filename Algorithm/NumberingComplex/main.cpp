// 2018-03-26
// https://www.acmicpc.net/problem/2667

#include <stdio.h>
#include <algorithm>
#include <queue>

int n; // ������ ũ��
std::vector<std::vector<int>> map;
std::vector<int> complex; // ����

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

			while (!Q.empty()) // ť�� ��������� ����Ż��
			{
				House h = Q.front();
				Q.pop();

				// ���� ���� �ִٸ�
				if (h.y > 0 && map[h.y - 1][h.x] != 0)
				{
					Q.push(House(h.x, h.y - 1));
					houseNum++;
					map[h.y - 1][h.x] = 0;
				}

				// �Ʒ��� ���� �ִٸ�
				if (h.y < n - 1 && map[h.y + 1][h.x] != 0)
				{
					Q.push(House(h.x, h.y + 1));
					houseNum++;
					map[h.y + 1][h.x] = 0;
				}

				// ���ʿ� ���� �ִٸ�
				if (h.x > 0 && map[h.y][h.x - 1] != 0)
				{
					Q.push(House(h.x - 1, h.y));
					houseNum++;
					map[h.y][h.x - 1] = 0;
				}

				// �����ʿ� ���� �ִٸ�
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
	
	std::sort(complex.begin(), complex.end()); // ������ ���ϴ� ���� ���� �������� ����
	
	int size = complex.size();
	printf("%d\n", size); // �Ѵ����� 
	for (auto i : complex)
		printf("%d\n", i); // ������ ���ϴ� ���� ���� ���

	return 0;
}