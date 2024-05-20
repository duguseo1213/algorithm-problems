
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

int dp[1001];

int arr[1001];

int N;

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
		dp[i] = 1;
	}

	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[i] > arr[j])
			{
				dp[i]=max(dp[i], dp[j] + 1);
			}
		}
	}
	int maxx = 0;
	for (int i = 0; i < N; i++)
	{
		maxx = max(maxx, dp[i]);
		
	}
	printf("%d ", maxx);
}