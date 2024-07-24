#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

vector<int> graph[100];
queue<int> q;

int N,M;
int arr[100][100];
int temp[100][100];

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };


int visit[101];
int cnt = 0;
void bfs(int r)
{
	visit[r] = 1;
	q.push(r);

	while (q.size() > 0)
	{
		r = q.front();
		for (int i = 0; i < graph[r].size(); i++)
		{
			if (visit[graph[r][i]] == 0)
			{
				visit[graph[r][i]] = 1;
				q.push(graph[r][i]);

			}
		}
		q.pop();
		cnt++;
	}


}



int main()
{
	
	cin >> N;
	
	cin >> M;
	int a, b;
	for (int i = 0; i < M; i++)
	{
		scanf("%d %d", &a, &b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	
	bfs(1);
	cout << cnt-1;


}