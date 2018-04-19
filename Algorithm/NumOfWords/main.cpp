// https://www.acmicpc.net/problem/1152
// 2018-04-20

#include <stdio.h>
#include <string.h>

int main()
{
  char str[1000001];
  int count = 0;

  scanf("%[^\n]", str); // 공백 포함

  bool wordCheck = false;
  for (int i = 0; i < strlen(str); i++)
  {
    if (!wordCheck && str[i] != ' ')
    {
      wordCheck = true;
      count++;
    }
    else if (wordCheck && str[i] == ' ')
    {
      wordCheck = false;
    }
  }

  printf("%d", count);

  return 0;
}