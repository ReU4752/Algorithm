#include <stdio.h>
#include <memory.h>

unsigned long long GetPinaryNumber(int n, int depth, char lastNum, unsigned long long(*dp)[2])
{
  if (depth == n) // 종료 조건
  {
    return 1;
  }

  if (dp[depth][lastNum - '0'] != 0)
  {
    return dp[depth][lastNum - '0'];
  }

  // 점화식
  unsigned long long count = 0;

  if (lastNum == '1')
  {
    count += GetPinaryNumber(n, depth + 1, '0', dp);
  }
  else if(lastNum == '0')
  {
    count += GetPinaryNumber(n, depth + 1, '0', dp);
    count += GetPinaryNumber(n, depth + 1, '1', dp);
  }
     
  return dp[depth][lastNum - '0'] = count;
}

int main()
{
  int n;
  unsigned long long dp[100][2];
  memset(dp, 0, sizeof(unsigned long long) * 200);

  scanf("%d", &n);

  printf("%llu", GetPinaryNumber(n, 1, '1', dp));

  return 0;
}