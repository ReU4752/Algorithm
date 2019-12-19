// https://www.acmicpc.net/problem/17298
// 2019-12-19

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie();

	int N;
	cin >> N;
	vector<int> sequence;
	sequence.resize(N);
	for (auto& element : sequence)
		cin >> element;

	vector<int> result;
	result.resize(N);
	result[N - 1] = -1;
	// ���� �ε��� ���� ������ ���⿡�� ���� ������ ū���� ����
	stack<int> ngeStack;
	for (int i = sequence.size() - 2; i >= 0; i--)
	{
		// ���ο� ��ū�� �߰�
		if (sequence[i] < sequence[i + 1])
		{
			ngeStack.push(sequence[i + 1]);
			result[i] = ngeStack.top();
		}
		else
		{
			if (!ngeStack.empty())
			{
				while (!ngeStack.empty() && sequence[i] >= ngeStack.top())
				{ ngeStack.pop(); }

				if (!ngeStack.empty())
					result[i] = ngeStack.top();
				else
					result[i] = -1;
			}
			else
				result[i] = -1;
		}
	}

	for (const auto& ngeValue : result)
	{
		cout << ngeValue << " ";
	}

	return 0;
}