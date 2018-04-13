// 2018-04-13
// https://www.acmicpc.net/problem/2750

#include <stdio.h>
#include <vector>

using namespace std;

vector<int> g_storage;

void Swap(int& a, int& b)
{
  int temp = a;
  a = b;
  b = temp;
}

void QSort(int left, int right)
{
  int l = left;
  int r = right;
  int pivot = g_storage[(l + r) / 2];

  do
  {
    while (g_storage[l] < pivot)
      l++;
    while (g_storage[r] > pivot)
      r--;
    if (l <= r)
    {
      Swap(g_storage[l], g_storage[r]);
      l++; r--;
    }
  } while (l <= r);

  if (left < r)
    QSort(left, r);

  if (l < right)
    QSort(l, right);
}

int main()
{
  int n;
  scanf("%d", &n);

  for (int i = 0; i < n; i++)
  {
    int num;

    scanf("%d", &num);
    g_storage.push_back(num);
  }

  QSort(0, g_storage.size() - 1);

  for (auto itr : g_storage)
  {
    printf("%d\n", itr);
  }

  return 0;
}