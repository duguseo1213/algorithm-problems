#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <map>
#include <cmath>
using namespace std;

int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };

int N, M;
vector<pair<int, int>> zero;
vector<pair<int, int>> virus;
queue<pair<int, int>> q;
int map_[8][8];
int maxx = 0;
int colcount = 3;
void bfs()
{
	int visit[8][8] = { 0, };
	for (int i = 0; i < virus.size(); i++)
	{
		q.push({ virus[i].first,virus[i].second });
		visit[virus[i].first][virus[i].second] = 1;
	}



	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;

		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny<0 || nx<0 || nx>M - 1 || ny>N - 1) continue;

			if (visit[ny][nx] == 1) continue;
			if (map_[ny][nx] == 1) continue;

			q.push({ ny,nx });
			visit[ny][nx] = 1;

		}

	}
	int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			//printf("%d ", visit[i][j]);
			if (visit[i][j] == 0)
			{
				cnt++;
			}
		}
		//printf("\n");
	}

	maxx = max(cnt-colcount, maxx);


}

void choose(int dep,int s)
{
	if (dep == 3)
	{
		bfs();
		return;
	}
	for (int i = s; i < zero.size(); i++)
	{

		map_[zero[i].first][zero[i].second] = 1;
		choose(dep + 1, i + 1);
		map_[zero[i].first][zero[i].second] = 0;

	}


	
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%d", &map_[i][j]);
			if (map_[i][j] == 2)
			{
				virus.push_back({ i,j });
			}
			else if(map_[i][j] == 0)
			{
				zero.push_back({ i,j });
			}
			else
			{
				colcount++;
			}

		}
	}
	choose(0,0);
	cout << maxx;

}