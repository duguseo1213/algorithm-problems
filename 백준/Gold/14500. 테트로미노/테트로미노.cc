#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };

int gun1[3] = {1,1,0};
int gun2[3] = { 1,1,2 };

int zig1[3] = { 1,0,1 };
int zig2[3] = { 1,2,1 };

int f1[3] = {0,1,2};

int map_[500][500];

int N, M;

int maxx = 0;

void square(int y,int x)
{
	int sum = 0;
	
	if (y + 1 < N  && x + 1 < M )
	{
		sum = map_[y][x] + map_[y + 1][x] + map_[y][x + 1] + map_[y + 1][x + 1];
		maxx = max(maxx, sum);
	}

}

void line(int y,int x)
{
	if (y + 3 < N && y + 2 < N && y + 1 < N)
	{
		maxx = max(maxx, map_[y][x] + map_[y + 1][x] + map_[y + 2][x] + map_[y + 3][x]);
	}

	if (x + 3 < M && x + 2 < M && x + 1 < M)
	{
		maxx = max(maxx, map_[y][x] + map_[y][x+1] + map_[y][x+2] + map_[y][x+3]);
	}

}

void fy(int y,int x)
{
	int sum = map_[y][x];

	for (int i = 0; i < 4; i++)
	{
		int temp = sum;
		int ny = y;
		int nx = x;
		for (int j = 0; j < 3; j++)
		{

			ny = y + dy[(f1[j] + i) % 4];
			nx = x + dx[(f1[j] + i) % 4];

			if (ny<0 || nx<0 || ny>N - 1 || nx>M - 1) break;

			temp = temp + map_[ny][nx];

		}
		maxx = max(temp, maxx);

	}
}

void zigzag(int y, int x)
{
	int sum = map_[y][x];

	for (int i = 0; i < 4; i++)
	{
		int temp = sum;
		int ny = y;
		int nx = x;
		for (int j = 0; j < 3; j++)
		{

			ny = ny + dy[(zig1[j] + i) % 4];
			nx = nx + dx[(zig1[j] + i) % 4];

			if (ny<0 || nx<0 || ny>N - 1 || nx>M - 1) break;

			temp = temp + map_[ny][nx];

		}
		maxx = max(temp, maxx);

	}

	for (int i = 0; i < 4; i++)
	{
		int temp = sum;
		int ny = y;
		int nx = x;
		for (int j = 0; j < 3; j++)
		{

			ny = ny + dy[(zig2[j] + i) % 4];
			nx = nx + dx[(zig2[j] + i) % 4];

			if (ny<0 || nx<0 || ny>N - 1 || nx>M - 1) break;

			temp = temp + map_[ny][nx];

		}
		maxx = max(temp, maxx);

	}
}

void gun(int y,int x)
{
	int sum = map_[y][x];

	for (int i = 0; i < 4; i++)
	{
		int temp = sum;
		int ny = y;
		int nx = x;
		for (int j = 0; j < 3; j++)
		{
			
			ny = ny + dy[(gun1[j] + i) % 4];
			nx = nx + dx[(gun1[j] + i) % 4];

			if (ny<0 || nx<0 || ny>N - 1 || nx>M - 1) break;

			temp = temp + map_[ny][nx];
			
		}
		maxx = max(temp, maxx);
		
	}

	for (int i = 0; i < 4; i++)
	{
		int temp = sum;
		int ny = y;
		int nx = x;
		for (int j = 0; j < 3; j++)
		{

			ny = ny + dy[(gun2[j] + i) % 4];
			nx = nx + dx[(gun2[j] + i) % 4];

			if (ny<0 || nx<0 || ny>N - 1 || nx>M - 1) break;

			temp = temp + map_[ny][nx];
			
		}
		maxx = max(temp, maxx);
		
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
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			gun(i, j);
			fy(i, j);
			line(i, j);
			square(i, j);
			zigzag(i, j);
		}
	}

	cout << maxx;
}
