// https://www.acmicpc.net/problem/10773
// 2019-12-10

#include <iostream>
#include <stack>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie();
	
	unsigned int k;
	cin >> k;

	stack<int> stack;
	for (int i = 0; i < k; i++)
	{
		unsigned int num;
		cin >> num;

		if (num == 0)
			stack.pop();
		else
			stack.push(num);
	}

	unsigned int accumulation = 0;
	while (!stack.empty())
	{
		accumulation += stack.top();
		stack.pop();
	}

	cout << accumulation;

	return 0;
}