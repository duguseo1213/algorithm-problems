#define P 
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;

int dp[70][70][70];

int arr[3];

void func(int a, int b, int c) {

	for (int i = 0; i <= 9; i++) {
		for (int j = 0; j <= 3; j++) {
			for (int k = 0; k <= 1; k++) {
				dp[a + i][b + j][c + k] = min(dp[a + i][b + j][c + k] , dp[a][b][c] + 1);
			}
		}
	}

	for (int i = 0; i <= 9; i++) {
		for (int j = 0; j <= 1; j++) {
			for (int k = 0; k <= 3; k++) {
				dp[a + i][b + j][c + k] = min(dp[a + i][b + j][c + k], dp[a][b][c] + 1);
			}
		}
	}

	for (int i = 0; i <= 3; i++) {
		for (int j = 0; j <= 9; j++) {
			for (int k = 0; k <= 1; k++) {
				dp[a + i][b + j][c + k] = min(dp[a + i][b + j][c + k], dp[a][b][c] + 1);
			}
		}
	}

	for (int i = 0; i <= 3; i++) {
		for (int j = 0; j <= 1; j++) {
			for (int k = 0; k <= 9; k++) {
				dp[a + i][b + j][c + k] = min(dp[a + i][b + j][c + k], dp[a][b][c] + 1);
			}
		}
	}

	for (int i = 0; i <= 1; i++) {
		for (int j = 0; j <= 3; j++) {
			for (int k = 0; k <= 9; k++) {
				dp[a + i][b + j][c + k] = min(dp[a + i][b + j][c + k], dp[a][b][c] + 1);
			}
		}
	}

	for (int i = 0; i <= 1; i++) {
		for (int j = 0; j <= 9; j++) {
			for (int k = 0; k <= 3; k++) {
				dp[a + i][b + j][c + k] = min(dp[a + i][b + j][c + k], dp[a][b][c] + 1);
			}
		}
	}

}


int main() {
	
	for (int i = 0; i <= 60; i++) {
		for (int j = 0; j <= 60; j++) {
			for (int k = 0; k <= 60; k++) {
				dp[i][j][k] = 21e8;
				if (i <= 9 && j <= 3 && k <= 1) {
					dp[i][j][k] = 1;
				}
				if (i <= 3 && j <= 9 && k <= 1) {
					dp[i][j][k] = 1;
				}
				if (i <= 9 && j <= 1 && k <= 3) {
					dp[i][j][k] = 1;
				}
				if (i <= 3 && j <= 1 && k <= 9) {
					dp[i][j][k] = 1;
				}
				if (i <= 1 && j <= 3 && k <= 9) {
					dp[i][j][k] = 1;
				}
				if (i <= 1 && j <= 9 && k <= 3) {
					dp[i][j][k] = 1;
				}


			}
		}
	}
	dp[0][0][0] = 0;
	for (int i = 0; i <= 60; i++) {
		for (int j = 0; j <= 60; j++) {
			for (int k = 0; k <= 60; k++) {
				
				func(i, j, k);
			}
		}
	}


	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	if (N == 3) {
		printf("%d", dp[arr[0]][arr[1]][arr[2]]);
	}
	else if (N == 2) {
		printf("%d", dp[arr[0]][arr[1]][0]);
	}
	else {
		printf("%d", dp[arr[0]][0][0]);
	}

}