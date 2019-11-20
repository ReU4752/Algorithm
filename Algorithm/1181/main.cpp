// https://www.acmicpc.net/problem/1181
// 2019-11-20

#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

void Swap(string* a, string* b)
{
	string temp = *a;
	*a = *b;
	*b = temp;
}

// -1 a < b
// 0 a == b
// 1 a > b
int CompareDictionaryOrder(string& a, string &b)
{
	if (a.length() < b.length())
		return -1;
	else if (a.length() > b.length())
		return 1;
	
	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] < b[i])
			return -1;
		else if (a[i] > b[i])
			return 1;
	}

	return 0;
}

int QuickSort_Partition(vector<string>& wordList, const int low, const int high)
{
	int left = low;
	int right = high + 1;
	const int pivot = low;

	do 
	{
		do { left++; } 
		while (left <= high && 
			(wordList[left].length() < wordList[pivot].length() || 
			(wordList[left].length() == wordList[pivot].length() && CompareDictionaryOrder(wordList[left], wordList[pivot]) < 0)));

		do { right--; } 
		while (right >= low && 
			(wordList[right].length() > wordList[pivot].length() || 
			(wordList[right].length() == wordList[pivot].length() && CompareDictionaryOrder(wordList[right], wordList[pivot]) > 0)));

		if (left < right)
		{
			Swap(&wordList[left], &wordList[right]);
		}
	} while (left < right);

	Swap(&wordList[low], &wordList[right]);

	return right;
}

void QuickSort(vector<string>& wordList)
{
	stack<pair<int, int>> partitions;

	partitions.push(make_pair(0, wordList.size() - 1));

	while (!partitions.empty())
	{
		int low = partitions.top().first;
		int high = partitions.top().second;
		partitions.pop();

		if (low < high)
		{
			int pivot = QuickSort_Partition(wordList, low, high);
			partitions.push(make_pair(low, pivot - 1));
			partitions.push(make_pair(pivot + 1, high));
		}
	}
}

int main()
{
	int N;
	cin >> N;

	vector<string> wordList;
	wordList.resize(N);

	for (int i = 0; i < N; i++)
	{
		cin >> wordList[i];
	}

	QuickSort(wordList);

	for (int i = 0; i < N; i++)
	{
		if (i > 0 && wordList[i - 1] == wordList[i])
			continue;

		cout << wordList[i] << endl;
	}

	return 0;
}