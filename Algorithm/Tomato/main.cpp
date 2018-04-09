// https://www.acmicpc.net/problem/7576
// 2018-04-07

#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

struct Space
{
  int day;
  int row, col;

  Space() {}
  Space(int _day, int _row, int _col) : day(_day), row(_row), col(_col) {}
};

int width, height;
int blankCount = 0;
int lessRipenCount = 0;
vector<vector<int>> g_storage;
queue<Space> g_spaceQueue;

int GetLastRipenDay()
{
  int lastDay = 0;
  int ripenCount = 0;

  while (!g_spaceQueue.empty())
  {
    Space nowSpace = g_spaceQueue.front();
    lastDay = nowSpace.day;

    g_spaceQueue.pop();

    if (nowSpace.row > 0 && g_storage[nowSpace.row - 1][nowSpace.col] == 0)
    {
      g_spaceQueue.push(Space(nowSpace.day + 1, nowSpace.row - 1, nowSpace.col));
      g_storage[nowSpace.row - 1][nowSpace.col] = 1;

      ripenCount++;
    }
    if (nowSpace.row < height - 1 && g_storage[nowSpace.row + 1][nowSpace.col] == 0)
    {
      g_spaceQueue.push(Space(nowSpace.day + 1, nowSpace.row + 1, nowSpace.col));
      g_storage[nowSpace.row + 1][nowSpace.col] = 1;

      ripenCount++;
    }
    if (nowSpace.col > 0 && g_storage[nowSpace.row][nowSpace.col - 1] == 0)
    {
      g_spaceQueue.push(Space(nowSpace.day + 1, nowSpace.row, nowSpace.col - 1));
      g_storage[nowSpace.row][nowSpace.col - 1] = 1;

      ripenCount++;
    }
    if (nowSpace.col < width - 1 && g_storage[nowSpace.row][nowSpace.col + 1] == 0)
    {
      g_spaceQueue.push(Space(nowSpace.day + 1, nowSpace.row, nowSpace.col + 1));
      g_storage[nowSpace.row][nowSpace.col + 1] = 1;

      ripenCount++;
    }
  }

  if (lessRipenCount != ripenCount)
  {
    lastDay = 0;
  }

  return lastDay;
}

int main()
{
  scanf("%d %d", &width, &height);

  g_storage.reserve(width * height);

  for (int i = 0; i < height; i++)
  {
    vector<int> temp;
    int state;

    for (int j = 0; j < width; j++)
    {
      scanf("%d", &state);

      switch (state)
      {
      case -1:
        blankCount++;
        break;

      case 0:
        lessRipenCount++;
        break;

      case 1:
        g_spaceQueue.push(Space(0, i, j));
        break;
      }

      temp.push_back(state);
    }

    g_storage.push_back(temp);
  }

  if (width * height - blankCount == g_spaceQueue.size()) // 처음부터 모두 익어있는 상황.
    printf("0\n");
  else
  {
    int day = GetLastRipenDay();

    if(day == 0) // 모두 익지 못하는 상황
      printf("-1\n");
    else
      printf("%d\n", day);
  }

  return 0;
}