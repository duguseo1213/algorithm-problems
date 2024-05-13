#define _CRT_SECURE_NO_WARNINGS
#define P 
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

int N, K;

int dp[2][10010];

int arr[101];


int main()
{
	scanf("%d %d", &N, &K);

	for (int i = 0; i < N; i++)
	{
		int a;
		scanf("%d", &arr[i]);
	}

	sort(&arr[0], &arr[0] + N);


	if (N == 1)
	{
		if (K%arr[0] == 0)
		{
			printf("1");
		}
		else
		{
			printf("0");
		}
		return 0;
	}

	
	for (int i = 0; i <= K; i++)
	{
		if (i / arr[0] == 0)
		{
			dp[0][i] = 0;
		}
		else
		{
			if (i%arr[0] == 0)
			{
				dp[0][i] = 1;
			}

			
		}
		P("%d ", dp[0][i]);
	}
	dp[0][0] = 1;
	P("\n");
	for (int i = 1; i < N; i++)
	{

		for (int j = 0; j <= K; j++)
		{
			if (j / arr[i] == 0)
			{
				dp[1][j] = dp[0][j];
			}
			else
			{
				dp[1][j] = dp[0][j] + dp[1][j - arr[i]];
			}
			//dp[i][j]
			
		}

		for (int j = 0; j <= K; j++)
		{
			P("%d ", dp[1][j]);
			dp[0][j] = dp[1][j];
		}
		P("\n");
	}

	for (int i = 0; i < N; i++)
	{

		for (int j = 0; j <= K; j++)
		{
			
			//printf("%d ", dp[i][j]);

		}
		//printf("\n");
	}

	printf("%d", dp[1][K]);

	

}