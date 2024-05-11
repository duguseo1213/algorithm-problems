#define _CRT_SECURE_NO_WARNINGS
#define P printf
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <queue>
#include <map>
#include <unordered_map>
using namespace std;

int N, R, Q,M;

vector<int> graph[100010];

int tree[100010];
int visit[100010];

int dfs(int v, int dep)
{
	
	int state = 0;
	int cnt = 0;
	for (int i = 0; i < graph[v].size(); i++)
	{
		if (visit[graph[v][i]] == 0)
		{
			state = 1;
			visit[graph[v][i]] = 1;
			cnt+=dfs(graph[v][i], dep + 1);
		}
	}

	tree[v] = cnt + 1;
	
	return cnt+1;
}

int main()
{
	scanf("%d %d %d", &N, &R, &Q);
	M = N - 1;
	int a, b;
	for (int i = 0; i <M; i++)
	{
		
		scanf("%d %d", &a, &b);

		graph[a].push_back(b);
		graph[b].push_back(a);

	}
	//P("\n");
	visit[R] = 1;
	dfs(R,0);
	for (int i = 0; i < Q; i++)
	{
		scanf("%d", &a);
		printf("%d\n", tree[a]);
	}
}
