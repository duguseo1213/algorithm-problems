#define P
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;
int N, K;
long long dp[100001];
int T;

int main(){

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 2;
	dp[4] = 3;
	dp[5] = 3;
	dp[6] = 6;


	for (int i = 7; i <= 100000; i++) {

		dp[i] = (dp[i - 2] + dp[i - 4] + dp[i - 6])%1000000009;


	}

	
	

	int T;
	scanf("%d", &T);


	int temp;
	for (int i = 0; i < T; i++) {
		scanf("%d", &temp);
		printf("%lld\n", dp[temp] );
	}
	
	

}