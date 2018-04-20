// https://www.acmicpc.net/problem/1924
// 2018-04-20

#include <stdio.h>

int GetDayOfWeek(int month, int day)
{
  int count = 0;

  for (int i = 1; i <= month; i++)
  {
    int j = 1;

    while (1)
    {
      if (i == month && j == day)
        return count;
      else
      {
        if (i == 2 && j > 28)
          break;
        else if ((i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) && j > 31)
          break;
        else if ((i == 4 || i == 6 || i == 9 || i == 11) && j > 30)
          break;

        count++;
      }

      j++;
    }
  }

  return -1;
}

int main()
{
  static char dayOfWeekStr[7][30] = { "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN" };

  int month, day;

  scanf("%d %d", &month, &day);

  printf("%s", dayOfWeekStr[GetDayOfWeek(month, day) % 7]);

  return 0;
}