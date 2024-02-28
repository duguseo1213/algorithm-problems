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
#include <cmath>

using namespace std;

int dy[5] = { 0,-1,0,1,0 };
int dx[5] = { 0,0,1,0,-1 };

int M, A;

int bamap[10][10][8];

vector<int> a;
vector<int> b; 

int main()
{
	//freopen("sample_input.txt", "r", stdin);
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++)
	{
		a.clear();
		b.clear();
		memset(bamap, 0, sizeof(bamap));



		int temp;

		cin >> M >> A;

		for (int i = 0; i < M; i++)
		{
			scanf("%d", &temp);
			a.push_back(temp);
		}
		for (int i = 0; i < M; i++)
		{
			scanf("%d", &temp);
			b.push_back(temp);
		}

		for (int i = 0; i < A; i++)
		{
			int y, x;
			int range;
			int power;

			scanf("%d %d %d %d", &x, &y, &range, &power);
			y--;
			x--;
			for (int j = 0; j < 10; j++)
			{
				for (int k = 0; k < 10; k++)
				{
					if (abs(y - j) + abs(x - k) <= range)
					{
						bamap[j][k][i] = power;
					}
				}
			}
		}


		int y1 = 0;
		int x1 = 0;

		int y2 = 9;
		int x2 = 9;

		int sum = 0;
		for (int i = 0; i <= M; i++)
		{
			int maxx = 0;
			int maxa = 0;
			int maxb = 0;
			int sela = -1;
			int selb = -1;


			//A가 먼저 선택

			for (int j = 0; j < A; j++)
			{
				if (maxa < bamap[y1][x1][j])
				{
					maxa = bamap[y1][x1][j];
					sela = j;
				}
			}

			for (int j = 0; j < A; j++)
			{
				if (maxb < bamap[y2][x2][j] && j != sela)
				{
					maxb = bamap[y2][x2][j];
					selb = j;
				}
			}

			maxx = max(maxx, maxa + maxb);


			//B가 먼저 선택

			maxa = 0;
			maxb = 0;
			sela = -1;
			selb = -1;

			for (int j = 0; j < A; j++)
			{
				if (maxb < bamap[y2][x2][j])
				{
					maxb = bamap[y2][x2][j];
					selb = j;
				}
			}

			for (int j = 0; j < A; j++)
			{
				if (maxa < bamap[y1][x1][j] && j != selb)
				{
					maxa = bamap[y1][x1][j];
					sela = j;
				}
			}



			maxx = max(maxx, maxa + maxb);

			//printf("%d %d %d\n",y1,x1, maxx);

			sum += maxx;


			if (i == M) break;

			y1 = y1 + dy[a[i]];
			x1 = x1 + dx[a[i]];

			y2 = y2 + dy[b[i]];
			x2 = x2 + dx[b[i]];


		}
		//cout << sum;
		printf("#%d %d\n", t, sum);
	}
}