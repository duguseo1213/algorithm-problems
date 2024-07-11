#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int arr[1001][1001];
int dp[1001][1001];


int N, M;

int main() {
	
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	dp[0][0] = arr[0][0];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (i == 0 && j == 0) {
				continue;
			}

			if (i == 0) {
				dp[i][j] = dp[i][j - 1] + arr[i][j];
			}
			else if (j == 0) {
				dp[i][j] = dp[i-1][j] + arr[i][j];
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + arr[i][j];
			}

		}
	}
	printf("%d", dp[N - 1][M - 1]);

}
