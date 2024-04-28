#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

int N,M;

int a, b;

vector<int> graph[50010];
int level[50010];
int parent[50010];
int visit[50010];
void dfs(int node,int lev) //level 정해주기
{
	//printf("%d ", node);
	level[node] = lev;

	for (int i = 0; i < graph[node].size(); i++)
	{
		if (visit[graph[node][i]] == 0)
		{
			visit[graph[node][i]] =1;


			dfs(graph[node][i], lev + 1);

		}
	}


}

int find_parent(int first,int second)
{
	if (level[first] > level[second])
	{
		while (1)
		{
			first = parent[first];
			if (level[first] == level[second])
			{
				break;
			}
		}
	}
	else if (level[first] < level[second])
	{
		while (1)
		{
			second = parent[second];
			if (level[first] == level[second])
			{
				break;
			}
		}
	}

	while (1)
	{
		if (first == second)
		{
			break;
		}

		first = parent[first];
		second = parent[second];
	}


	return first;

}

int main()
{
	int T;
	scanf("%d", &T);

	for (int t = 0; t < T; t++)
	{
		for (int i = 0; i < 20000; i++)
		{
			graph[i].clear();
		}
		memset(visit, 0, sizeof(visit));
		memset(level, 0, sizeof(level));
		memset(parent, 0, sizeof(parent));


		scanf("%d", &M);
		int aa, bb;
		for (int i = 0; i < M - 1; i++)
		{
			
			scanf("%d %d", &aa, &bb);

			graph[aa].push_back(bb);
			graph[bb].push_back(aa);

			parent[bb] = aa;

		}

		int root=bb;

		while (1)
		{
			if (parent[root] == 0)
			{
				break;
			}

			root = parent[root];
		}




		visit[root] = 1;
		dfs(root, 0);


		
		scanf("%d %d", &a, &b);


		int anc = find_parent(a, b);
		printf("%d\n", anc);
		
	}
}
