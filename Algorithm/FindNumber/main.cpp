// 2018-03-27
// https://www.acmicpc.net/problem/1920

#include <stdio.h>
#include <vector>
#include <algorithm>

std::vector<int> vecNum;

int BSearch(int num)
{
  int front = 0;
  int rear = vecNum.size() - 1;

  while (front <= rear)
  {
    int middle = vecNum[(front + rear) / 2];

    if (middle == num)
      return 1;
    else if (middle < num)
      front = (front + rear) / 2 + 1;
    else if (middle > num)
      rear = (front + rear) / 2 - 1;
  }

  return 0;
}

int main()
{
  int n;
  scanf("%d", &n);
  vecNum.reserve(n);

  for (int i = 0; i < n; i++)
  {
    int num;

    scanf("%d", &num);
    vecNum.push_back(num);
  }

  std::sort(vecNum.begin(), vecNum.end());

  int m;
  scanf("%d", &m);

  for (int i = 0; i < m; i++)
  {
    int num;

    scanf("%d", &num);
    printf("%d\n", BSearch(num));
  }

  return 0;
}