#include <stdint.h>
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
int m, n, h;
vector<vector<vector<int>>> g_storage;
queue<Space> g_spaceQueue;
int blankCount, lessRipenCount;

int GetLastRipenDay()
{
  int lastDay = 0;

  while (!g_spaceQueue.empty())
  {
    Space nowSpace = g_spaceQueue.front();

    lastDay = nowSpace.day;

    g_spaceQueue.pop();


  }

  return lastDay;
}

int main()
{
  scanf("%d %d %d", &m, &n, &h);

  int num;

  g_storage.reserve(h);
  for (int i = 0; i < h; i++)
  {
    vector<vector<int>> floorTemp;
    floorTemp.reserve(n);

    for (int j = 0; j < n; j++)
    {
      vector<int> widthTemp;
      widthTemp.reserve(m);

      for (int k = 0; k < m; k++)
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
          g_spaceQueue.push(Space(0, k, j, i));
          break;
        }

        widthTemp.push_back(num);
      }

      floorTemp.push_back(widthTemp);
    }

    g_storage.push_back(floorTemp);
  }

  // 처음부터 모두 익어있는 상태라면.
  if (m * n * h - blankCount == g_spaceQueue.size())
  {
    printf("0\n");
  }
  else
  {

  }

  return 0;
}