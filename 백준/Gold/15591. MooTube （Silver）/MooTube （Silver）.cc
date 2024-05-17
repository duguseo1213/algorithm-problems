#define _CRT_SECURE_NO_WARNINGS
#define P printf

#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>

using namespace std;

int arr[5001][5001];

vector<pair<int,int>> graph[5001];
int visit[5001];
queue<pair<int, int>> q;

int N, Q;

void bfs(int start)
{
	q.push({start,2100000000});

	while (!q.empty())
	{
		pair<int, int> now = q.front();
		q.pop();

		for (int i = 0; i < graph[now.first].size(); i++)
		{
			if (visit[graph[now.first][i].first] == 0)
			{
				visit[graph[now.first][i].first] = 1;
				int minn = min(graph[now.first][i].second, now.second);
				arr[start][graph[now.first][i].first] = minn;
				q.push({ graph[now.first][i].first ,minn });



			}
		}
	}


}

int main() 
{
	scanf("%d %d", &N, &Q);

	int a, b, c;

	for (int i = 0; i < N - 1; i++)
	{
		scanf("%d %d %d", &a, &b, &c);
		graph[a].push_back({ b,c });
		graph[b].push_back({ a,c });

	}

	for (int i = 1; i <= N; i++)
	{
		memset(visit, 0, sizeof(visit));
		bfs(i);
	}
	/*
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}*/

	for (int i = 0; i < Q; i++)
	{
		scanf("%d %d", &a, &b);
		int cnt = 0;
		for (int j = 1; j <= N; j++)
		{
			if (b == j) continue;

			if (arr[b][j] >= a)
			{
				cnt++;
			}


		}
		printf("%d\n", cnt);
	}


}