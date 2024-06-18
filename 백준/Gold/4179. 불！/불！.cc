#define _CRT_SECURE_NO_WARNINGS
#define P
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };

int N, M;

int ji[1000][1000];

int fire[1000][1000];
vector<string> vec;

queue<pair<int, int>> q;
queue<pair<int, int>> fq;
void bfs1()
{
	

	

	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny<0 || nx<0 || ny>N - 1 || nx> M - 1) continue;
			if (ji[ny][nx] != 0) continue;
			if (vec[ny][nx] == '#') continue;

			q.push({ ny,nx });

			ji[ny][nx] = ji[y][x] + 1;

		}


	}

}

void bfs2()
{


	while (!fq.empty())
	{
		int y = fq.front().first;
		int x = fq.front().second;
		fq.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny<0 || nx<0 || ny>N - 1 || nx> M - 1) continue;
			if (fire[ny][nx] != 0) continue;
			if (vec[ny][nx] == '#') continue;

			fq.push({ ny,nx });

			fire[ny][nx] = fire[y][x] + 1;

		}


	}

}

int main()
{
	cin >> N >> M;

	string temp;

	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		vec.push_back(temp);
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (vec[i][j] == 'J')
			{
				ji[i][j] = 1;
				q.push({ i,j });
			}

			if (vec[i][j] == 'F')
			{

				fire[i][j] = 1;
				fq.push({ i,j });
			}


		}
		
	}

	bfs1();

	
	bfs2();
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			P("%d ", ji[i][j]);
		}
		P("\n");
	}
	P("\n");
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			P("%d ", fire[i][j]);
		}
		P("\n");
	}
	int flag = 0; // 0이면 불가능
	int minn = 210000000;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{

			if (i == 0 || j == 0 || i==N-1 || j==M-1)
			{

				if ((ji[i][j] != 0) && ((ji[i][j] < fire[i][j]) || fire[i][j]==0))
				{
					flag = 1;
					minn = min(minn, ji[i][j]);
				}

			}

		}
	}

	if (flag == 0)
	{
		cout << "IMPOSSIBLE";
	}
	else
	{
		cout << minn;
	}

}