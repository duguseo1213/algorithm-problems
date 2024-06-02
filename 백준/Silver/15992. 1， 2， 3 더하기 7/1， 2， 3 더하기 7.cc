#define _CRT_SECURE_NO_WARNINGS
#define P printf

#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>

using namespace std;

long long dp[1010][1010]; //개수,값

int N, M;
int T;
int main() 
{
	scanf("%d", &T);
	//scanf("%d %d", &N, &M);

	dp[1][1] = 1;

	dp[1][2] = 1;
	dp[2][2] = 1;

	dp[1][3] = 1;
	dp[2][3] = 2;
	dp[3][3] = 1;


	
		for (int j = 1; j <= 1000; j++)
		{
			for (int i = 4; i <= 1000; i++)
			{
			dp[j][i] += dp[j - 1][i - 1] % 1000000009;
			dp[j][i] += dp[j - 1][i - 2] % 1000000009;
			dp[j][i] += dp[j - 1][i - 3] % 1000000009;

		}
	}

	for (int i = 0; i < T; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%lld\n", dp[b][a] % 1000000009);

	}
	
	
}