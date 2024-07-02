#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

long long dp[1000001];

int N;

int main() {
	scanf("%d", &N);

	

	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 1;

	

	for (int i = 3; i <= 1000000; i++) {
		dp[i] = (dp[i-1] + dp[i-2])% 1000000000;
	}

	if (N == 0) {
		printf("0\n0");
	}
	else if (N>0) 
	{

		printf("1\n%lld", dp[N]);
	}
	else
	{
		N = N * -1;
		if (N%2 == 0 ) { // 짝수
			printf("-1\n%lld", dp[N]);
		}
		else { // 홀수
			printf("1\n%lld", dp[N]);
		}
	}
	


}