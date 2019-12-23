// https://www.acmicpc.net/problem/2164
// 2019-12-23

#include <iostream>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie();

	int N;
	cin >> N;

	if (N == 1)
		cout << '1';
	else
	{
		queue<int> cardList;
		for (int i = 1; i <= N; i++)
			cardList.push(i);

		while (cardList.size() > 1)
		{
			cardList.pop();

			auto frontCard = cardList.front();
			cardList.pop();
			cardList.push(frontCard);
		}

		cout << cardList.front();
	}

	return 0;
}