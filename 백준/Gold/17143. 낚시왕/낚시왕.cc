#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <cstring>
#include <queue>
using namespace std;

int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,1,-1};

struct shark {
	int y;
	int x;
	int s; //속력
	int d;
	int size;


};

vector<shark> sh;

int map_[100][100];
int N, M;
int tempmap[100][100];
int main()
{
	//freopen("sample_input.txt", "r", stdin);
	int num;
	cin >> N >> M >> num;
	shark temp;
	for (int i = 0; i < num; i++)
	{
		scanf("%d %d %d %d %d", &temp.y, &temp.x, &temp.s, &temp.d, &temp.size);
		temp.d--;
		temp.y--;
		temp.x--;
		sh.push_back(temp);
		
		map_[temp.y][temp.x] = temp.size;
	}

	

	int man = 0;
	int sum = 0;
	while (1)
	{
		memset(tempmap, 0, sizeof(tempmap));
		for (int i = 0; i < N; i++)
		{
			if (map_[i][man] != 0)
			{
				sum += map_[i][man];
				map_[i][man] = 0;
				break;
			}
		}
		if (man == M - 1)
		{
			break;
		}

		
		for (int i = 0; i < sh.size(); i++)
		{

			if (map_[sh[i].y][sh[i].x] != sh[i].size || sh[i].size == 0)
			{
				sh[i].size = 0;
				continue;
			}
			map_[sh[i].y][sh[i].x] = 0;

			if (sh[i].d == 2)
			{
				sh[i].x += sh[i].s;

				if (sh[i].x / (M - 1) % 2 == 0)
				{
					sh[i].x = sh[i].x % (M - 1);

				}
				else
				{
					sh[i].x = (M - 1) - sh[i].x % (M - 1);
					sh[i].d = sh[i].d + 1;
				}

			}
			else if (sh[i].d == 3)
			{
				sh[i].x -= sh[i].s;

				if (sh[i].x / (M - 1) % 2 == 0)
				{

					if (sh[i].x < 0)
					{
						sh[i].d = sh[i].d - 1;
					}
					sh[i].x = abs(sh[i].x % (M - 1));

					
				}
				else
				{
					sh[i].x = (M - 1) - abs(sh[i].x % (M - 1));
				}


			}
			else if (sh[i].d == 0)
			{
				sh[i].y -= sh[i].s;

				if (sh[i].y / (N - 1) % 2 == 0)
				{
					
					if (sh[i].y < 0)
					{
						sh[i].d = sh[i].d + 1;
					}
					
					sh[i].y = abs(sh[i].y % (N - 1));
					
				}
				else
				{
					sh[i].y = (N - 1) - abs(sh[i].y % (N - 1));
				}


			}
			else if (sh[i].d == 1)
			{
				sh[i].y += sh[i].s;

				if (sh[i].y / (N - 1) % 2 == 0)
				{
					sh[i].y = sh[i].y % (N - 1);

				}
				else
				{
					sh[i].y = (N - 1) - sh[i].y % (N - 1);
					sh[i].d = sh[i].d - 1;
				}


			}




			if (tempmap[sh[i].y][sh[i].x] < sh[i].size)
			{
				tempmap[sh[i].y][sh[i].x] = sh[i].size;
			}
			else
			{
				sh[i].size = 0;
			}


		}
		
		//printf("\n");
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				map_[i][j] = tempmap[i][j];
				//printf("%d ", map_[i][j]);
			}
			//printf("\n");
		}
		man++;
		
	}

	cout << sum;

}