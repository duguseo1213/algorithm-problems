#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <queue>
using namespace std;
int map_[10][10];

int score;
void down(int t,int y, int x)
{
	if (t == 1)
	{
		while (1)
		{
			if (y >= 9 || map_[y + 1][x] == 1) break;
			y++;


		}
		map_[y][x] = 1;

	}

	else if (t == 2)
	{
		int tempy = y;

		while (1)
		{
			if (y >= 9 || map_[y + 1][x] == 1) break;
			y++;
		}
		while (1)
		{
			if (tempy >= 9 || map_[tempy + 1][x + 1] == 1) break;
			tempy++;
		}

		y = min(y, tempy);

		map_[y][x] = 1;
		map_[y][x + 1] = 1;

	}

	else if (t == 3)
	{
		while (1)
		{
			if (y >= 9 || map_[y + 1][x] == 1) break;
			y++;


		}
		map_[y][x] = 1;
		map_[y - 1][x] = 1;
	}
}

void right(int t, int y, int x)
{
	if (t == 1)
	{
		while (1)
		{
			if (x >= 9 || map_[y][x+1] == 1) break;
			x++;


		}
		map_[y][x] = 1;

	}

	else if (t == 3)
	{
		int tempx = x;

		while (1)
		{
			if (x >= 9 || map_[y][x+1] == 1) break;
			x++;
		}
		while (1)
		{
			if (tempx >= 9 || map_[y+1][tempx + 1] == 1) break;
			tempx++;
		}

		x = min(x, tempx);

		map_[y+1][x] = 1;
		map_[y][x] = 1;

	}

	else if (t == 2)
	{
		while (1)
		{
			if (x >= 9 || map_[y][x+1] == 1) break;
			x++;


		}
		map_[y][x] = 1;
		map_[y][x-1] = 1;
	}
}


int main()
{
	int N;
	int y, x, t;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		scanf("%d %d %d", &t, &y, &x);

		//초록

		down(t, y, x);
		
		//꽉차있는지 체크
		int onetwo = 0;
		int line = 0;
		for (int j = 6; j < 10; j++)
		{
			int state = 1;
			for (int k = 0; k < 4; k++)
			{
				if (map_[j][k] == 0)
				{
					state = 0;
					break;
				}
			}
			if (state == 1)
			{
				onetwo++;
				line = j;
			}
		}
		//cout << onetwo << endl << line << endl;

		int temparray[4][4] = { 0, };
		if (onetwo > 0)
		{
			for (int j = line - onetwo + 1 - 4; j < line - onetwo + 1; j++)
			{
				for (int k = 0; k < 4; k++)
				{
					temparray[j - (line - onetwo + 1 - 4)][k] = map_[j][k];
				}
			}

			for (int j = line - 4+1; j < line+1; j++)
			{
				for (int k = 0; k < 4; k++)
				{
					map_[j][k]=temparray[j-(line - 4 + 1)][k];
				}
			}
			/*
			printf("\n");
			for (int j = 0; j < 4; j++)
			{
				for (int k = 0; k < 4; k++)
				{
					printf("%d ", temparray[j][k]);
				}
				printf("\n");
			}*/
			score += onetwo;
		}
		onetwo = 0;

		for (int j = 4; j < 6; j++)
		{
			int state = 0;
			for (int k = 0; k < 4; k++)
			{
				if (map_[j][k] == 1)
				{
					state = 1;
					break;
				}
			}
			if (state == 1)
			{
				onetwo++;
			}
		}

		if (onetwo == 0)
		{

		}
		else if (onetwo >= 1)
		{
			for (int j = 9-onetwo; j >= 4-onetwo; j--)
			{
				for (int k = 0; k < 4; k++)
				{
					map_[j + onetwo][k] = map_[j][k];
				}
			}
		}

		//파랑
		
		right(t, y, x);

		onetwo = 0;
		line = 0;
		for (int j = 6; j < 10; j++)
		{
			int state = 1;
			for (int k = 0; k < 4; k++)
			{
				if (map_[k][j] == 0)
				{
					state = 0;
					break;
				}
			}
			if (state == 1)
			{
				onetwo++;
				line = j;
			}
		}
		
		
		if (onetwo > 0)
		{
			for (int j = line - onetwo + 1 - 4; j < line - onetwo + 1; j++)
			{
				for (int k = 0; k < 4; k++)
				{
					temparray[k][j - (line - onetwo + 1 - 4)] = map_[k][j];
				}
			}

			for (int j = line - 4 + 1; j < line + 1; j++)
			{
				for (int k = 0; k < 4; k++)
				{
					map_[k][j] = temparray[k][j - (line - 4 + 1)];
				}
			}
			/*
			printf("\n");
			for (int j = 0; j < 4; j++)
			{
				for (int k = 0; k < 4; k++)
				{
					printf("%d ", temparray[j][k]);
				}
				printf("\n");
			}*/
			score += onetwo;
		}
		onetwo = 0;

		for (int j = 4; j < 6; j++)
		{
			int state = 0;
			for (int k = 0; k < 4; k++)
			{
				if (map_[k][j] == 1)
				{
					state = 1;
					break;
				}
			}
			if (state == 1)
			{
				onetwo++;
			}
		}

		if (onetwo == 0)
		{

		}
		else if (onetwo >= 1)
		{
			for (int j = 9 - onetwo; j >= 4 - onetwo; j--)
			{
				for (int k = 0; k < 4; k++)
				{
					map_[k][j + onetwo] = map_[k][j];
				}
			}
		}


		


		

	}
	int answer = 0;
	for (int j = 0; j < 10; j++)
	{
		for (int k = 0; k < 10; k++)
		{
			if (map_[j][k] == 1) answer++;
		}
		
	}
	cout << score << endl << answer;
}