#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>//memset
#include <string>
#include <vector>

using namespace std;

int N;

vector<int> graph[10001];
int dp[10001][2];
int value[10001];
int visit[10001];


void dfs(int v) {




	for (int i = 0; i < graph[v].size(); i++) {

		if (visit[graph[v][i]] == 0) {
			visit[graph[v][i]] = 1;

			dfs(graph[v][i]);

			dp[v][0] += max(dp[graph[v][i]][1], dp[graph[v][i]][0]);
			dp[v][1] +=  dp[graph[v][i]][0];
		}

	}


}

int main() {
	
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &value[i]);
		dp[i][1] = value[i];
	}

	for (int i = 0; i < N - 1; i++) {
		int a, b;

		scanf("%d %d", &a, &b);

		graph[a].push_back(b);
		graph[b].push_back(a);



	}

	visit[1] = 1;

	dfs(1);

	printf("%d", max(dp[1][0], dp[1][1]));

}