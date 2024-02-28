#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <cstring>
#include <climits>
#include <map>
#include <deque>
#include <cmath>

using namespace std;

int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };

struct house {

	int y;
	int x;
	int dist;
};

int N, M;
int map_[50][50];

vector<house> h;
vector<pair<int, int>> chicken;
queue<pair<int, int>> q;
int visit[13];

int minn = 987654321;

void bfs()
{
	int d[50][50];
	for (int j = 0; j < h.size(); j++)
	{
		
		h[j].dist=987654321;
	}
	for (int i = 0; i < chicken.size(); i++)
	{
		memset(d, 0, sizeof(d));
		if (visit[i] == 1)
		{
			q.push({ chicken[i].first,chicken[i].second });
			d[chicken[i].first][chicken[i].second] = 1;
			while (!q.empty())
			{
				int y = q.front().first;
				int x = q.front().second;
				q.pop();
				for (int j = 0; j < 4; j++)
				{
					int ny = y + dy[j];
					int nx = x + dx[j];

					if (ny<0 || nx<0 || ny> N - 1 || nx>N - 1) continue;

					if (d[ny][nx] != 0) continue;

					q.push({ ny,nx });
					d[ny][nx] = d[y][x] + 1;
				}

			}
			
			for (int j = 0; j < h.size(); j++)
			{
				h[j].dist = min(h[j].dist, d[h[j].y][h[j].x]-1);
			}



		}
		
	}
	int sum = 0;
	for (int j = 0; j < h.size(); j++)
	{
		
		sum+=h[j].dist;
	}
	
	minn = min(minn, sum);


}

void func(int dep,int s)
{
	if (dep == M)
	{
		/*
		for (int i = 0; i < chicken.size(); i++)
		{
			printf("%d ", visit[i]);
		}
		printf("\n");
		*/
		bfs();
		return;
	}

	for (int i = s; i < chicken.size(); i++)
	{
		if (visit[i] == 0)
		{
			visit[i] = 1;
			func(dep + 1, i + 1);
			visit[i] = 0;

		}

	}
	   

}


int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &map_[i][j]);
			if (map_[i][j] == 1)
			{
				h.push_back({ i,j,987654321 });
			}
			else if (map_[i][j] == 2)
			{
				chicken.push_back({ i,j });
			}
		}
	}

	func(0,0);
	
	cout << minn;
}