#define _CRT_SECURE_NO_WARNINGS
#define P 

#include <iostream>
#include <vector>
using namespace std;

int N, M, K;

int dy[8] = { -1,-1,0,1,1,1,0,-1 };
int dx[8] = { 0,1,1,1,0,-1,-1,-1 };

struct NODE {
	int m;
	int d;
	int dir;
};

vector<NODE> map_[50][50]; //합쳐지기전

vector<NODE> arr[50][50]; //합쳐지고 나서



int main()
{
	scanf("%d %d %d", &N, &M, &K);

	int y, x, m, d, dir;

	for (int i = 0; i < M; i++)
	{
		scanf("%d %d %d %d %d", &y, &x, &m, &d, &dir);

		y = y - 1;
		x = x - 1;

		arr[y][x].push_back({ m,d,dir });

	}
	int msum;
	for (int t = 0; t < K; t++)
	{

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				for (int k = 0; k < arr[i][j].size(); k++)
				{
					NODE now = arr[i][j][k];
					int nx = j + dx[now.dir] * now.d;
					int ny = i + dy[now.dir] * now.d;

					if (nx < 0)
					{
						nx = nx % N;
						
						if (nx != 0)
						{
							nx=nx + N;
						}


					}

					if (nx > N - 1)
					{
						nx = nx % N;

					}

					if (ny < 0)
					{
						ny = ny % N;
						if (ny != 0)
						{
							ny=ny + N;
						}
					}

					if (ny > N - 1)
					{
						ny = ny % N;

					}

					map_[ny][nx].push_back(now);



				}

				arr[i][j].clear();

			}
		}
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				P("%d ", map_[i][j].size());
			}
			P("%\n");
		}
		P("%\n");

		msum = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (map_[i][j].size() >= 2)
				{
					NODE temp;
					temp.m = 0;
					temp.d = 0;
					int state = 0;//0,2,4,6

					for (int k = 0; k < map_[i][j].size(); k++)
					{
						temp.m += map_[i][j][k].m;

						temp.d += map_[i][j][k].d;

						if (map_[i][j][k].dir % 2 != map_[i][j][0].dir % 2) state = 1;
					}



					temp.m = temp.m / 5;
					temp.d = temp.d / map_[i][j].size();

					msum += temp.m * 4;

					if (temp.m > 0)
					{
						for (int k = 0; k < 4; k++)
						{
							temp.dir = k * 2 + state;
							arr[i][j].push_back(temp);
						}
					}

				}

				if (map_[i][j].size() == 1)
				{
					arr[i][j].push_back(map_[i][j][0]);

					msum += map_[i][j][0].m;

				}

				map_[i][j].clear();

			}
		}

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				P("%d ", arr[i][j].size());
			}
			P("%\n");
		}
		P("%\n");
		
		P("%\n");
	}
	printf("%d", msum);
}
