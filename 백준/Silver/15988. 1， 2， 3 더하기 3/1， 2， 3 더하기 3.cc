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



long long dp[1000001];


int main(){

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	for (int i = 4; i < 1000001; i++) {
		dp[i] = (dp[i - 1]  + dp[i - 2]  + dp[i - 3] )%1000000009;
	}
	int t;
	scanf("%d", &t);

	int temp;
	for (int i = 0; i < t; i++) {
		scanf("%d",&temp);
		printf("%d\n", dp[temp]);
	}
	
	

}