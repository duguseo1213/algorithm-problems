#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int dp[1001][1001]; //



int main() {
	
	for (int i = 1; i < 1001; i++) {
		dp[1][i] = i;
	}

	for (int j = 4; j < 1001; j++) {
		dp[2][j] = (dp[2][j - 1] + dp[1][j - 2]) % 1000000003;
	}

	for (int i = 3; i < 1001; i++) {
		for (int j = 2; j < 1001; j++) {

			dp[i][j] = (dp[i][j - 1] + dp[i - 1][j - 2])%1000000003;
		}
	}

	int N, M;

	cin >> N >> M;

	cout << dp[M][N] % 1000000003;

}



