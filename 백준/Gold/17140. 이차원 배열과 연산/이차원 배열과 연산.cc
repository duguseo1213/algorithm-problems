#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <cstring>
#include <queue>
using namespace std;

int dat[101];

int map_[100][100];

struct cmp {
	bool operator()(pair<int, int> a, pair<int, int> b)
	{
		if (a.first == b.first)
		{
			return a.second > b.second;
		}
		
		return a.first > b.first;


	}
};

priority_queue <pair<int, int>, vector<pair<int, int>>, cmp> pq;

int row;
int col;

void R()
{
	int maxcol = 0;

	for (int i = 0; i < row; i++)
	{
		memset(dat, 0, sizeof(dat));
		for (int j = 0; j < col; j++)
		{
			dat[map_[i][j]]++;
		}

		for (int j = 0; j < 100; j++)
		{
			map_[i][j] = 0;
		}

		for (int j = 1; j <= 100; j++)
		{
			pair<int, int> temp;
			if (dat[j] > 0)
			{
				temp.first = dat[j];
				temp.second = j;

				pq.push(temp);
			}

		}
		
		int rocount = pq.size()*2;
		
		rocount=min(rocount, 100);
		maxcol =max(maxcol, rocount);
		int index = 0;
		while (!pq.empty())
		{
			map_[i][index]=pq.top().second;
			index++;
			map_[i][index] = pq.top().first;
			index++;
			pq.pop();
			if (index == 100) break;
		}

		while (!pq.empty())
		{
			pq.pop();
		}
	}
	col = maxcol;
}

void C()
{
	int maxrow = 0;
	for (int i = 0; i < col; i++)
	{
		memset(dat, 0, sizeof(dat));
		for (int j = 0; j < row; j++)
		{
			dat[map_[j][i]]++;
			
		}
		for (int j = 0; j < 100; j++)
		{
			map_[j][i] = 0;
		}

		for (int j = 1; j <= 100; j++)
		{
			pair<int, int> temp;
			if (dat[j] > 0)
			{
				temp.first = dat[j];
				temp.second = j;

				pq.push(temp);
			}

		}

		int rocount = pq.size() * 2;
		
		rocount=min(rocount, 100);
		maxrow = max(maxrow, rocount);
		int index = 0;
		while (!pq.empty())
		{
			map_[index][i] = pq.top().second;
			index++;
			map_[index][i] = pq.top().first;
			index++;
			pq.pop();
			if (index == 100) break;
		}

		while (!pq.empty())
		{
			pq.pop();
		}

	}
	row = maxrow;
}



int main()
{
	int r, c, k;

	cin >> r >> c >> k;
	r--;
	c--;
	row = 3;
	col = 3;


	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> map_[i][j];
		}
	}
	int cnt = 0;
	while (1)
	{
		if (map_[r][c] == k) break;
		if (cnt == 100)
		{
			cnt = -1;
			break;
		}
		
		if (row >= col)
		{
			R();
		}
		else
		{
			C();
		}
		
		cnt++;

	}
	
	
	cout << cnt;
}