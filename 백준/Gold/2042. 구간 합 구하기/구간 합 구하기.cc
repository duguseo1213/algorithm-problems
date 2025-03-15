#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <set>
#include <vector>
#include <queue>
#include <unordered_map>
#include <map>

using namespace std;

long long arr[1000001];
long long tree[4000400];

long long init(int left,int right,int node)
{

	if (left == right) {
		tree[node] = arr[left];
		return tree[node];
	}

	int mid = (left + right) / 2;

	tree[node] = init(left, mid, node * 2) + init(mid + 1, right, node * 2 + 1);
	
	return tree[node];

}

long long getsum(int left, int right, int a, int b, int node)
{
	if (left > b || right < a) return 0;

	if (left >= a && right <= b) return tree[node];

	int mid = (left + right) / 2;

	return getsum(left, mid, a, b, node * 2) + getsum(mid + 1, right, a, b, node * 2 + 1);

}

void update(int left, int right, long long diff, int node,int index)
{
	if (index<left || index>right) return;
	if (left == right)
	{
		tree[node] += diff;
		return;
	}


	


	tree[node] += diff;
	int mid = (left + right) / 2;

	update(left, mid, diff, node * 2, index);

	update(mid + 1, right, diff, node * 2 + 1, index);

	return;


}

int N, M, K;

int main()
{
	scanf("%d %d %d", &N, &M, &K);

	for (int i = 1; i <= N; i++)
	{
		scanf("%lld", &arr[i]);

	}

	init(1, N, 1);

	for (int i = 0; i < M+K; i++)
	{
		int state;
		int b;
		long long c;
		scanf("%d", &state);
		scanf("%d %lld", &b, &c);
		if (state == 1)
		{
			
			update(1, N, c - arr[b],1,b);
			arr[b] = c;

		}
		else
		{
			printf("%lld\n", getsum(1, N, b, c, 1));
		}
	}


}