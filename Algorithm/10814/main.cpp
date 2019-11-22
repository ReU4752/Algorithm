// https://www.acmicpc.net/problem/10814
// 2019-11-22

#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef pair<int, string> MemberData;

vector<MemberData> tempList;

void MergeSort_Merge(vector<MemberData>& memberList, const int low, const int mid, const int high)
{
	int saveIdx = low;
	int firstPart = low;
	int lastPart = mid + 1;

	while ((firstPart <= mid) && (lastPart <= high))
	{
		if (memberList[firstPart].first <= memberList[lastPart].first)
			tempList[saveIdx++] = memberList[firstPart++];
		else
			tempList[saveIdx++] = memberList[lastPart++];
	}

	while (firstPart <= mid)
		tempList[saveIdx++] = memberList[firstPart++];

	while (lastPart <= high)
		tempList[saveIdx++] = memberList[lastPart++];

	for (int i = low; i <= high; i++)
		memberList[i] = tempList[i];
}

void MergeSort_Partition(vector<MemberData>& memberList, int low, int high)
{
	if (low < high)
	{
		const int mid = (low + high) / 2;
		MergeSort_Partition(memberList, low, mid);
		MergeSort_Partition(memberList, mid + 1, high);
		MergeSort_Merge(memberList, low, mid, high);
	}
}

int main()
{
	int N;
	cin >> N;

	vector<MemberData> memberList;
	memberList.resize(N);
	tempList.resize(N);

	for (int i = 0; i < N; i++)
		cin >> memberList[i].first >> memberList[i].second;

	MergeSort_Partition(memberList, 0, memberList.size() - 1);

	for(int i = 0; i < N; i++)
	{
		cout << memberList[i].first << " " << memberList[i].second << "\n";
	}

	return 0;
}