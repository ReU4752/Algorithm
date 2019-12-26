// https://www.acmicpc.net/problem/11866
// 2019-12-24

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie();

	int N, K;
	cin >> N >> K;

	queue<int> sequence;

	for (int i = 1; i <= N; i++)
		sequence.push(i);


	vector<int> result;
	result.resize(N);
	int idx = 0;

	int count = 1;
	while (!sequence.empty())
	{
		if (count % K == 0)
		{
			result[idx++] = sequence.front();
			sequence.pop();
			count = 1;
		}
		else
		{
			auto front = sequence.front();
			sequence.pop();
			sequence.push(front);
			count++;
		}
	}

	cout << '<';
	cout << result.front();
	for (int i = 1; i < result.size(); i++)
		cout << ", " << result[i];
	cout << '>';

	return 0;
}