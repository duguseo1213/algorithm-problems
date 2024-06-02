#define _CRT_SECURE_NO_WARNINGS
#define P printf

#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>

using namespace std;

long long dp[100001][2]; //0은 홀수 1은 짝수

int N, M;
int T;
int main() 
{
	scanf("%d", &T);
	//scanf("%d %d", &N, &M);

	dp[1][0] = 1;

	dp[2][0] = 1;
	dp[2][1] = 1;

	dp[3][0] = 2;
	dp[3][1] = 2;
	


	
	for (int i = 4; i <= 100000; i++)
	{
		
			dp[i][0] += dp[i-1][1] % 1000000009;
			dp[i][0] += dp[i-2][1] % 1000000009;
			dp[i][0] += dp[i-3][1] % 1000000009;

			dp[i][1] += dp[i - 1][0] % 1000000009;
			dp[i][1] += dp[i - 2][0] % 1000000009;
			dp[i][1] += dp[i - 3][0] % 1000000009;
			

		
	}
	int a, b;
	for (int i = 0; i < T; i++)
	{
		
		scanf("%d", &a);
		printf("%lld %lld\n", dp[a][0] % 1000000009, dp[a][1] % 1000000009);

	}

	
}