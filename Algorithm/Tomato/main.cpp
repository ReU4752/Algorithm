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
  const static int dirRow[4] = { -1, 1, 0, 0 };
  const static int dirCol[4] = { 0, 0, -1, 1 };
  int lastDay = 0;
  int ripenCount = 0;

  while (!g_spaceQueue.empty())
  {
    Space nowSpace = g_spaceQueue.front();
    lastDay = nowSpace.day;

    g_spaceQueue.pop();

    for (int i = 0; i < 4; i++)
    {
      if (nowSpace.row + dirRow[i] >= 0 
          && nowSpace.row + dirRow[i] <= height - 1
          && nowSpace.col + dirCol[i] >= 0
          && nowSpace.col + dirCol[i] <= width - 1
          && g_storage[nowSpace.row + dirRow[i]][nowSpace.col + dirCol[i]] == 0)
      {
        g_spaceQueue.push(Space(nowSpace.day + 1, nowSpace.row + dirRow[i], nowSpace.col + dirCol[i]));
        g_storage[nowSpace.row + dirRow[i]][nowSpace.col + dirCol[i]] = 1;

        ripenCount++;
      }
    }
  }

  // 처음에 익지 못한 개수와 마지막에 익어진 개수가 다르면 전부 익지 못한것.
  if (lessRipenCount != ripenCount)
    lastDay = 0;

  return lastDay;
}

int main()
{
  scanf("%d %d", &width, &height);

  g_storage.reserve(height);

  for (int i = 0; i < height; i++)
  {
    vector<int> temp;
    int state;

    temp.reserve(width);

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

  // 처음부터 모두 익어있는 상황이면.
  if (width * height - blankCount == g_spaceQueue.size())
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