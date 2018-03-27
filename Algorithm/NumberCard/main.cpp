// 2018-03-27
// https://www.acmicpc.net/problem/10815

#include <stdio.h>
#include <vector>
#include <algorithm>

// 숫자가 무조건 범위 안에 있다하니..
// -10,000,000 ~ 10,000,000 -> 총 20000001
bool haveCard[20000001];

int main()
{
  int n;
  scanf("%d", &n);

  for (int i = 0; i < n; i++)
  {
    int num;

    scanf("%d", &num);
    haveCard[num + 10000000] = true;
  }

  int m;
  scanf("%d", &m);

  int result;
  for (int i = 0; i < m; i++)
  {
    int num;

    scanf("%d", &num);

    int idx = num + 10000000;
    if (haveCard[idx] == true)
    {
      printf("1 ");
    }
    else
    {
      printf("0 ");
    }
  }

  return 0;
}