#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <unordered_map>
#include <cstring>

using namespace std;

struct Edge {
	//int start;
	int end;
	int cost;
};

vector<Edge> NODE[100001];

queue<int> q;
int visit[100001];

int N, M;

int bfs(int s,int e,int weight)
{
	memset(visit, 0, sizeof(visit));
	visit[s] = 1;
	q.push(s);

	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		for (int i = 0; i < NODE[now].size(); i++)
		{
			if (NODE[now][i].cost >= weight && visit[NODE[now][i].end]==0)
			{
				if (NODE[now][i].end == e)
				{
					return 1;
				}
				visit[NODE[now][i].end] = 1;
				q.push(NODE[now][i].end);
			}

		}
	}

	return 0;

}


int main()
{
	scanf("%d %d", &N, &M);

	int start, end, cost;
	Edge temp;
	for (int i = 0; i < M; i++)
	{
		scanf("%d %d %d", &start, &end, &cost);

		NODE[start].push_back({ end,cost });
		NODE[end].push_back({ start,cost });
	}
	scanf("%d %d", &start, &end);

	//printf("%d", bfs(start, end,3));


	int i = 0;
	int j = 1000000000;
	int weight;
	while (1)
	{
		while (!q.empty())
		{
			q.pop();
		}
		

		if (i > j) break;

		int mid = (i + j) / 2;

		if (bfs(start,end,mid))
		{
			weight = mid;
			i = mid + 1;
		}
		else
		{
			j = mid - 1;
		}


	}

	printf("%d", weight);
	


}