#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

int dy[4] = { -1,0,0,1 };
int dx[4] = { 0,-1,1,0 };

int map_[20][20];

struct fish {
	int num;
	int y;
	int x;

};

vector<fish> fishes;

int shark_y;
int shark_x;
int shark_size;
int N;
int to_be_big;
int t;
int state;
queue<pair<int, int>> q;

int miny;
int minx;
int mindist;
void bfs()
{
	
	int visited[20][20] = { 0, };
	q.push({ shark_y ,shark_x });
	visited[shark_y][shark_x] = 1;
	miny = 21e8;
	minx = 21e8;
	mindist = 21e8;
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

			if (visited[ny][nx] != 0) continue;

			if (map_[ny][nx] > shark_size) continue;

			if (map_[ny][nx] < shark_size && map_[ny][nx]>0 && visited[y][x]<=mindist)
			{
				mindist = visited[y][x];
				if (ny <= miny)
				{
					if (ny == miny)
					{
						if (nx < minx)
						{
							miny = ny;
							minx = nx;
						}
					}
					else
					{
						miny = ny;
						minx = nx;
					}


				}
				state = 1;
			}

			q.push({ ny,nx });
			visited[ny][nx] = visited[y][x] + 1;

		}
		
	}
	if (state == 1)
	{
		map_[miny][minx] = 0;
		to_be_big--;
		if (to_be_big == 0)
		{
			shark_size++;
			to_be_big = shark_size;
		}
		state = 1;
		t = t + visited[miny][minx] - 1;
		shark_y = miny;
		shark_x = minx;
	}

	while (!q.empty())
	{
		q.pop();
	}
	/*
	printf("\n");
	printf("%d %d\n",shark_y,shark_x);
	printf("\n");
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			printf("%d ", visited[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			printf("%d ", map_[i][j]);
		}
		printf("\n");
	}
	cout <<"time" << t;
	printf("\n");
	*/
}


int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &map_[i][j]);

			if (map_[i][j] == 9)
			{
				shark_y = i;
				shark_x = j;
				map_[i][j] = 0;
			}

		}
	}
	shark_size = 2;
	to_be_big = 2;
	//여러번 반복할 예정

	while (1)
	{
		state = 0;
		bfs();
		if (state == 0) break;
	}
	cout << t;
}
