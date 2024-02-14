#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#define INF 987654321

using namespace std;

vector<pair<int, int>> pro;
queue<pair<int, int>> q;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0, };
int procount;

int N;
int map[12][12];


int minn = 21e8;
int maxx = 0;

void func(int dep,int processor,int s)
{
	if (pro.size() - dep + processor < maxx)
	{
		return;
	}

	if (processor >= maxx) 
	{	
		
		if(processor>maxx) minn= 21e8; //최대 개수보다 많을경우
		maxx = processor;
		int cnt = 0;
		//printf("\n");
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				//printf("%d ", map[i][j]);

				if (map[i][j] == 1) cnt++;
			}
			//printf("\n");
		}
		cnt = cnt - procount;
		minn = min(minn, cnt);
	}

	int temp1[12][12] = { 0, };
	copy(&map[0][0], &map[0][0] + 144, &temp1[0][0]);

	for (int i = s; i < pro.size(); i++)
	{

		int y = pro[i].first;
		int x = pro[i].second;

		for (int j = 0; j < 4; j++)
		{
			int temp = 1;
			while (1)
			{
				int ny = y + dy[j] * temp;
				int nx = x + dx[j] * temp;
				q.push({ ny,nx });
				if (map[ny][nx] == 1)
				{
					while (!q.empty())
					{
						q.pop();
					}
					break;
				}
				else if (ny == 0 || nx == 0 || ny == N - 1 || nx == N - 1) 
				{
					
					while (!q.empty())
					{
						map[q.front().first][q.front().second]=1;
						q.pop();
					}

					func(dep + 1, processor + 1, i + 1);
					copy(&temp1[0][0], &temp1[0][0] + 144, &map[0][0]);

					break;
				}

				
				temp++;
			}
		}

		func(dep + 1, processor, i + 1);
		//copy(&temp1[0][0], &temp1[0][0] + 144, &map[0][0]);


	}

}



int main()
{
	int T;
	cin >> T;

	for (int k = 1; k <= T; k++)
	{
		cin >> N;
		minn = 21e8;
		maxx = 0;
		procount = 0;
		pro.clear();
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				scanf("%d", &map[i][j]);

				if (map[i][j] == 1) procount++;

				if (i == 0 || j == 0 || i == N - 1 || j == N - 1) continue;

				if (map[i][j] == 1)
				{
					pro.push_back({ i,j });
				}
			}
		}
		
		func(0, 0, 0);
		printf("#%d %d\n", k, minn);

	}



}



