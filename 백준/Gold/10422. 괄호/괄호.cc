#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
using namespace std;


int N, K;

int dp[5001][5001];




int main() {
	
	for (int i = 1; i < 5001; i++) {
		
		dp[i][i] = 1;
		
	}

	for (int i = 2; i < 5001; i++) {
		for (int j = 0; j < i; j++) {
			if (j == 0 && i%2==0) {
				dp[0][i] = dp[1][i-1];
				continue;
			}

			if (i % 2 == 0 && j%2==0) {
				dp[j][i] = (dp[j-1][i-1] + dp[j+1][i-1])%1000000007;
			}

			if (i % 2 == 1 && j % 2 == 1) {
				dp[j][i] = (dp[j - 1][i - 1] + dp[j + 1][i - 1]) % 1000000007;
			}
		}
	}

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		int temp;

		scanf("%d", &temp);

		printf("%d\n",dp[0][temp]);
	}


	
}
