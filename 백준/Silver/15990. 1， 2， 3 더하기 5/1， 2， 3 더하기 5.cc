#define _CRT_SECURE_NO_WARNINGS
#define P
#include <iostream>

using namespace std;

long long dp[100001][4]; //시작하는걸로

int N;
int main()
{
	dp[1][1] = 1;
	dp[1][2] = 0;
	dp[1][3] = 0;

	dp[2][1] = 0;
	dp[2][2] = 1;
	dp[2][3] = 0;

	dp[3][1] = 1;
	dp[3][2] = 1;
	dp[3][3] = 1;

	for (int i = 4; i <= 100000; i++)
	{
		dp[i][1] = (dp[i - 1][2] + dp[i - 1][3]) % 1000000009;

		dp[i][2] = (dp[i - 2][1] + dp[i - 2][3]) % 1000000009;

		dp[i][3] = (dp[i - 3][2] + dp[i - 3][1]) % 1000000009;




	}
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		int temp;
		scanf("%d", &temp);
		printf("%lld\n", (dp[temp][1] + dp[temp][2] + dp[temp][3]) % 1000000009);
	}


}