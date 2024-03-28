#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>;
using namespace std;

int N, K;

bool cmp(pair<int, int> a, pair<int, int> b)
{
	return a.first > b.first;
}

vector<pair<int, int>> vec; //가격 무게

int arr[300010];
int uni[300010];
int find(int tar)
{
	if (tar == uni[tar])
	{
		return tar;
	}

	int root=find(uni[tar]);

	uni[tar] = root;

	return root;


}

void setunion(int a, int b)
{
	int t1 = find(a);
	int t2 = find(b);

	if (t1 == t2)
	{
		return;
	}

	uni[t2] = t1;


}


int main()
{

	for (int i = 0; i < 300000; i++)
	{
		uni[i] = i;
	}

	scanf("%d %d", &N, &K);

	for (int i = 0; i < N; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);

		vec.push_back({ b,a });

	}
	sort(vec.begin(), vec.end(), cmp);
	
	for (int i = 0; i < K; i++)
	{
		scanf("%d", &arr[i]);
	}
	
	sort(arr, arr + K);
	for (int i = 0; i < K; i++)
	{
		//printf("%d ", arr[i]);
	}
	

	
	long long sum = 0;
	for (int k = 0; k < N; k++)
	{
		int maxx = -1;
		int i = 0;
		int j = K;
		
		while (1)
		{
			
			if (i > j)
			{
				break;
			}

			int mid = (i + j) / 2;

			if (arr[mid] >= vec[k].second)
			{
				maxx = mid;
				j = mid - 1;
				
			}
			else
			{
				i = mid + 1;
			}
			
		}
		

		int idx = find(maxx);
		//printf("%d %d\n ", idx,maxx);
		if (maxx == -1) continue;
		if (idx == K) continue;
		sum = sum + vec[k].first;
		setunion(idx + 1, idx);

	}
	printf("%lld", sum);
	   	 
}