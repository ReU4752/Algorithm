// https://www.acmicpc.net/problem/11650
// 2019-11-15

#include <stdio.h>
#include <vector>
#include <stack>

using namespace std;

struct Point
{
	int x, y;

	Point() {}
	Point(int ix, int iy) : x(ix), y(iy) {}
};

void Swap(Point* a, Point* b)
{
	Point temp = *a;
	*a = *b;
	*b = temp;
}

int QuickSortX_Partition(vector<Point>& points, const int low, const int high)
{
	Point pivot = points[low];
	int left = low;
	int right = high + 1;

	do
	{
		do { left++; } while (left <= high && points[left].x < pivot.x);
		do { right--; } while (right >= low && points[right].x > pivot.x);
		if (left < right)
		{
			Swap(&points[left], &points[right]);
		}
	} while (left < right);

	Swap(&points[low], &points[right]);

	return right;
}

void QuickSortX(vector<Point>& points)
{
	stack<pair<int, int>> quickSortLowHigh;

	quickSortLowHigh.push(make_pair(0, points.size() - 1));

	while (!quickSortLowHigh.empty())
	{
		const int low = quickSortLowHigh.top().first;
		const int high = quickSortLowHigh.top().second;
		quickSortLowHigh.pop();

		if (low < high)
		{
			int pivot = QuickSortX_Partition(points, low, high);

			quickSortLowHigh.push(make_pair(low, pivot - 1));
			quickSortLowHigh.push(make_pair(pivot + 1, high));
		}
	}
}

int QuickSortY_Partition(vector<Point>& points, const int low, const int high)
{
	Point pivot = points[low];
	int left = low;
	int right = high + 1;

	do
	{
		do { left++; } while (left <= high && points[left].y < pivot.y);
		do { right--; } while (right >= low && points[right].y > pivot.y);
		if (left < right)
		{
			Swap(&points[left], &points[right]);
		}
	} while (left < right);

	Swap(&points[low], &points[right]);

	return right;
}

void QuickSortY(vector<Point>& points, const int low, const int high)
{
	stack<pair<int, int>> quickSortLowHigh;

	quickSortLowHigh.push(make_pair(low, high));

	while (!quickSortLowHigh.empty())
	{
		const int low = quickSortLowHigh.top().first;
		const int high = quickSortLowHigh.top().second;
		quickSortLowHigh.pop();

		if (low < high)
		{
			int pivot = QuickSortY_Partition(points, low, high);

			quickSortLowHigh.push(make_pair(low, pivot - 1));
			quickSortLowHigh.push(make_pair(pivot + 1, high));
		}
	}
}

int main()
{
	int N;
	scanf("%d", &N);

	vector<Point> points;
	points.resize(N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d %d", &points[i].x, &points[i].y);
	}

	QuickSortX(points);
	int length = 0;
	int start = 0;
	for (int i = 1; i < N; i++)
	{
		if (points[i - 1].x == points[i].x)
		{
			length++;
		}
		else
		{
			QuickSortY(points, i - 1 - length, i - 1);
			length = 0;
			start = i;
		}
	}

	if (length != 0)
		QuickSortY(points, start, length);

	for (int i = 0; i < N; i++)
	{
		printf("%d %d\n", points[i].x, points[i].y);
	}

	return 0;
}