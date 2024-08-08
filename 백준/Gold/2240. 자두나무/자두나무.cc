#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int dp[1001][31];

int cnt;
int N;

int main() {
	scanf("%d %d", &N, &cnt);

	
	int temp;
	for (int i = 1; i <= N; i++) {
		scanf("%d", &temp);
		if (temp == 1) {
			dp[i][0]=dp[i-1][0]+1;
		}
		else {
			dp[i][0] = dp[i - 1][0];
		}

		for (int j = 1; j <= 30; j++) {


			if (temp == 1) {
				if (j % 2 == 0) {
					dp[i][j] = max(dp[i-1][j] + 1, dp[i-1][j - 1]+1);
				}
				else {
					dp[i][j]=dp[i-1][j];
				}



			}
			else {
				if (j % 2 == 1) {
					dp[i][j] = max(dp[i-1][j] + 1, dp[i-1][j - 1] + 1);
				}
				else {
					dp[i][j] = dp[i - 1][j] ;
				}
			}

		}
		

	}
	int maxx = 0;

	
	for (int j = 0; j <= cnt; j++) {
		maxx = max(maxx,dp[N][j]);
	}
		
	cout << maxx;



}



