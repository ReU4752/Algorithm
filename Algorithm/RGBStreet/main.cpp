// https://www.acmicpc.net/problem/1149
// 2018-04-23

#include <stdio.h>
#include <vector>

using namespace std;

inline int minI(int a, int b)
{
  return (a < b) ? a : b;
}

inline int min3(int a, int b, int c)
{
  return (a < b) ? ((a < c) ? a : c) : (b < c) ? b : c;
}

enum COLOR
{
  R = 0,
  G,
  B
};
struct House
{
  int cost[3];
};

int main()
{
  vector<House> vecHouse;

  int n;
  scanf("%d", &n);
  vecHouse.reserve(n);

  int i;
  int r, g, b;
  for (i = 0; i < n; i++)
  {
    scanf("%d %d %d", &r, &g, &b);

    House house;

    if (i >= 1)
    {
      house.cost[R] = minI(vecHouse[i - 1].cost[G], vecHouse[i - 1].cost[B]) + r;
      house.cost[G] = minI(vecHouse[i - 1].cost[R], vecHouse[i - 1].cost[B]) + g;
      house.cost[B] = minI(vecHouse[i - 1].cost[R], vecHouse[i - 1].cost[G]) + b;
    }
    else
    {
      house.cost[R] = r;
      house.cost[G] = g;
      house.cost[B] = b;
    }

    vecHouse.push_back(house);
  }

  printf("%d", min3(vecHouse[n - 1].cost[R], vecHouse[n - 1].cost[G], vecHouse[n - 1].cost[B]));

  return 0;
}