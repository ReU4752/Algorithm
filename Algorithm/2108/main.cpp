// https://www.acmicpc.net/problem/2108
// 2019-11-13

#include <cstdio>
#include <vector>
#include <cmath>
#include <string.h>

using namespace std;

int main()
{
	vector<int> list;
	int counting[8001];
	int min = 2147483647, max = -2147483647 - 1;
	int accumulation = 0;

	memset(counting, 0, sizeof(counting));

	int N;
	scanf("%d", &N);

	list.resize(N);
	for (int i = 0; i < N; i++)
	{
		int inputNum = 0;
		scanf("%d", &inputNum);
		if (inputNum > max)
			max = inputNum;
		if (inputNum < min)
			min = inputNum;
	
		list[i] = inputNum;
		counting[inputNum + 4000] += 1;
		accumulation += inputNum;
	}

	vector<int> sortedlist;
	sortedlist.reserve(N);

	for (int i = min + 4000; i <= max + 4000; i++)
	{
		for (int j = 0; j < counting[i]; j++)
		{
			sortedlist.push_back(i - 4000);
		}
	}

	printf("%d\n", (int)floor((float)accumulation / N + 0.5f));
	printf("%d\n", sortedlist[sortedlist.size() / 2]);

	vector<int> mostFrequentlyNumbers;
	int mostFrequency = 1;
	for (int i = min + 4000; i <= max + 4000; i++)
	{
		if (counting[i] >= mostFrequency)
		{
			if (counting[i] > mostFrequency)
				mostFrequentlyNumbers.clear();

			mostFrequency = counting[i];

			mostFrequentlyNumbers.push_back(i - 4000);
		}
	}
	printf("%d\n", mostFrequentlyNumbers.size() > 1 ? mostFrequentlyNumbers[1] : mostFrequentlyNumbers[0]);
	printf("%d\n", max - min);

	return 0;
}