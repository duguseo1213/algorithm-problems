#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cstring>
using namespace std;

int dp[1001][1001];
int N, M;

int arr[1001];


int func(int cnt,int line) {

	

	if (cnt == N-1) {
		return 0;
	}


	if (dp[cnt][line] != 21e8) {
		return dp[cnt][line];
	}

	int temp = M;

	int i = cnt;

	while (1) {

		temp = temp - arr[i];

		if (temp < 0) {
			return dp[cnt][line];
		}

		

		if (i == N) {
			
			return 0;

		}
		dp[cnt][line] = min(dp[cnt][line], func(i + 1, line + 1) + temp * temp);



		
		//if (temp <= 1) break;
		temp--;

		
		i++;

	}
	//temp++;
	//dp[cnt][line] = min(dp[cnt][line], temp * temp);
	
	//printf("%d %d %d\n", cnt, line,dp[cnt][line]);

	return dp[cnt][line];


}


int main()
{
	
	memset(dp, -1, sizeof(dp));

	for (int i = 0; i < 1001; i++) {
		for (int j = 0; j < 1001; j++) {
			dp[i][j] = 21e8;
		}
	}


	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {

		scanf("%d", &arr[i]);

	}

	printf("%d", func(0, 0));



}