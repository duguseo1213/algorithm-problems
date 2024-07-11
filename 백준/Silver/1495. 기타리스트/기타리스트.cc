#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int arr[51];
int dp[51][1001];

int N,M,S;

int main() {
	scanf("%d %d %d", &N, &S, &M);

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	dp[0][S] = 1;

	for (int i = 0; i < N; i++) {
		//printf("1");
		for (int j = 0; j <= M; j++) {

			if (dp[i][j] == 1) {

				int temp1 = j + arr[i];
				int temp2 = j - arr[i];

				if (temp2 >= 0) {
					dp[i + 1][temp2] = 1;
				}

				if (temp1 <= M) {
					dp[i + 1][temp1] = 1;
				}
			}

		}
	}
	
	int answer = -1;
	for (int i = 0; i <= M; i++) {
		if (dp[N][i] == 1) {
			answer = i;
		}
	}
	printf("%d", answer);


}
