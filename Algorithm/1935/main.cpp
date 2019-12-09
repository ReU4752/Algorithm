// https://www.acmicpc.net/problem/1935
// 2019-12-09

#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

bool IsOperator(const char& c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return true;

	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie();

	int numOperators;
	cin >> numOperators;

	vector<int> operandValueList;
	operandValueList.resize(numOperators);

	string postfixNotation;
	cin >> postfixNotation;

	for (auto& value : operandValueList)
	{
		cin >> value;
	}

	stack<double> operandStack;
	for (const char& token : postfixNotation)
	{
		if (IsOperator(token))
		{
			auto opa2 = operandStack.top(); operandStack.pop();
			auto opa1 = operandStack.top(); operandStack.pop();
			switch (token)
			{
			case '+':
				operandStack.push(opa1 + opa2);
				break;
			case '-':
				operandStack.push(opa1 - opa2);
				break;
			case '*':
				operandStack.push(opa1 * opa2);
				break;
			case '/':
				operandStack.push(opa1 / opa2);
				break;
			}
		}
		else
			operandStack.push((double)operandValueList[token - 'A']);
	}

	cout << fixed;
	cout.precision(2);
	cout << operandStack.top();

	return 0;
}