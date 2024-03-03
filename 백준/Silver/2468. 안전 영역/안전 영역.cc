#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <queue>
#include <cstring>
using namespace std;

int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };


int map_[100][100];
int temp[100][100];
int visit[100][100];

queue<pair<int,int>> q;

int N;
void bfs(int y,int x,int color)
{

	q.push({ y,x });

	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;

		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny<0 || nx<0 || ny>N - 1 || nx>N - 1) continue;

			if (temp[ny][nx] < 1) continue;

			if (visit[ny][nx] != 0) continue;

			visit[ny][nx] = color;
			q.push({ ny,nx });

		}

	}
	
}

int main()
{
	cin >> N;

	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &map_[i][j]);
		}
	}
	int maxx = 0;
	int answer = 0;
	for (int depth = 0; depth <= 100; depth++)
	{
		memset(visit, 0, sizeof(visit));
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				temp[i][j] = map_[i][j]-depth;
			}
		}
	
	
		int color = 1;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (temp[i][j]>0 && visit[i][j] == 0)
				{
					bfs(i, j, color);
					color++;
				}
			}
		}
		/*
		printf("\n");
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				printf("%d ", visit[i][j]);
			}
			printf("\n");
		}
		cout << maxx;
		*/

		if (maxx < color - 1)
		{
			maxx = color - 1;
			answer = depth;
		}



	}
	cout << maxx;
}