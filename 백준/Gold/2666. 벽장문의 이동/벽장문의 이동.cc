#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cstring>
using namespace std;

int N;

int l, r;
int cnt;

int order[21];
int answer=21e8;

int dp[21][21][21];


int dfs(int left,int right,int depth) {

	if (depth == cnt) {

		return 0;
	}

	if (dp[depth][left][right] == -1) {
		dp[depth][left][right] = min(abs(left - order[depth]) + dfs(order[depth], right, depth + 1), abs(right - order[depth]) + dfs(left, order[depth], depth + 1));


		return dp[depth][left][right];
	}
	else {
		return dp[depth][left][right];
	}
	
	
	
	
	

	

	


}

int main()
{
	memset(dp, -1, sizeof(dp));

	scanf("%d", &N);

	scanf("%d %d", &l, &r);

	scanf("%d", &cnt);

	for (int i = 0; i < cnt; i++) {
		scanf("%d", &order[i]);
	}

	

	printf("%d", dfs(l, r, 0));
   
}