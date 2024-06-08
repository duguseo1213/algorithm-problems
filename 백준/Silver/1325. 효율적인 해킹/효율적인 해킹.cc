#define _CRT_SECURE_NO_WARNINGS
#define P 

#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>

using namespace std;

vector<int> graph[10001];
int N, M;
int visit[10001];
int answer[10001];
int dfs(int now)
{

	int sum = 0;
	int state = 0;
	P("%d ", now);
	for (int i = 0; i < graph[now].size(); i++)
	{
		
		if (visit[graph[now][i]] == 0)
		{
			state = 1;
			visit[graph[now][i]] = 1;
			
			sum+=dfs(graph[now][i]);

			
		}
	}
	if (state == 0)
	{
		return 1;
	}
	else
	{
		return sum+1;
	}

	

	//return 1;



}



int main() 
{
	scanf("%d %d", &N, &M);

	for (int i = 0; i < M; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);

		graph[b].push_back(a);
	}
	P("\n");
	for (int i = 1; i <= N; i++)
	{
		memset(visit, 0, sizeof(visit));
		visit[i] = 1;
		answer[i]=dfs(i);

		P("%d %d\n", i, answer[i]);
	}

	int maxx = 0;

	for (int i = 1; i <= N; i++)
	{
		maxx=max(answer[i], maxx);
	}

	for (int i = 1; i <= N; i++)
	{
		if (answer[i] == maxx)
		{
			printf("%d ", i);
		}
	}

	
}