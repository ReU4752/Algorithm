#include <stdio.h>
#include <memory.h>

int GetCanSumCount(int n, int* dp)
{
  if (n == 0) // 종료 조건
    return 1;
  
  if (dp[n] != 0)
    return dp[n];

  int count = 0;

  // 점화식
  if (n - 1 >= 0)
    count += GetCanSumCount(n - 1, dp);
  if (n - 2 >= 0)
    count += GetCanSumCount(n - 2, dp);
  if (n - 3 >= 0)
    count += GetCanSumCount(n - 3, dp);

  return dp[n] = count;
}

int main()
{
  int numCase;

  scanf("%d", &numCase);

  int num;
  int dp[12];

  memset(dp, 0, sizeof(int) * 12);

  for (int i = 0; i < numCase; i++)
  {
    scanf("%d", &num);

    printf("%d\n", GetCanSumCount(num, dp));
  }

  return 0;
}