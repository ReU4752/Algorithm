// https://www.acmicpc.net/problem/1932
// 2018-04-26

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

template <typename T>
inline T MAX(T a, T b)
{
  return (a > b) ? a : b;
}

int main()
{
  int tri[501][501];
  int result[501][501];
  int triSize = 0;

  memset(tri, 0, sizeof(int) * 501 * 501);
  memset(result, 0, sizeof(int) * 501 * 501);

  scanf("%d", &triSize);

  for (int i = 1; i <= triSize; i++)
  {
    for (int j = 1; j <= i; j++)
    {
      scanf("%d", &tri[i][j]);
    }
  }

  result[1][1] = tri[1][1];

  for (int i = 2; i <= triSize; i++)
  {
    for (int j = 1; j <= i; j++)
    {
      result[i][j] = MAX(result[i - 1][j] + tri[i][j], result[i - 1][j  - 1] + tri[i][j]);
    }
  }

  int highest = 0;
  for (int i = 1; i <= triSize; i++)
  {
    highest = MAX(highest, result[triSize][i]);
  }

  printf("%d\n", highest);

  return 0;
}