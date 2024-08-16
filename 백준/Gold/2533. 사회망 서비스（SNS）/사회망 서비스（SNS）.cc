#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>//memset
#include <string>
#include <vector>

using namespace std;

int N;

vector<int> graph[1000001];
int dp[1000001][2];
int visit[1000001];


void dfs(int v) {

	for (int i = 0; i < graph[v].size(); i++) {

		if (visit[graph[v][i]] == 0) {
			visit[graph[v][i]] = 1;

			dfs(graph[v][i]);

			dp[v][1] += min(dp[graph[v][i]][0], dp[graph[v][i]][1]);
			dp[v][0] += dp[graph[v][i]][1];

			
		}

	}


}

int main() {
	
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		dp[i][1] = 1;
		
	}

	for (int i = 0; i < N - 1; i++) {
		int a, b;

		scanf("%d %d", &a, &b);

		graph[a].push_back(b);
		graph[b].push_back(a);



	}

	visit[1] = 1;

	dfs(1);

	printf("%d", min(dp[1][0], dp[1][1]));

}