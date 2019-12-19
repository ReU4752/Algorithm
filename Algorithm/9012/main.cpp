// https://www.acmicpc.net/problem/9012
// 2019-12-11

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie();

	int numTestCase;
	cin >> numTestCase;

	for (int t = 0; t < numTestCase; t++)
	{
		stack<bool> parenthesisStack;

		string str;
		cin >> str;

		bool valid = true;
		for (const char& token : str)
		{
			if (token == '(')
				parenthesisStack.push(true);
			else if (token == ')')
				if (parenthesisStack.empty())
				{
					valid = false;
					break;
				}
				else
					parenthesisStack.pop();
		}

		if (valid && parenthesisStack.empty())
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}