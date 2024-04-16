#define _CRT_SECURE_NO_WARNINGS
#define P 
#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int dy[3] = { -1,0,1 };
int dx[3] = { 1,1,1 };


vector<pair<int, int>> vec;
int N, M; 
   
int visit[10010][510];
char map_[10010][510];
int state = 0;
int answer = 0;
int cnt = 0;

void dfs(int y, int x)
{

	if (x == M - 1)
	{
		state = 1;
		answer++;
		return;
	}

	for (int i = 0; i < 3; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny<0 || nx<0 || ny> N - 1 || nx> M - 1) continue;
		if (map_[ny][nx] == 'x') continue;
		if (visit[ny][nx] == 1) continue;

		visit[ny][nx] = 1;
		dfs(ny, nx);
		if (state == 1) return;
		
	}



}


int main()
{
	scanf("%d %d", &N, &M);

	
	for (int i = 0; i < N; i++)
	{
		scanf("%s", map_[i]);
	}

	
	

	for (int i = 0; i < N; i++)
	{

		state = 0;
		dfs(i, 0);
		


	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			P("%c", map_[i][j]);
		}
		P("\n");
	}


	printf("%d", answer);
}