#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;



long long dp[41][2]; // 위치, 바꿈 유무 0이 안바꿈

int N;
int M;

int seat[41];

int main() {
	scanf("%d", &N);
	scanf("%d", &M);


	dp[0][0] = 1;

	dp[1][0] = 1;
	dp[1][1] = 0;

	for (int i = 2; i <= 40; i++) {
		dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
		dp[i][1] = dp[i - 1][0];

		//printf("%lld ", dp[i][1] + dp[i][0]);
	}
	
	for (int i = 0; i < M; i++) {
		int temp;
		scanf("%d", &temp);

		seat[temp] = 1;
	}
	int cnt = 0;
	long long sum = 1;
	for (int i = 1; i <= N; i++) {
		
		if (seat[i] == 1) {
			sum = sum * (dp[cnt][0] + dp[cnt][1]);
			cnt = 0;
		}
		else {
			cnt++;
		}

	}
	sum = sum * (dp[cnt][0] + dp[cnt][1]);
	printf("%lld", sum);



}