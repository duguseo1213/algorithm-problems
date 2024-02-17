#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

int fish[4][4][10]; //8는 상어 9은 냄새

int dy[8] = { 0,-1,-1,-1,0,1,1,1 };
int dx[8] = { -1,-1,0,1,1,1,0,-1 };

int shark_dy[4] = { -1,0,1,0 };
int shark_dx[4] = { 0,-1,0,1 }; //상어는 dfs로 구현
int temp2[4][4][10];
int M, S;

int vv[4][4];

int visit[3][2];
int maxvisit[3][2];
int maxkill;
void dfs(int y, int x, int dep, int sum)
{

	if (dep == 3)
	{
		if (sum > maxkill)
		{
			maxkill = sum;
			copy(&visit[0][0], &visit[0][0] + 6, &maxvisit[0][0]);
		}
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int ny = y + shark_dy[i];
		int nx = x + shark_dx[i];
		int state = 0;
		if (ny < 0 || nx < 0 || ny>3 || nx>3) continue; //갔던곳 안돌아올 여지있음
		if (vv[ny][nx] == 1)
		{
			visit[dep][0] = ny;
			visit[dep][1] = nx;


			dfs(ny, nx, dep + 1, sum);

		}
		else
		{
			visit[dep][0] = ny;
			visit[dep][1] = nx;
			int temp = 0;
			for (int j = 0; j < 8; j++)
			{
				temp = temp + fish[ny][nx][j];
			}
			vv[ny][nx] = 1;
			dfs(ny, nx, dep + 1, sum + temp);
			vv[ny][nx] = 0;
		}


	}
}

int main()
{
	cin >> M >> S;
	int fy, fx, d;
	for (int i = 0; i < M; i++)
	{
		scanf("%d %d %d", &fy, &fx, &d);
		fish[fy - 1][fx - 1][d - 1]++;
	}
	int sy, sx;
	scanf("%d %d", &sy, &sx);
	sy--;
	sx--;
	fish[sy][sx][8] = 1;


	for (int qwe = 0; qwe < S; qwe++)
	{

		memset(vv, 0, sizeof(vv));
		memset(visit, 0, sizeof(visit));
		memset(maxvisit, 0, sizeof(maxvisit));
		memset(temp2, 0, sizeof(temp2));
		maxkill = -1;


		int temp[4][4][10];

		copy(&fish[0][0][0], &fish[0][0][0] + 160, &temp[0][0][0]);    // 1번 복제마법





		for (int i = 0; i < 4; i++) //2번 물고기 한칸 이동
		{
			for (int j = 0; j < 4; j++)
			{
				for (int l = 0; l < 8; l++)
				{
					if (fish[i][j][l] == 0) continue;
					int dir = l + 1;
					int cnt = 0;


					while (1)
					{

						if (cnt == 8) break;
						dir = dir - 1;
						if (dir < 0) dir = dir + 8;
						int ny = i + dy[dir];
						int nx = j + dx[dir];

						cnt++;
						if (ny < 0 || nx < 0 || ny>3 || nx>3) continue; //범위 벗어나면

						if (fish[ny][nx][8] == 1) continue; // 상어 있다면

						if (fish[ny][nx][9] != 0) continue; //냄새 있다면

						

						temp2[ny][nx][dir] = temp2[ny][nx][dir] + fish[i][j][l];
						fish[i][j][l] = 0;

						break;

					}
					if (cnt == 8)
					{
						temp2[i][j][l] = temp2[i][j][l] + fish[i][j][l];
					}


				}
			}
		}


		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				temp2[i][j][9] = fish[i][j][9];
			}

		}


		copy(&temp2[0][0][0], &temp2[0][0][0] + 160, &fish[0][0][0]);



		dfs(sy, sx, 0, 0);
		for (int j = 0; j < 8; j++)
		{
			for (int i = 0; i < 3; i++)
			{

				if (fish[maxvisit[i][0]][maxvisit[i][1]][j] > 0)
				{
					fish[maxvisit[i][0]][maxvisit[i][1]][9] = 3;
				}
				fish[maxvisit[i][0]][maxvisit[i][1]][j] = 0;

			}
		}


		fish[sy][sx][8] = 0;

		sy = maxvisit[2][0];
		sx = maxvisit[2][1];
		fish[sy][sx][8] = 1;
		for (int i = 0; i < 4; i++) //냄새 제거
		{
			for (int j = 0; j < 4; j++)
			{
				if (fish[i][j][9] > 0)
				{
					fish[i][j][9] = fish[i][j][9] - 1;
				}
			}
		}


		for (int l = 0; l < 8; l++) // 5. 복제 하기
		{
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					fish[i][j][l] = fish[i][j][l] + temp[i][j][l];
					//printf("%d", fish[i][j][l]);

				}
				//printf("\n");
			}
			//printf("\n");
		}



	}
	int finale = 0;
	for (int l = 0; l < 8; l++)
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				finale = finale + fish[i][j][l];

			}

		}

	}
	cout << finale;
}
