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

struct NODE {

	int maxx;
	int minn;

};


int arr[100010];

NODE tree[400000];

NODE init(int left, int right, int node)
{
	if (left == right)
	{
		tree[node].maxx = arr[left];
		tree[node].minn = arr[left];
		return tree[node];
	}

	int mid = (left + right) / 2;
	NODE L = init(left, mid, node * 2);
	NODE R = init(mid + 1, right, node * 2 + 1);
	tree[node].minn = min(L.minn ,R.minn);
	tree[node].maxx = max(L.maxx,R.maxx);
	return tree[node];

}

NODE getmin(int left, int right, int a,int b, int node)
{
	NODE temp;
	if (a > right || b < left)
	{
		
		temp.minn = INT_MAX;
		temp.maxx = -100;

		return temp;
	}
	if (a <= left && b >= right)
	{
		return tree[node];
	}

	int mid=(left + right) / 2;
	
	NODE L = getmin(left, mid,a,b, node * 2);
	NODE R = getmin(mid + 1, right,a,b, node * 2 + 1);


	temp.minn= min(L.minn, R.minn);
	temp.maxx= max(L.maxx, R.maxx);


	return temp;

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
		NODE temp = getmin(1, N, a, b, 1);
		printf("%d %d \n", temp.minn,temp.maxx);
		
	}



}