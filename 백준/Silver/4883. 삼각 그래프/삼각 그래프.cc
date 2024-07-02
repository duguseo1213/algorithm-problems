#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int N;

int dp[100000][3];
int arr[100000][3];

int main() {

	int cnt = 1;
	while (1) {
		memset(dp, 0, sizeof(dp));
		scanf("%d", &N);

		if (N == 0) break;

		for (int i = 0; i < N; i++) {
			scanf("%d %d %d", &arr[i][0], &arr[i][1], &arr[i][2]);
		}

		dp[0][0] = 987654321;
		dp[0][1] = arr[0][1];
		dp[0][2] = dp[0][1] + arr[0][2];

		for (int i = 1; i < N; i++) {

			dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]) + arr[i][0];

			int minn = min(dp[i - 1][0], dp[i - 1][1]);

			minn = min(minn, dp[i][0]);
			dp[i][1] = min(minn, dp[i - 1][2]) + arr[i][1];

			minn = min(dp[i - 1][1], dp[i - 1][2]);


			dp[i][2] = min(minn, dp[i][1]) + arr[i][2];


		}
		/*
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < 3; j++) {
				printf("%d ", dp[i][j]);
			}
			printf("\n");
		}*/
		printf("%d. %d\n", cnt,dp[N - 1][1]);
		cnt++;
	}


}



