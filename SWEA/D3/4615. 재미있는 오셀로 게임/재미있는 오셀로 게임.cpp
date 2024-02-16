#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

int board[8][8];
queue<pair<int,int>> q;

int dx[8] = { 0,0,1,-1,1,1,-1,-1 };
int dy[8] = { 1,-1,0,0,1,-1,1,-1 };
int N, M;

void change(int y,int x,int color)
{
	board[y][x] = color;
	for (int i = 0; i < 8; i++)
	{
		int ny = y;
		int nx = x;
		while (1)
		{
			
			 ny= ny + dy[i];
			 nx= nx + dx[i];
			
			if (ny<0 || nx<0 || ny>N - 1 || nx>N - 1 || board[ny][nx] == 0)
			{
				while (!q.empty())
				{				
					q.pop();
				}
				break;
			}
			

			if (board[ny][nx] == color)
			{
				while (!q.empty())
				{
					board[q.front().first][q.front().second] = color;
					q.pop();
				}
				break;
			}

			q.push({ ny,nx });
		}

	}
}

int main()
{
	int T;
	cin >> T;
	for (int k = 0; k < T; k++)
	{
		memset(board, 0, sizeof(board));
		cin >> N >> M;
		int y, x, color;
		board[N / 2 - 1][N / 2 - 1] = 2;
		board[N / 2 - 1][N / 2] = 1;
		board[N / 2][N / 2 - 1] = 1;
		board[N / 2][N / 2] = 2;


		for (int i = 0; i < M; i++)
		{
			scanf("%d %d %d", &x, &y, &color);
			change(y - 1, x - 1, color);

		}
		int black = 0, white = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				//printf("%d ", board[i][j]);
				if (board[i][j] == 1)
				{
					black++;
				}
				else if(board[i][j]==2)
				{
					white++;
				}
			}
			//printf("\n");
		}
		printf("#%d %d %d\n", k+1, black, white);
	}



}