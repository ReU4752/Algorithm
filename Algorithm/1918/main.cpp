// https://www.acmicpc.net/problem/1918
// 2019-12-05

#include <iostream>
#include <string>
#include <stack>

using namespace std;

inline bool IsOperator(char c)
{
	return (c == '(' || c == ')' || c == '+' || c == '-' || c == '*' || c == '/');
}

int GetOperatorWeight(char c)
{
	if (c == '*' || c == '/')
		return 3;
	else if (c == '+' || c == '-')
		return 2;
	else if (c == '(' || c == ')')
		return 1;
	else
		return -1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie();

	string infixNotation;

	cin >> infixNotation;

	stack<char> operatorStack;
	
	string postfixNotation;
	for (const auto& c : infixNotation)
	{
		if (!IsOperator(c))
		{
			postfixNotation += c;
		}
		else
		{
			if (c == '(')
				operatorStack.push(c);
			else if (c == ')')
			{
				while (!operatorStack.empty())
				{
					char op = operatorStack.top();
					operatorStack.pop();

					if (op == '(')
						break;
					else
						postfixNotation.push_back(op);
				}
			}
			else
			{
				while (!operatorStack.empty() && GetOperatorWeight(c) <= GetOperatorWeight(operatorStack.top()))
				{
					postfixNotation.push_back(operatorStack.top());
					operatorStack.pop();
				}

				operatorStack.push(c);
			}
		}
	}
	while(!operatorStack.empty())
	{
		postfixNotation += operatorStack.top();
		operatorStack.pop();
	}

	cout << postfixNotation << "\n";

	return 0;
}