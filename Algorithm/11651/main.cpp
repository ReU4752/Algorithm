// https://www.acmicpc.net/problem/11651
// 2019-11-19

#include <stdio.h>
#include <vector>
#include <stack>

using namespace std;

struct Point
{
	int x, y;

	Point() {}
	Point(int _x, int _y) : x(_x), y(_y) {}
};

void Swap(Point* a, Point* b)
{
	Point temp = *a;
	*a = *b;
	*b = temp;
}

int QuickSortY_Partition(vector<Point>& pointList, const int low, const int high)
{
	int pivot = low;
	int left = low;
	int right = high + 1;

	do 
	{
		do { left++; } while (left <= high && pointList[left].y < pointList[pivot].y);
		do { right--; } while (right >= low && pointList[right].y > pointList[pivot].y);
		if (left < right)
		{
			Swap(&pointList[left], &pointList[right]);
		}
	} while (left < right);

	Swap(&pointList[low], &pointList[right]);

	return right;
}

void QuickSortY(vector<Point>& pointList)
{
	stack<pair<int, int>> partitionList;
	partitionList.push(make_pair(0, pointList.size() - 1));

	while (!partitionList.empty())
	{
		int low = partitionList.top().first;
		int high = partitionList.top().second;
		partitionList.pop();

		if (low < high)
		{
			int pivot = QuickSortY_Partition(pointList, low, high);
			partitionList.push(make_pair(low, pivot - 1));
			partitionList.push(make_pair(pivot + 1, high));
		}
	}
}

int QuickSortX_Partition(vector<Point>& pointList, const int low, const int high)
{
	int left = low;
	int right = high + 1;
	int pivot = low;
	
	do 
	{
		do { left++; } while (left <= high && pointList[left].x < pointList[pivot].x);
		do { right--; } while (right >= low && pointList[right].x > pointList[pivot].x);
		if (left < right)
		{
			Swap(&pointList[left], &pointList[right]);
		}
	} while (left < right);

	Swap(&pointList[low], &pointList[right]);

	return right;
}

void QuickSortX(vector<Point>& pointList, const int low, const int high)
{
	stack<pair<int, int>> partitionList;
	partitionList.push(make_pair(low, high));

	while (!partitionList.empty())
	{
		const int low = partitionList.top().first;
		const int high = partitionList.top().second;
		partitionList.pop();

		if (low < high)
		{
			int pivot = QuickSortX_Partition(pointList, low, high);
			partitionList.push(make_pair(low, pivot - 1));
			partitionList.push(make_pair(pivot + 1, high));
		}
	}
}

int main()
{
	int N;
	scanf("%d", &N);

	vector<Point> pointList;
	pointList.resize(N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d %d", &pointList[i].x, &pointList[i].y);
	}

	QuickSortY(pointList);

	int length = 0;
	for (int i = 1; i < N; i++)
	{
		if (pointList[i - 1].y != pointList[i].y)
		{
			if (length > 0)
				QuickSortX(pointList, i - 1 - length, i - 1);
		
			length = 0;
		}
		else
		{
			length += 1;
		}
	}

	if (length > 0)
	{
		QuickSortX(pointList, N - 1 - length, N - 1);
	}

	for (int i = 0; i < N; i++)
	{
		printf("%d %d\n", pointList[i].x, pointList[i].y);
	}

	return 0;
}