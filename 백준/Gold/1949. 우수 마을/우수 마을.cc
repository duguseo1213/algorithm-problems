#define _CRT_SECURE_NO_WARNINGS
#define P printf
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <queue>
#include <map>
#include <unordered_map>
#include <algorithm>
using namespace std;

int N;

int value[10010];
int dp[10010][2];
int visit[10010];
vector<int> graph[10010];
vector<int> trace[10010];

vector<int> answer;

void dfs(int v,int parent)
{
	
	for (int i = 0; i < graph[v].size(); i++)
	{
		if (visit[graph[v][i]] == 0)
		{
			visit[graph[v][i]] = 1;
			dfs(graph[v][i], v);

			


		}
	}
	dp[parent][1] += dp[v][0];
	
	if (dp[v][0] > dp[v][1])
	{
		dp[parent][0] += dp[v][0];

	}
	else
	{
		dp[parent][0] += dp[v][1];
		trace[parent].push_back(v);
	}
	 



}

void dfs2(int v,int state)
{
	
	if (state == 0)
	{
		//printf("%d ", trace[v].size());
		for (int i = 0; i < trace[v].size(); i++)
		{
			if (visit[trace[v][i]] == 0)
			{
				visit[trace[v][i]] = 1;
				answer.push_back(trace[v][i]);
				dfs2(trace[v][i], 1);

			}
			
		}
		for (int i = 0; i < graph[v].size(); i++)
		{
			if (visit[graph[v][i]] == 0)
			{
				visit[graph[v][i]] = 1;
				dfs2(graph[v][i], 0);

			}
		}
		
	}
	else
	{
		for (int i = 0; i < graph[v].size(); i++)
		{
			if (visit[graph[v][i]] == 0)
			{
				visit[graph[v][i]] = 1;
				dfs2(graph[v][i], 0);

			}
		}
	}
}





int main()
{
	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &value[i]);
		dp[i][1] = value[i];

	}
	int a, b;
	for (int i = 0; i < N - 1; i++)
	{
		scanf("%d %d", &a, &b);
		graph[a].push_back(b);
		graph[b].push_back(a);


	}
	visit[1] = 1;
	dfs(1, 0);


		printf("%d\n", max(dp[1][0], dp[1][1]));
	
	/*
	memset(visit, 0, sizeof(visit));

	visit[1] = 1;
	if (dp[1][0] > dp[1][1])
	{
		dfs2(1, 0);
	}
	else
	{
		answer.push_back(1);
		dfs2(1, 1);
	}
	
	sort(answer.begin(), answer.end());

	for (int i = 0; i < answer.size(); i++)
	{
		printf("%d ", answer[i]);
	}*/

}
