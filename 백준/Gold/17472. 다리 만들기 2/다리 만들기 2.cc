#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

queue<pair<int, int>> q;
int N, M;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int arr[10][10];

int visit[10][10];

int graph[10][10];

int vis[8];

int u[100];

int find(int tar)
{
	if (u[tar] == tar)
	{
		return tar;
	}

	int root = find(u[tar]);

	return root;


}

void setunion(int a, int b)
{
	int t1 = find(a);
	int t2 = find(b);
	if (t1 == t2) return;

	u[t2] = t1;

}



struct edge {

	int a, b;
	int cost;

};

int cmp(edge a, edge b)
{
	return a.cost < b.cost;
}

vector<edge> edges;


void numbering(int y, int x, int num)
{
	q.push({ y,x });

	arr[y][x] = num;
	visit[y][x] = 1;
	while (q.size() > 0)
	{
		y = q.front().first;
		x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny<0 || nx<0 || ny>N - 1 || nx>M - 1) continue;

			if (visit[ny][nx] == 1) continue;
			if (arr[ny][nx] == 0) continue;
			visit[ny][nx] = 1;


			arr[ny][nx] = num;

			q.push({ ny,nx });

		}

	}

}



int main()
{
	
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}

	int num = 2;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (visit[i][j] == 0 && arr[i][j] == 1)
			{
				//cout << num << endl;
				numbering(i, j, num);
				num++;
			}
		}
	}
	/*
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			printf("%d ", arr[i][j]);

		}
		printf("\n");
	}*/

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			graph[i][j] = 100;
		}

	}

	for (int i = 0; i < N; i++)
	{
		int temp = 10000;
		int tempi = 10000;
		for (int j = 0; j < M; j++)
		{
			if (arr[i][j] != 0)
			{
				if (j - tempi - 1 > 1 && arr[i][j] != temp)
				{

					graph[arr[i][j]][temp] = min(graph[arr[i][j]][temp], j - tempi - 1);
					graph[temp][arr[i][j]] = min(graph[arr[i][j]][temp], j - tempi - 1);
				}
				temp = arr[i][j];
				tempi = j;
			}
		}
	}

	for (int i = 0; i < M; i++)
	{
		int temp = 10000;
		int tempi = 10000;
		for (int j = 0; j < N; j++)
		{
			if (arr[j][i] != 0)
			{

				if (j - tempi - 1 > 1 && arr[j][i] != temp)
				{

					graph[arr[j][i]][temp] = min(graph[arr[j][i]][temp], j - tempi - 1);
					graph[temp][arr[j][i]] = min(graph[arr[j][i]][temp], j - tempi - 1);
				}
				temp = arr[j][i];
				tempi = j;

			}
		}

	}




	//cout << endl;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (graph[i][j] == 100) graph[i][j] = 0;
			//printf("%d ", graph[i][j]);
		}
		//printf("\n");
	}

	num = num - 2;


	for (int i = 0; i < 90; i++)
	{
		u[i] = i;
	}


	for (int i = 0; i < 10; i++)
	{
		for (int j = i; j < 10; j++)
		{
			if (graph[i][j] != 0)
			{
				edges.push_back({ i,j,graph[i][j]});
			}
		}
	}
	int cnt = 0;
	int sum = 0;


	sort(edges.begin(), edges.end(),cmp);

	for (int i = 0; i < edges.size(); i++)
	{
		if (find(edges[i].a) == find(edges[i].b))
		{
			continue;
		}

		setunion(edges[i].a, edges[i].b);
		cnt++;
		sum = sum + edges[i].cost;
		if (cnt == num - 1)
		{
			break;
		}
	}
	if (cnt != num - 1)
	{
		cout << -1;
	}
	else
	{

		cout << sum;
	}

}