#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

using namespace std;
int dp[101][10001];
int arr[101];
int N, K;
int main()
{
	for (int i = 0; i < 101; i++)
	{
		for (int j = 1; j <= 10000; j++)
		{
			dp[i][j] = 9999999;
		}
	}

	scanf("%d %d", &N, &K);
	
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}

	for (int i = 1; i <= K; i++)
	{
		if (i < arr[0])
		{

		}
		else
		{
			if (i % arr[0] == 0)
			{
				dp[0][i] = i / arr[0];
			}
		}
	}
	for (int i = 1; i <= K; i++)
	{
		//printf("%d ", dp[0][i]);
	}

	for (int i = 1; i < N; i++)
	{
		for (int j = 1; j <= K; j++)
		{
			if (j < arr[i])
			{
				dp[i][j] = dp[i-1][j];
			}

			else
			{
				
				dp[i][j] = min(dp[i][j - arr[i]] + 1, dp[i - 1][j]);


			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j <= K; j++)
		{

			//printf("%d ", dp[i][j]);
		}
		//printf("\n");
	}

	if (dp[N-1][K] == 9999999)
	{
		printf("-1");
	}
	else
	{
		printf("%d",dp[N-1][K]);
	}
}