#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

//long long dp[100];

long long dp[31][31];


int N;

int main()
{
	for (int i = 0; i < 31; i++)
	{
		dp[0][i] = 1;
	}

	for (int i = 0; i < 31; i++)
	{
		dp[i][i] = 1;
	}

	for (int i = 1; i < 31; i++)
	{
		for (int j = 2; j < 31; j++)
		{
			dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];
		}
	}



	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		
		printf("%d\n", dp[a][b]);
	}

	

}