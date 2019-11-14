// https://www.acmicpc.net/problem/1427
// 2019-11-14

#include <stdio.h>
#include <cmath>
#include <vector>
#include <stack>

template <typename T>
void Swap(T* a, T* b)
{
	T temp = *a;
	*a = *b;
	*b = temp;
}

void DigitSort(std::vector<char>& numStr, int digit)
{
	// low high
	std::stack<std::pair<int, int>> quickSortStack;

	quickSortStack.push(std::make_pair(0, digit - 1));

	while (!quickSortStack.empty())
	{
		std::pair<int, int> partition = quickSortStack.top();
		quickSortStack.pop();

		const int& low = partition.first;
		const int& high = partition.second;

		if (low < high)
		{
			char& pivot = numStr[high];

			int i = low - 1, j = low;

			for (; j < high; ++j)
			{
				if (numStr[j] > pivot)
					Swap(&numStr[++i], &numStr[j]);
			}

			Swap(&numStr[++i], &pivot);

			// partition
			quickSortStack.push(std::make_pair(low, i - 1));
			quickSortStack.push(std::make_pair(i + 1, high));
		}
	}
}

int main()
{
	int num;
	scanf("%d", &num);

	int digit = 0;
	while (num >= pow(10, ++digit));

	std::vector<char> numStr;
	int tempNum = num;
	int tempDigit = digit;
	while (tempDigit > 0)
	{
		int numberOfCurrentDigit = tempNum % (int)pow(10, tempDigit) / (int)pow(10, tempDigit - 1);
		numStr.push_back(numberOfCurrentDigit + 48);
		tempDigit--;
	}

	DigitSort(numStr, digit);

	for (int i = 0; i < digit; i++)
		printf("%c", numStr[i]);

	return 0;
}