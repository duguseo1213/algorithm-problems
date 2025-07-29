#define P
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <cstring>

using namespace std;

int dp[12];






int main(){

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	for (int i = 4; i < 12; i++) {
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}

	int T;
	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		int temp;
		scanf("%d", &temp);
		printf("%d\n", dp[temp]);
	}
}