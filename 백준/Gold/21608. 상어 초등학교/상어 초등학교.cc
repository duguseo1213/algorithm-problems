#define _CRT_SECURE_NO_WARNINGS
#define P
#include <iostream>

using namespace std;

int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };

int N;

int student[500][4];

int map_[20][20];
int sum = 0;
void find_place(int num)
{
	int maxempty = -1;
	int maxfre = -1;
	int maxi = 0;
	int maxj = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int empty = 0;
			int fre = 0;

			if (map_[i][j] != 0) continue;

			for (int k = 0; k < 4; k++)
			{
				int ny = i + dy[k];
				int nx = j + dx[k];

				if (ny<0 || nx<0 || ny>N - 1 || nx>N - 1) continue;

				if (map_[ny][nx] == 0)
				{
					empty++;
					continue;
				}

				for (int l = 0; l < 4; l++)
				{
					if (map_[ny][nx] == student[num][l])
					{
						fre++;
					}
				}
							   				 
			}




			if (fre > maxfre)
			{
				maxfre = fre;
				maxempty = empty;
				maxi = i;
				maxj = j;

			}
			else if (fre == maxfre)
			{
				if (empty > maxempty)
				{
					maxempty = empty;
					maxi = i;
					maxj = j;
				}
			}



		}
	}

	P("%d %d\n", maxfre,maxempty);
	map_[maxi][maxj] = num;






}

void cal_score()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int fre = 0;
			for (int k = 0; k < 4; k++)
			{
				int ny = i + dy[k];
				int nx = j + dx[k];

				if (ny<0 || nx<0 || ny>N - 1 || nx>N - 1) continue;

				for (int l = 0; l < 4; l++)
				{
					if (map_[ny][nx] == student[map_[i][j]][l])
					{
						fre++;
					}
				}



			}
			if (fre == 0)
			{
				
			}
			else if (fre == 1)
			{
				sum += 1;
			}
			else if (fre == 2)
			{
				sum += 10;
			}
			else if (fre == 3)
			{
				sum += 100;
			}
			else if (fre == 4)
			{
				sum += 1000;
			}




		}
		
	}



}


int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N*N; i++)
	{
		int num;
		scanf("%d", &num);
		scanf("%d %d %d %d", &student[num][0], &student[num][1], &student[num][2], &student[num][3]);
		find_place(num);
	
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			P("%d ", map_[i][j]);
		}
		P("\n");
	}
	cal_score();

	printf("%d", sum);
}