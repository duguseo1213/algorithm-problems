#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

int dy[4] = { 0,0,-1,1 };
int dx[4] = { 1,-1,0,0 };
int pic[4][3];
int N, M;
int role;
int dice_map[20][20];

int main()
{
	int sy, sx;
	cin >> N >> M >> sy >> sx>>role;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%d", &dice_map[i][j]);
		}
	}

	int dir;
	for (int i = 0; i < role; i++)
	{
		scanf("%d", &dir);
		dir--;
		int ny = sy + dy[dir];
		int nx = sx + dx[dir];

		if (nx<0 || ny<0 || ny>N - 1 || nx>M - 1) continue;
		
		if (dice_map[ny][nx] == 0)
		{
			int temp;
			if (dir == 0)
			{
				temp = pic[1][2];
				pic[1][2] = pic[1][1];
				pic[1][1] = pic[1][0];
				pic[1][0] = pic[3][1];
				pic[3][1] = temp;
			}

			else if (dir == 1)
			{
				temp = pic[1][0];
				pic[1][0] = pic[1][1];
				pic[1][1] = pic[1][2];
				pic[1][2] = pic[3][1];
				pic[3][1] = temp;
			}

			else if (dir == 2)
			{
				temp = pic[0][1];
				pic[0][1] = pic[1][1];
				pic[1][1] = pic[2][1];
				pic[2][1] = pic[3][1];
				pic[3][1] =temp;

			}
			else
			{
				temp = pic[2][1];
				pic[2][1] = pic[1][1];
				pic[1][1] = pic[0][1];
				pic[0][1] = pic[3][1];
				pic[3][1] = temp;
			}
			dice_map[ny][nx] = pic[3][1];
		}

		else
		{

			if (dir == 0)
			{
				pic[1][2] = pic[1][1];
				pic[1][1] = pic[1][0];
				pic[1][0] = pic[3][1];
				pic[3][1] = dice_map[ny][nx];
			}

			else if (dir == 1)
			{
				pic[1][0] = pic[1][1];
				pic[1][1] = pic[1][2];

				pic[1][2] = pic[3][1];

				pic[3][1] = dice_map[ny][nx];
			}

			else if (dir == 2)
			{
				pic[0][1] = pic[1][1];
				pic[1][1] = pic[2][1];
				pic[2][1] = pic[3][1];
				pic[3][1] = dice_map[ny][nx];

			}
			else
			{
				pic[2][1] = pic[1][1];
				pic[1][1] = pic[0][1];
				pic[0][1] = pic[3][1];
				pic[3][1] = dice_map[ny][nx];
			}
			dice_map[ny][nx] = 0;
		}
		printf("%d\n", pic[1][1]);
		sy = ny;
		sx = nx;

	}


}
