#define _CRT_SECURE_NO_WARNINGS
#define P printf
#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

long long dp[201][201];

int N, K;

int main() 
{
	scanf("%d %d", &N, &K);

	for (int i = 0; i <= 200; i++)
	{
		dp[1][i] = 1;
	}

	for (int i = 1; i <= 200; i++)
	{
		dp[i][0] = 1;
	}

	for (int i = 2; i <= 200; i++)
	{
		for (int j = 1; j <= 200; j++)
		{
			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1])%1000000000;

			//P("%d", dp[i][j]);
		}
		//P("\n");
	}

	printf("%lld", dp[K][N]);



}