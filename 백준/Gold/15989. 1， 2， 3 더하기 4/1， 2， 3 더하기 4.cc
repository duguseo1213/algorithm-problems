#define _CRT_SECURE_NO_WARNINGS
#define P
#include <iostream>

using namespace std;

int dp[10001];

int N;
int main()
{
	dp[0] = 1;
	scanf("%d", &N);


	
	for (int j = 1; j <= 3; j++)
	{
		for (int i = j; i <= 10000; i++)
		{
			dp[i] += dp[i - j];
		}
	}

	for (int i = 0; i < N; i++)
	{
		int temp;
		scanf("%d", &temp);

		printf("%d\n", dp[temp]);
	}

}