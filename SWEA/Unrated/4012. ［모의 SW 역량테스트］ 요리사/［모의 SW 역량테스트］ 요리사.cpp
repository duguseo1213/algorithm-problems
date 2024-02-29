#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;



int N;

int map_[16][16];


int visit[16];

vector<int> a;
vector<int> b;

int minn = 987654321;
int visit2[8];

int sum1;
int sum2;

void makea(int dep,int s)
{
	if (dep == 2)
	{
		int temp1 = -1;
		int temp2 = -1;

		for (int i = 0; i < N / 2; i++)
		{
			if (temp1 == -1 && visit2[i] == 1)
			{
				temp1 = a[i];
			}
			else if (visit2[i] == 1)
			{
				temp2 = a[i];
			}
			
			

		}
		sum1 += map_[temp2][temp1];
		sum1 += map_[temp1][temp2];
		
		return;
	}

	for (int i = s; i < N / 2; i++)
	{
		
		if (visit2[i] == 0)
		{
			visit2[i] = 1;
			makea(dep + 1,i+1);
			visit2[i] = 0;
		}
	}

}

void makeb(int dep, int s)
{
	if (dep == 2)
	{
		int temp1 = -1;
		int temp2 = -1;

		for (int i = 0; i < N / 2; i++)
		{
			if (temp1 == -1 && visit2[i] == 1)
			{
				temp1 = b[i];
			}
			else if (visit2[i] == 1)
			{
				temp2 = b[i];
			}

			

		}
		sum2 += map_[temp2][temp1];
		sum2 += map_[temp1][temp2];

		return;
	}
	for (int i = s; i < N / 2; i++)
	{

		if (visit2[i] == 0)
		{
			visit2[i] = 1;
			makeb(dep + 1, i + 1);
			visit2[i] = 0;
		}
	}

}


void func(int dep,int s)
{
	if (dep == N/2)
	{
		a.clear();
		b.clear();
		sum1 = 0;
		sum2 = 0;
		for (int i = 0; i < N; i++)
		{
			//printf("%d ", visit[i]);
			if (visit[i] == 0)
			{
				a.push_back(i);
			}
			else
			{
				b.push_back(i);
			}
		}
		makea(0,0);
		makeb(0,0);
		//printf("%d %d\n", sum1, sum2);

		minn = min(minn, abs(sum1 - sum2));
		return;

	}

	for (int i = s; i < N; i++)
	{
		if (visit[i] == 0)
		{
			visit[i] = 1;
			func(dep + 1,i+1);
			visit[i] = 0;
		}
	}


}

int main()
{
	//freopen("sample_input.txt", "r", stdin);
	
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++)
	{

		minn = 987654321;
		cin >> N;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				scanf("%d", &map_[i][j]);
			}
		}

		func(0,0);

		printf("#%d %d\n",t, minn);
	}
}