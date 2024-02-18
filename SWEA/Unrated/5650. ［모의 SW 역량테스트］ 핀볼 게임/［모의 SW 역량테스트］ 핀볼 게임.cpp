#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
//#include <map>
using namespace std;
int state = 0;
struct worm {

	int y1;
	int x1;
	int y2;
	int x2;
};


int mx, my;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int N;
int map[100][100];

int maxx = 21e8;

int main()
{
	//freopen("input.txt", "r", stdin);
	int T;
	cin >> T;
	for (int q = 1; q <= T; q++)
	{
		worm hole[11] = { 0, };
		memset(map, 0, sizeof(map));
		maxx = 0;
		int dir = 0;
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				scanf("%d", &map[i][j]);
				if (map[i][j] >= 6)
				{
					if (hole[map[i][j]].x1 == 0 && hole[map[i][j]].y1 == 0)
					{
						hole[map[i][j]].y1 = i;
						hole[map[i][j]].x1 = j;
					}
					else
					{
						hole[map[i][j]].y2 = i;
						hole[map[i][j]].x2 = j;
					}
				}

			}
		}
		/*
		for (int i = 6; i <= 10; i++)
		{
			printf("%d %d %d %d\n", hole[i].y1 ,
			hole[i].x1 , hole[i].y2,
				hole[i].x2 );
		}
		*/
		int sy, sx;
		int y, x;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{

				if (map[i][j] == 0)
				{


					sy = i;
					sx = j;




					for (int k = 0; k < 4; k++)
					{
						int cnt = 0;
						y = i;
						x = j;
						dir = k;
						//cout << "시작" << endl;
						//cout << y << " " << x << endl;

						int ny = i;
						int nx = j;
						state = 0;
						while (1)
						{


							if (ny<0 || nx<0 || ny>N - 1 || nx>N - 1 || map[ny][nx] == 5) //바깥벽 또는 5
							{
								cnt++;
								dir = (dir + 2) % 4;
								ny = ny + dy[dir];
								nx = nx + dx[dir];
								state = 0;
							}

							else if (map[ny][nx] == 0) // 다음 도착지 0
							{
								ny = ny + dy[dir];
								nx = nx + dx[dir];
								state = 0;
							}

							else if (map[ny][nx] > 0 && map[ny][nx] < 5) //다음도착지 벽
							{
								state = 0;
								cnt++;
								if (dir == 0)
								{
									if (map[ny][nx] == 2 || map[ny][nx] == 3)
									{
										dir = (dir + 2) % 4;
										ny = ny + dy[dir];
										nx = nx + dx[dir];
									}
									else if (map[ny][nx] == 1)
									{
										dir = 1;
										ny = ny + dy[dir];
										nx = nx + dx[dir];
									}
									else
									{
										dir = 3;
										ny = ny + dy[dir];
										nx = nx + dx[dir];
									}

								}
								else if (dir == 1)
								{

									if (map[ny][nx] == 1 || map[ny][nx] == 2)
									{
										dir = (dir + 2) % 4;
										ny = ny + dy[dir];
										nx = nx + dx[dir];
									}
									else if (map[ny][nx] == 3)
									{
										dir = 0;
										ny = ny + dy[dir];
										nx = nx + dx[dir];
									}
									else
									{
										dir = 2;
										ny = ny + dy[dir];
										nx = nx + dx[dir];
									}


								}
								else if (dir == 2)
								{
									if (map[ny][nx] == 1 || map[ny][nx] == 4)
									{
										dir = (dir + 2) % 4;
										ny = ny + dy[dir];
										nx = nx + dx[dir];
									}
									else if (map[ny][nx] == 2)
									{
										dir = 1;
										ny = ny + dy[dir];
										nx = nx + dx[dir];
									}
									else
									{
										dir = 3;
										ny = ny + dy[dir];
										nx = nx + dx[dir];
									}
								}
								else //dir 3
								{
									if (map[ny][nx] == 3 || map[ny][nx] == 4)
									{
										dir = (dir + 2) % 4;
										ny = ny + dy[dir];
										nx = nx + dx[dir];
									}
									else if (map[ny][nx] == 1)
									{
										dir = 2;
										ny = ny + dy[dir];
										nx = nx + dx[dir];
									}
									else
									{
										dir = 0;
										ny = ny + dy[dir];
										nx = nx + dx[dir];
									}
								}


							}

							else if (map[ny][nx] >= 6 && map[ny][nx] <= 10) //웜홀
							{
								if (state == 0)
								{
									worm temp = hole[map[ny][nx]];

									if (temp.x1 == nx && temp.y1 == ny)
									{
										nx = temp.x2;
										ny = temp.y2;
									}
									else
									{
										nx = temp.x1;
										ny = temp.y1;
									}
									state = 1;
								}
								else
								{
									ny = ny + dy[dir];
									nx = nx + dx[dir];
									state = 0;
								}
							}
							//cout << ny << " " << nx << endl;


							if ((ny >= 0 && nx >= 0 && ny <= N - 1 && nx <= N - 1) && map[ny][nx] == -1 || (ny == sy && nx == sx)) //자기자신과 블랙홀
							{
								my = sy;
								mx = sx;
								maxx = max(maxx, cnt);
								break;
							}






						}
					}

				}
			}
		}
		printf("#%d %d\n", q, maxx);
	}
}