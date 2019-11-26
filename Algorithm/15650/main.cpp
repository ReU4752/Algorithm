// https://www.acmicpc.net/problem/15650
// 2019-11-26

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> arr;
vector<bool> used;

void BackTracking(int k, int p)
{
	if (k == M)
	{
		for (int i = 0; i < M; i++) cout << arr[i] << " ";
		cout << "\n";

		return;
	}

	for (int i = p; i <= N; i++)
	{
		if (used[i - 1] == false)
		{
			used[i - 1] = true;
			arr[k] = i;
			BackTracking(k + 1, arr[k]);
			used[i - 1] = false;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie();

	cin >> N >> M;
	arr.resize(M);
	used.resize(N);
	fill(used.begin(), used.end(), false);

	BackTracking(0, 1);

	return 0;
}