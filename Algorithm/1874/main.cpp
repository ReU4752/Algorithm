// https://www.acmicpc.net/problem/1874
// 2019-12-13

#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie();

	int n;
	cin >> n;

	vector<int> targetList;
	targetList.resize(n);
	for (auto& n : targetList)
	{
		cin >> n;
	}


	stack<int> numStack;
	int count = 1;
	vector<char> result;
	bool fail = false;
	int targetIdx = 0;
	for (int i = 0; i < targetList.size() * 2; i++)
	{
		if (numStack.empty() || count <= targetList[targetIdx])
		{
			numStack.push(count++);
			result.push_back('+');
		}
		else if (numStack.top() == targetList[targetIdx])
		{
			numStack.pop();
			result.push_back('-');
			targetIdx++;
		}
		else if (targetList[targetIdx] < numStack.top())
		{
			fail = true;
		}
		else
		{
			if (numStack.empty() == false && numStack.top() >= targetList[targetIdx])
			{
				numStack.pop();
				result.push_back('-');
			}
			else
				fail = true;
		}
	}

	if (fail)
	{
		cout << "NO\n";
	}
	else
	{
		for (int i = 0; i < result.size(); i++)
		{
			cout << result[i] << "\n";
		}
	}


	return 0;
}