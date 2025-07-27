#define P
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <cstring>

using namespace std;

int arr[50001];

int dp[3][50001];

int N;

int train_length;
int maxx = -1;

int prefix_sum[50002];




int get_sum(int index) {

	return prefix_sum[index+train_length] - prefix_sum[index];
}

int main(){

	memset(dp, -1, sizeof(dp));

	scanf("%d", &N);

	int summ = 0;

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);

		summ += arr[i];
		prefix_sum[i+1]=summ;
	}


	scanf("%d", &train_length);



	for (int i = N - train_length ; i >= 0; i--) {
		dp[2][i] = max(dp[2][i+1], get_sum(i));
	}

	for (int i = 0; i < N; i++) {
		P("%d ", dp[2][i]);
	}

	for (int i = N - train_length * 2; i >= 0; i--) {
		dp[1][i] = max(dp[1][i + 1], get_sum(i)+dp[2][i + train_length]);
	}
	P("\n");
	for (int i = 0; i < N; i++) {
		P("%d ", dp[1][i]);
	}

	for (int i = N - train_length * 3; i >= 0; i--) {
		dp[0][i] = max(dp[0][i + 1], get_sum(i) + dp[1][i + train_length]);
	}
	P("\n");
	for (int i = 0; i < N; i++) {
		P("%d ", dp[0][i]);
	}

	printf("%d", dp[0][0]);


}