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

long long arr[1000010];

long long tree[4000000];

long long init(int left,int right,int node)
{
	if (left == right)
	{
		tree[node] = arr[left];
		return tree[node];
	}

	int mid = (left + right) / 2;

	tree[node] = (init(left, mid, node * 2)*init(mid + 1, right, node * 2 + 1)) % 1000000007;

	return tree[node];
}

long long getmul(int left, int right, int a, int b, int node)
{
	if (right<a || left>b)
	{
		return 1;
	}
	
	if (right <= b && left >= a)
	{
		return tree[node];
	}

	int mid = (left + right) / 2;

	return (getmul(left, mid, a, b, node * 2)*getmul(mid + 1, right, a, b, node * 2 + 1))% 1000000007;



}

long long update(int left, int right,  int index,int node)
{
	if (index > right || index < left)
	{
		return tree[node];
	}

	if (left == right)
	{
		tree[node] = arr[index];
		return arr[index];
	}
	

	if (left != right)
	{
		int mid = (left + right) / 2;

		tree[node] = update(left,mid, index, node*2)*update(mid+1,right,index,node*2+1) % 1000000007;
		return tree[node];

	}


}



int N, M, K;

int main()
{
	scanf("%d %d %d", &N, &M, &K);

	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &arr[i]);
	}

	init(1, N, 1);

	for (int i = 0; i < M + K; i++)
	{
		int order;
		scanf("%d", &order);
		int a, b;
		scanf("%d %d", &a, &b);
		if (order == 1)
		{
			arr[a] = b;
			update(1, N, a, 1);
			
		}
		else
		{
			printf("%d\n", getmul(1, N, a, b, 1));
		}

	}




}