#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <set>
#include <vector>
#include <queue>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <climits>

using namespace std;

int arr[100010];

int tree[400000];

int init(int left, int right, int node)
{
	if (left == right)
	{
		tree[node] = arr[left];
		return tree[node];
	}

	int mid = (left + right) / 2;

	tree[node] = min(init(left, mid, node * 2) , init(mid + 1, right, node * 2 + 1));
	return tree[node];

}

int getmin(int left, int right, int a,int b, int node)
{
	if (a > right || b < left)
	{
		return INT_MAX;
	}
	if (a <= left && b >= right)
	{
		return tree[node];
	}

	int mid=(left + right) / 2;
	
	int minn = min(getmin(left, mid, a, b, node * 2), getmin(mid + 1, right, a, b, node * 2 + 1));
	//printf("%d\n", minn);
	return minn;


}




int N, M;

int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &arr[i]);
	}

	init(1, N, 1);

	

	int a, b;
	for (int i = 0; i < M; i++)
	{
		scanf("%d %d", &a, &b);

		printf("%d\n", getmin(1, N, a, b, 1));
		
	}



}