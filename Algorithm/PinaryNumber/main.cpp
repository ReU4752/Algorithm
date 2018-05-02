#include <stdio.h>
#include <string>
#include <memory.h>

using namespace std;

int GetPinaryNumber(int n, int depth, char lastNum)
{
  if (depth == n) // 종료 조건
    return 1;

  // 점화식
  int count = 0;

  if (lastNum == '1')
  {
    count += GetPinaryNumber(n, depth + 1, '0');
  }
  else if(lastNum == '0')
  {
    count += GetPinaryNumber(n, depth + 1, '0');
    count += GetPinaryNumber(n, depth + 1, '1');
  }
     
  return count;
}

int main()
{
  int n;

  scanf("%d", &n);

  printf("%d", GetPinaryNumber(n, 1, '1'));

  return 0;
}