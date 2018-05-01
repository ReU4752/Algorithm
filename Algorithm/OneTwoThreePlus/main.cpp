#include <stdio.h>

int GetCanSumCount(int n)
{
  if (n == 0) // 종료 조건
    return 1;
  
  int count = 0;

  // 점화식
  if (n - 1 >= 0)
    count += GetCanSumCount(n - 1);
  if (n - 2 >= 0)
    count += GetCanSumCount(n - 2);
  if (n - 3 >= 0)
    count += GetCanSumCount(n - 3);

  return count;
}

int main()
{
  int numCase;

  scanf("%d", &numCase);

  int num;
  for (int i = 0; i < numCase; i++)
  {
    scanf("%d", &num);

    printf("%d\n", GetCanSumCount(num));
  }

  return 0;
}