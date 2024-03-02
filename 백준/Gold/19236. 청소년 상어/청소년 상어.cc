#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <queue>
using namespace std;

int dy[8] = { -1,-1,0,1,1,1,0,-1 };
int dx[8] = { 0,-1,-1,-1,0,1,1,1 };


struct fish {
	int num;
	int dir;
	int alive; //0 이 산거

};

int fishalive[17];

fish map_[4][4];



int maxx;

void func(int sy,int sx,int sdir,int sum)
{
	//printf("\n");
	//printf("%d %d %d %d\n", sy, sx, sdir, sum);
	maxx = max(sum, maxx);
	fish temp[4][4];
	



	//물고기 이동
	for (int i = 1; i <= 16; i++)
	{
		if (fishalive[i] == 1) continue;

		else
		{
			int y, x;
			for (int j = 0; j < 4; j++)
			{
				for (int k = 0; k < 4; k++)
				{
					if (map_[j][k].num == i)
					{
						y = j;
						x = k;
					}
				}
			}
			int ny;
			int nx;
			int state = 0;
			for (int j = 0; j < 8; j++)
			{
				ny = y + dy[(map_[y][x].dir + j) % 8];
				nx = x + dx[(map_[y][x].dir + j) % 8];

				if (ny < 0 || nx < 0 || ny>3 || nx>3) continue;

				if (ny == sy && nx == sx) continue;

				state = 1;
				map_[y][x].dir = (map_[y][x].dir + j) % 8;
				break;

			}

			if (state == 1)
			{
				

				fish temp;
				temp = map_[y][x];
				map_[y][x] = map_[ny][nx];
				map_[ny][nx] = temp;
				
			}
			else
			{
				continue;
			}

		}
	}

	for (int j = 0; j < 4; j++)
	{
		for (int k = 0; k < 4; k++)
		{
			temp[j][k] = map_[j][k];
		}

	}
	//상어 이동
	/*
	printf("\n");
	for (int j = 0; j < 4; j++)
	{
		for (int k = 0; k < 4; k++)
		{
			if (j == sy && k == sx)
			{
				printf("@ ");
			}
			else
			{
				printf("%d ", map_[j][k].num);
			}
		}
		printf("\n");
	}*/

	while (1)
	{
		sy = sy + dy[sdir];
		sx = sx + dx[sdir];

		if (sy < 0 || sx < 0 || sy>3 || sx>3) break;

		if (map_[sy][sx].alive == 1) continue;

		map_[sy][sx].alive = 1;
		fishalive[map_[sy][sx].num] = 1;
		func(sy, sx, map_[sy][sx].dir, sum + map_[sy][sx].num);

		for (int j = 0; j < 4; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				map_[j][k] = temp[j][k];
			}

		}

		fishalive[map_[sy][sx].num] = 0;
		map_[sy][sx].alive = 0;

	}




	
	

	
}


int main()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			scanf("%d %d", &map_[i][j].num, &map_[i][j].dir);
			map_[i][j].dir--;
		}
	}

	fishalive[map_[0][0].num] = 1;
	map_[0][0].alive = 1;
	func(0,0, map_[0][0].dir, map_[0][0].num);


	cout << maxx;
}