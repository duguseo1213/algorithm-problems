#define _CRT_SECURE_NO_WARNINGS
#define P printf
#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;


int arr[1001];
int N;
int dp[1001];
int main() 
{
	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &arr[i]);
	}

	for (int i = 1; i <= 1000; i++)
	{
		dp[i] = 1;
	}

	for (int i = 2; i <= N; i++)
	{
		for (int j = 1; j < i; j++)
		{
			if (arr[i] > arr[j])
			{
				dp[i] = max(dp[j]+1, dp[i]);
			}
		}
	}

	int maxx = 0;

	for (int i = 1; i <= 1000; i++)
	{
		maxx = max(dp[i], maxx);
	}

	P("%d", maxx);
}