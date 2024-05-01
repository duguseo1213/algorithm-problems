#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

int dy[8] = { -1,-1,-1,0,1,1,1,0 };
int dx[8] = { -1,0,1,1,1,0,-1,-1 };

vector<string> arr;


int N;

queue<pair<int, int>> q;

void bfs(int i,int j)
{
	q.push({ i,j });
	arr[i][j] = '0';

	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;

		q.pop();
		int state = 0;
		for (int k = 0; k < 8; k++)
		{
			int ny = y + dy[k];
			int nx = x + dx[k];

			if (ny<0 || nx <0 || ny> N - 1 || nx> N - 1) continue;

			if (arr[ny][nx] == '*' )
			{
				state = 1;
				break;
			}			
			
		}

		if (state == 0)
		{

			for (int k = 0; k < 8; k++)
			{
				int ny = y + dy[k];
				int nx = x + dx[k];

				if (ny<0 || nx <0 || ny> N - 1 || nx> N - 1) continue;

				if (arr[ny][nx] != '0')
				{

					q.push({ ny,nx });
					arr[ny][nx] ='0';
				}
			}
		}


	}
}

int main()
{

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++)
	{
		string temp;
		arr.clear();

		int cnt = 0;
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			cin >> temp;
			arr.push_back(temp);
		}

		

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{

				int state = 0;


				if (arr[i][j] == '0' || arr[i][j] == '*')
				{
					continue;
				}

				for (int k = 0; k < 8; k++)
				{
					int ny = i + dy[k];
					int nx = j + dx[k];

					if (ny<0 || nx <0 || ny> N - 1 || nx> N - 1) continue;

					if (arr[ny][nx] == '*')
					{
						state = 1;
						break;
					}

				}

				if (state == 0)
				{
					//printf("%d %d\n", i, j);
					bfs(i, j);
					cnt++;

				}



			}
		}

		for (int l = 0; l < N; l++)
		{
			for (int m = 0; m < N; m++)
			{

				if (arr[l][m] == '.')
				{
					cnt++;
				}
			}

		}
		printf("#%d %d\n", t, cnt);
	}
}
