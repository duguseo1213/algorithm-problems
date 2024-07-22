#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

long long dp[16][65537]; //현재 위치에서 도착지점까지의 최소 거리
long long arr[16][16];
int N;

int dfs(int visit, int v) {


	if (visit == (1<<N)-1) {

		return 0;

	}

	//printf("vertex %d\n", v);
	
	int state = 0;
	for (int i = 1; i < N; i++) {

		if ((visit | (1 << i)) != visit) {
			state = 1;
			if (arr[v][i] == 0) continue;
			long long temp=21e13;

			if (dp[i][visit | (1 << i)] == 21e13) {

				temp = dfs(visit | (1 << i), i);
			}
			else {

				temp = dp[i][visit | (1 << i)];
			}
			
			 

			dp[v][visit] = min(dp[v][visit],temp + arr[v][i]);


		}



	}


	

	if (state == 0 && arr[v][0] != 0) {

		dp[v][visit] = arr[v][0];
	}
	
	//printf("%d %d %d\n", v, visit, dp[v][visit]);

	return dp[v][visit];



}

int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {

			scanf("%lld", &arr[i][j]);


		}
	}


	for (int i = 0; i < 16; i++) {

		for (int j = 0; j < 65536; j++) {
			dp[i][j] = 21e13;
		}
	}
	
	printf("%lld", dfs(0, 0));

	
}
