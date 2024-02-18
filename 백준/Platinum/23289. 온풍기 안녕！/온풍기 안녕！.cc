#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int dy[4] = { 0,0,-1,1 };
int dx[4] = { 1,-1,0,0 };

int ddy[4][3] = { -1,0,1, -1,0,1 , -1,-1,-1, 1,1,1 };
int ddx[4][3] = { 1,1,1, -1,-1,-1, -1,0,1, -1,0,1 };

int map[20][20][6];
vector<pair<int, int>> investigate;
vector<pair<int, int>> fan;

queue<pair<int, int>> q;

int R, C, K;
//1,2,3,4 오른 왼 위 아래

void bfs()
{
	for (int k = 0; k < fan.size(); k++)
	{
		int visited[20][20] = { 0, };
		int dir = map[fan[k].first][fan[k].second][5] - 1;

		q.push({ fan[k].first + dy[dir],fan[k].second + dx[dir] });
		visited[fan[k].first + dy[dir]][fan[k].second + dx[dir]] = 5;
		while (!q.empty())
		{
			int y = q.front().first;
			int x = q.front().second;
			q.pop();
			if (visited[y][x] < 1) continue;
			for (int i = 0; i < 3; i++)
			{
				int ny = y + ddy[dir][i];
				int nx = x + ddx[dir][i];
				if (ny<0 || nx<0 || ny>R - 1 || nx>C - 1) continue;
				if (visited[ny][nx] != 0) continue;

				if (dir == 0 )
				{
					if (i == 0)
					{
						if (map[y][x][3] == 1) continue;
					}
					else if (i == 2)
					{
						if (map[y][x][4] == 1) continue;
					}
				}
				else if (dir == 1)
				{
					if (i == 0)
					{
						if (map[y][x][3] == 1) continue;
					}
					else if (i == 2)
					{
						if (map[y][x][4] == 1) continue;
					}
				}

				else if (dir == 2)
				{
					if (i == 0)
					{
						if (map[y][x][2] == 1) continue;
					}
					else if (i == 2)
					{
						if (map[y][x][1] == 1) continue;
					}
				}
				else
				{
					if (i == 0)
					{
						if (map[y][x][2] == 1) continue;
					}
					else if (i == 2)
					{
						if (map[y][x][1] == 1) continue;
					}
				}


				if ((dir) % 2 == 1) //벽의 새로운 조건 추가 해야됨
				{
					if (map[ny][nx][dir] == 1) continue;
				}
				else
				{
					if (map[ny][nx][dir + 2] == 1) continue;
				}

				visited[ny][nx] = visited[y][x] - 1;
				q.push({ ny,nx });

			}


		}

		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
			{
				map[i][j][0] += visited[i][j];
				//printf("%d ", map[i][j][0]);
			}
			//printf("\n");
		}
		//printf("\n");


	}
	/*
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{

			printf("%d ", map[i][j][0]);
		}
		printf("\n");
	}
	printf("\n");
	*/
}

void tempchange() //벽뒤에 조절 안했으
{
	int visited[20][20] = { 0, };
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{

			for (int k = 0; k < 4; k++)
			{
				int ny = i + dy[k];
				int nx = j + dx[k];
				if (ny<0 || nx<0 || ny>R - 1 || nx>C - 1) continue;



				if (map[i][j][0] > map[ny][nx][0])
				{


					if (map[i][j][k + 1] == 1) continue;




					visited[ny][nx] += (map[i][j][0] - map[ny][nx][0]) / 4;
					visited[i][j] -= (map[i][j][0] - map[ny][nx][0]) / 4;
				}


			}

		}
	}

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			map[i][j][0] += visited[i][j];
			//printf("%d ", visited[i][j]);
		}
		//printf("\n");
	}
	//printf("\n");

}

void edge()
{
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if ((i == 0 || j == 0 || i == R - 1 || j == C - 1) && map[i][j][0] > 0) map[i][j][0]--;
		}

	}
}

int main()
{
	cin >> R >> C >> K;

	int chocolate = 0;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			scanf("%d", &map[i][j][0]);
			if (map[i][j][0] > 0 && map[i][j][0] < 5)
			{
				fan.push_back({ i,j });
				map[i][j][5] = map[i][j][0];
				map[i][j][0] = 0;
			}
			else if (map[i][j][0] == 5)
			{
				investigate.push_back({ i,j });
				map[i][j][0] = 0;
			}
		}
	}

	int W;
	cin >> W;
	int y, x, temp;
	for (int i = 0; i < W; i++)
	{
		scanf("%d %d %d", &y, &x, &temp);
		y--;
		x--;
		if (temp == 0)
		{
			map[y][x][3] = 1;
			map[y - 1][x][4] = 1;
		}
		else
		{
			map[y][x][1] = 1;
			map[y][x + 1][2] = 1;
		}
	}
	/*
	for (int k = 0; k < 6; k++)
	{
		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
			{

				printf("%d ", map[i][j][k]);

			}
			printf("\n");
		}
		printf("\n");
	}*/
	while (1)
	{
		int flag = 0;
		//cout << "start" <<chocolate+1<< endl;
		//1번 바람 발사

		bfs();

		//2번 온도 변경

		tempchange();
		/*
		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
			{

				printf("%d ", map[i][j][0]);

			}
			printf("\n");
		}
		printf("\n");
		*/
		//3번 테두리 깍기

		edge();
		/*
		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
			{

				printf("%d ", map[i][j][0]);

			}
			printf("\n");
		}
		printf("\n");
		*/
		//4번 초콜릿먹기
		chocolate++;
		//5번 온도검사

		for (int i = 0; i < investigate.size(); i++)
		{
			if (map[investigate[i].first][investigate[i].second][0] < K)
			{
				flag = 1;
				break;
			}
		}
		if (flag == 0 || chocolate == 101) break;
	}
	cout << chocolate;
}