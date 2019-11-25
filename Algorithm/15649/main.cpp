// https://www.acmicpc.net/problem/15649
// 2019-11-25

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> arr;
vector<bool> used;

void BackTrack(int k)
{
	if (k == M)
	{
		for (int i = 0; i < k; i++) cout << arr[i] + 1 << " ";
		cout << "\n";
		return;
	}

	for (int i = 0; i < N; i++)
	{
		if (used[i] == false)
		{
			arr[k] = i;
			used[i] = true;
			BackTrack(k + 1);
			used[i] = false;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	arr.resize(M);
	used.resize(N);
	fill(used.begin(), used.end(), false);

	BackTrack(0);

	return 0;
}