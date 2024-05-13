#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

int dp[41];

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



	for (int i = 2; i < 41; i++)
	{
		cnt[i][1] = cnt[i - 1][1] + cnt[i - 2][1];
		cnt[i][0] = cnt[i - 1][0] + cnt[i - 2][0];


	}

	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		int a;
		scanf("%d", &a);

		printf("%d %d\n", cnt[a][0], cnt[a][1]);

	}
	

}