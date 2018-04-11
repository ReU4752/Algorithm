// https://www.acmicpc.net/problem/7569
// 2018-04-10

#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

struct Space
{
  int day;
  int row, col, height;

  Space() {}
  Space(int _day, int _row, int _col, int _height) 
    : day(_day), row(_row), col(_col), height(_height) {}
};

// 가로, 세로, 높이
int row, col, height;
vector<vector<vector<int>>> g_storage;
queue<Space> g_spaceQueue;
int blankCount, lessRipenCount;

int GetLastRipenDay()
{
  static int rowDir[6] = { -1, 1, 0, 0, 0, 0 };
  static int colDir[6] = { 0, 0, -1, 1, 0, 0 };
  static int heightDir[6] = { 0, 0, 0, 0, -1, 1 };

  int lastDay = 0;
  int ripenCount = 0;

  while (!g_spaceQueue.empty())
  {
    Space nowSpace = g_spaceQueue.front();

    if (nowSpace.day > lastDay)
      lastDay = nowSpace.day;

    g_spaceQueue.pop();

    for (int i = 0; i < 6; i++)
    {
      if (nowSpace.row + rowDir[i] >= 0 && nowSpace.row + rowDir[i] <= row - 1
          && nowSpace.col + colDir[i] >= 0 && nowSpace.col + colDir[i] <= col - 1
          && nowSpace.height + heightDir[i] >= 0 && nowSpace.height + heightDir[i] <= height - 1
          && g_storage[nowSpace.height + heightDir[i]][nowSpace.row + rowDir[i]][nowSpace.col + colDir[i]] == 0)
      {
        g_storage[nowSpace.height + heightDir[i]][nowSpace.row + rowDir[i]][nowSpace.col + colDir[i]] = 1;
        g_spaceQueue.push(Space(nowSpace.day + 1, nowSpace.row + rowDir[i], nowSpace.col + colDir[i], nowSpace.height + heightDir[i]));

        ripenCount++;
      }
    }
  }

  if (lessRipenCount != ripenCount)
    lastDay = 0;

  return lastDay;
}

int main()
{
  scanf("%d %d %d", &col, &row, &height);

  int num;

  g_storage.reserve(height);
  for (int i = 0; i < height; i++)
  {
    vector<vector<int>> floorTemp;
    floorTemp.reserve(row);

    for (int j = 0; j < row; j++)
    {
      vector<int> widthTemp;
      widthTemp.reserve(col);

      for (int k = 0; k < col; k++)
      {
        scanf("%d", &num);
        
        switch (num)
        {
        case -1:
          blankCount++;
          break;
        case 0:
          lessRipenCount++;
          break;
        case 1:
          g_spaceQueue.push(Space(0, j, k, i));
          break;
        }

        widthTemp.push_back(num);
      }

      floorTemp.push_back(widthTemp);
    }

    g_storage.push_back(floorTemp);
  }

  // 처음부터 모두 익어있는 상태라면.
  if (row * col * height - blankCount == g_spaceQueue.size())
  {
    printf("0\n");
  }
  else
  {
    int day = GetLastRipenDay();
    if (day == 0)
      printf("-1\n");
    else
      printf("%d\n", day);
  }

  return 0;
}