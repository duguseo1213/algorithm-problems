#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <cstring>
#include <climits>
#include <map>
#include <deque>

using namespace std;

int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0, };

int N, M;

struct camera 
{
	int y;
	int x;
	int num;
};

vector<camera> cams;



int map_[8][8];

int look[8][8];
int minn = 987654321;
void func(int dep,int s)
{
	

	if (dep == cams.size())
	{
		int cnt = 0;
		//printf("\n");
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{

				if (look[i][j] == 0 && map_[i][j]!=6)
				{
					cnt++;
				}
				//printf("%d ", look[i][j]);
			}
			//printf("\n");
		}
		minn = min(minn, cnt);
		return;
	}

	int templook[8][8] = { 0, };
	copy(&look[0][0], &look[0][0] + 64, &templook[0][0]);


	for (int i = s; i < cams.size(); i++)
	{

		if (cams[i].num == 1)
		{
			
			for (int j = 0; j < 4; j++)
			{
				look[cams[i].y][cams[i].x]++;
				int cnt = 1;
				while (1)
				{
					int ny = cams[i].y + dy[j]*cnt;
					int nx = cams[i].x + dx[j]*cnt;

					if (ny<0 || nx<0 || ny>N - 1 || nx> M - 1) break;

					if (map_[ny][nx] == 6) break;

					look[ny][nx]++;
					cnt++;
				}

				func(dep + 1, i + 1);
				copy(&templook[0][0], &templook[0][0] + 64, &look[0][0]);
			}
		}

		else if (cams[i].num == 2)
		{
			for (int k = 0; k < 4; k++)
			{
				look[cams[i].y][cams[i].x]++;
				for (int j = k; j < k + 3; j=j+2)
				{

					int cnt = 1;
					while (1)
					{
						int ny = cams[i].y + dy[j % 4] * cnt;
						int nx = cams[i].x + dx[j % 4] * cnt;

						if (ny<0 || nx<0 || ny>N - 1 || nx> M - 1) break;

						if (map_[ny][nx] == 6) break;

						look[ny][nx]++;
						cnt++;
					}


				}
				func(dep + 1, i + 1);
				copy(&templook[0][0], &templook[0][0] + 64, &look[0][0]);
			}
		}

		else if (cams[i].num == 3)
		{
			for (int k = 0; k < 4; k++)
			{
				look[cams[i].y][cams[i].x]++;
				for (int j = k; j <k+ 2; j++)
				{
					
					int cnt = 1;
					while (1)
					{
						int ny = cams[i].y + dy[j%4] * cnt;
						int nx = cams[i].x + dx[j%4] * cnt;

						if (ny<0 || nx<0 || ny>N - 1 || nx> M - 1) break;

						if (map_[ny][nx] == 6) break;

						look[ny][nx]++;
						cnt++;
					}


				}
				func(dep + 1, i + 1);
				copy(&templook[0][0], &templook[0][0] + 64, &look[0][0]);
			}
		}

		else if (cams[i].num == 4)
		{
			for (int k = 0; k < 4; k++)
			{
				look[cams[i].y][cams[i].x]++;
				for (int j = k; j < k + 3; j++)
				{

					int cnt = 1;
					while (1)
					{
						int ny = cams[i].y + dy[j % 4] * cnt;
						int nx = cams[i].x + dx[j % 4] * cnt;

						if (ny<0 || nx<0 || ny>N - 1 || nx> M - 1) break;

						if (map_[ny][nx] == 6) break;

						look[ny][nx]++;
						cnt++;
					}


				}
				func(dep + 1, i + 1);
				copy(&templook[0][0], &templook[0][0] + 64, &look[0][0]);
			}
		}

		else if (cams[i].num == 5)
		{
			
			look[cams[i].y][cams[i].x]++;
			for (int j = 0; j < 4; j++)
			{

				int cnt = 1;
				while (1)
				{
					int ny = cams[i].y + dy[j % 4] * cnt;
					int nx = cams[i].x + dx[j % 4] * cnt;

					if (ny<0 || nx<0 || ny>N - 1 || nx> M - 1) break;

					if (map_[ny][nx] == 6) break;

					look[ny][nx]++;
					cnt++;
				}
			}
			func(dep + 1, i + 1);
			copy(&templook[0][0], &templook[0][0] + 64, &look[0][0]);
		}
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

			if (map_[i][j] > 0 && map_[i][j] <= 5)
			{
				cams.push_back({ i,j,map_[i][j] });
			}
		}
	}
	
	func(0,0);
	/*
	if (minn == 987654321)
	{
		cout << 0;
	}
	else {*/
		cout << minn;
	

}