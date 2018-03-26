// 2018-03-26
// https://www.acmicpc.net/problem/2667

#include <stdio.h>
#include <algorithm>
#include <queue>

int n; // ������ ũ�� n * n
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

int dX[4] = { 0, 0, 1, -1 }; // �̸� ������ ����
int dY[4] = { 1, -1, 0, 0 }; // �̸� ������ ����

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
        House nowHouse = Q.front();
        Q.pop();

        for (int i = 0; i < 4; i++)
        {
          if (nowHouse.x + dX[i] >= 0 && nowHouse.y + dY[i] >= 0 &&
              nowHouse.x + dX[i] < n && nowHouse.y + dY[i] < n
              && map[nowHouse.y + dY[i]][nowHouse.x + dX[i]])
          {
            Q.push(House(nowHouse.x + dX[i], nowHouse.y + dY[i]));

            houseNum++;

            map[nowHouse.y + dY[i]][nowHouse.x + dX[i]] = 0;
          }
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