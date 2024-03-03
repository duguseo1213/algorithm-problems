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

struct sonnim{
	int sy, sx;

	int dy, dx;
	int end;
	int distance;
};

vector<sonnim> client;
queue<pair<int,int>> q;
int map_[20][20];

int visit[20][20];
long long fuel;
int N, M;
int ty, tx;

int finish = 0;

bool cmp(sonnim a, sonnim b)
{
	if (visit[a.sy][a.sx] == visit[b.sy][b.sx])
	{
		if (a.sy == b.sy)
		{
			return a.sx >= b.sx;
		}

		return a.sy > b.sy;
	}

	return visit[a.sy][a.sx] > visit[b.sy][b.sx];
}

void init(sonnim temp)
{
	memset(visit, 0, sizeof(visit));


	q.push({ temp.sy, temp.sx });
	visit[temp.sy][temp.sx] = 1;

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

			if (map_[ny][nx] == 1) continue;

			if (visit[ny][nx] >= 1) continue;

			visit[ny][nx] = visit[y][x] + 1;
			q.push({ ny,nx });
		}

	}

	if (visit[temp.dy][temp.dx] == 0)
	{
		temp.distance = 1000000000;
	}
	else
	{
		temp.distance = visit[temp.dy][temp.dx] - 1;
	}
	client.push_back(temp);
}

void select()
{
	memset(visit, 0, sizeof(visit));


	q.push({ty,tx });
	visit[ty][tx] = 1;

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

			if (map_[ny][nx] == 1) continue;

			if (visit[ny][nx] >= 1) continue;

			visit[ny][nx] = visit[y][x] + 1;
			q.push({ ny,nx });
		}
	}
	//printf("\n");
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			//printf("%d ",visit[i][j]);

			if (visit[i][j] == 0 && map_[i][j] != 1)
			{
				visit[i][j] = 1000000000;
			}
		}
		//printf("\n");
	}
	
	int index;
	sonnim temp;
	for (int i = 0; i < M; i++) //첫번째 선택
	{
		if (client[i].end == 0)
		{
			temp = client[i];
			index = i;
			break;
		}
	}
	
	for (int i = 0; i < M; i++) 
	{
		if (client[i].end == 1)
		{
			continue;
		}
		
		if (cmp(temp, client[i]))
		{
			temp = client[i];
			index = i;
		}
	}
	
	client[index].end = 1;
	fuel = fuel - visit[temp.sy][temp.sx] - temp.distance+1;
	ty = temp.dy;
	tx = temp.dx;
	//cout << ty << tx <<fuel<< endl;
	if (fuel < 0)
	{
		finish = 1;
	}
	else
	{
		fuel += temp.distance * 2;
	}


}

int main()
{
	cin >> N >> M >> fuel;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &map_[i][j]);
		}
	}

	cin >> ty >> tx;
	ty--;
	tx--;
	sonnim temp;
	for (int i = 0; i < M; i++)
	{
		
		scanf("%d %d %d %d", &temp.sy, &temp.sx, &temp.dy, &temp.dx);
		temp.sy--;
		temp.sx--;
		temp.dy--;
		temp.dx--;
		temp.end = 0;
		init(temp);

	}
	/*
	for (int i = 0; i < M; i++)
	{
		printf("%d %d %d %d %d\n", client[i].sy, client[i].sx, client[i].dy, client[i].dx, client[i].distance);
		
	}*/
	for (int i = 0; i < M; i++)
	{
		select();
		if (finish == 1) break;
	}

	if (finish == 1)
	{
		cout << -1;
		
	}
	else
	{
		cout << fuel;
	}
}