#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int arr[1001];
int dp[1201];

int N;

int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {

		scanf("%d", &arr[i]);
		dp[i] = 21e8;
	}

	dp[0] = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 1; j <= arr[i]; j++) {

			dp[i + j] = min(dp[i + j], dp[i] + 1);

		}
		
	}

	if (dp[N - 1] == 21e8) {
		printf("-1");
		return 0;
	}

	printf("%d ", dp[N-1]);




}
