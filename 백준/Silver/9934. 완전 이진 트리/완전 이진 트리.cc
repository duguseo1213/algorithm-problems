#define _CRT_SECURE_NO_WARNINGS
#define P printf
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <unordered_set>
#include <cmath>
using namespace std;

vector<int> level[11];

int K;
int arr[10000];

void func(int dep, int left, int right)
{
	if (left == right)
	{
		//printf("%d ", arr[left]);
		level[dep].push_back(arr[left]);
		return;
	}


	int mid = (left + right)/2;

	level[dep].push_back(arr[mid]);

	//printf("%d ", arr[mid]);

	func(dep + 1,left, mid - 1);

	func(dep + 1, mid+1, right);

}

int main()
{
	scanf("%d", &K);

	int L=pow(2, K)-1;

	for (int i = 0; i < L; i++)
	{
		scanf("%d", &arr[i]);
	}

	func(0, 0, L -1);

	for (int i = 0; i < K; i++)
	{
		for (int j = 0; j < level[i].size(); j++)
		{
			printf("%d ", level[i][j]);
		}
		printf("\n");
	}
}
