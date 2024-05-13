#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

long long dp[100];

int cnt[41][2];

int main()
{
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 2;

	cnt[0][0] = 1;
	cnt[0][1] = 0;

	cnt[1][0] = 0;
	cnt[1][1] = 1;



	for (int i = 2; i < 91; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];


	}

	int N;
	scanf("%d", &N);
	
	printf("%lld", dp[N]);
	

}