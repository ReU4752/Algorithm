// https://www.acmicpc.net/problem/4949
// 2019-12-12

#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool IsValidParenthesesPair(char open, char close)
{
	if ((open == '(' && close == ')') ||
		(open == '[' && close == ']'))
	{
		return true;
	}

	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie();

	string line;
	getline(cin, line);
	
	while (line != ".")
	{
		stack<char> psStack;

		bool IsOkay = true;
		for (const auto& token : line)
		{
			if (token == '(' || token == '[')
			{
				psStack.push(token);
			}
			else if (token == ')' || token == ']')
			{
				if (psStack.empty())
				{
					IsOkay = false;
					break;
				}
				else
				{
					char latestOpenParentheses = psStack.top();
					psStack.pop();
					if (!IsValidParenthesesPair(latestOpenParentheses, token))
					{
						IsOkay = false;
						break;
					}
				}
			}
		}

		if (IsOkay && psStack.empty())
			cout << "yes\n";
		else
			cout << "no\n";

		getline(cin, line);
	}

	return 0;
}