#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[100][100001];

pair<int, int> thing[100]; //weight value

int main()
{
	int N, K;
	scanf("%d %d", &N, &K);

	for (int i = 0; i < N; i++)
	{
		int a, b;
		scanf("%d %d", &thing[i].first, &thing[i].second);
	}

	for (int i = 1; i <= K; i++)
	{
		if (thing[0].first > i)
		{
			dp[0][i] = 0;
		}
		else
		{
			dp[0][i] = thing[0].second;
		}
	}

	for (int i = 1; i <= K; i++)
	{
		for (int j = 1; j < N; j++)
		{
			int temp = 0;
			if (thing[j].first <= i)
			{
				temp = thing[j].second + dp[j-1][(i - thing[j].first)];
			}
			dp[j][i] = max(dp[j-1][i], temp);
		}
	}
	/*
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j <= K; j++)
		{
			printf("%d ", dp[i][j]);
		}
		printf("\n");
	}*/
	
	printf("%d", dp[N - 1][K]);

}