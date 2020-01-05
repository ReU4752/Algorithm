// https://www.acmicpc.net/problem/2263
// 2019-01-05

#include <iostream>
#include <vector>

using namespace std;

vector<int> inorder;
vector<int> postorder;
vector<int> pos;

void preorder(int inorder_start, int inorder_end, int postorder_start, int postorder_end)
{
	if ((inorder_start > inorder_end) || (postorder_start > postorder_end))
		return;

	int root = postorder[postorder_end];
	cout << root << " ";

	int idx = pos[root];

	// left
	preorder(inorder_start, idx - 1,
		postorder_start, postorder_start + (idx - inorder_start) - 1);
	// right
	preorder(idx + 1, inorder_end,
		postorder_start + (idx - inorder_start), postorder_end - 1);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	inorder.resize(N);
	postorder.resize(N);
	pos.resize(100001);
	for (int i = 0; i < N; i++)
		cin >> inorder[i];
	for (int i = 0; i < N; i++)
		cin >> postorder[i];
	for (int i = 0; i < N; i++)
		pos[inorder[i]] = i;

	preorder(0, N - 1, 0, N - 1);

	return 0;
}