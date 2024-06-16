#define _CRT_SECURE_NO_WARNINGS
#define P printf
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

pair<int, int> parent[10000];// 왼쪽 부모 번호, 오른쪽 order 0 d,1 s,2 l ,3 r
queue<int> q;
int start;
int target;
char answer[4] = { 'D','S','L','R' };
vector<int> vec;
void bfs(int v)
{
	q.push(v);

	while (!q.empty())
	{

		int now = q.front();

		if (now == target)
		{
			break;
		}

		q.pop();


		int temp;

		temp = now * 2%10000;
		if (parent[temp].first == -1)
		{
			q.push(temp);
			parent[temp] = { now,0 };
		}

		temp = now - 1;
		if (temp < 0)
		{
			temp = 9999;
		}

		if (parent[temp].first == -1)
		{
			q.push(temp);
			parent[temp] = { now,1 };
		}

		temp = (now / 1000 + now * 10)%10000;
		if (parent[temp].first == -1)
		{
			q.push(temp);
			parent[temp] = { now,2 };
		}

		temp = (now % 10)*1000+now/10;
		if (parent[temp].first == -1)
		{
			q.push(temp);
			parent[temp] = { now,3 };
		}

	}

}

int main() 
{
	int T;

	scanf("%d", &T);

	for (int i = 0; i < T; i++)
	{
		memset(parent, 0, sizeof(parent));
		vec.clear();
		for (int i = 0; i < 10000; i++)
		{
			parent[i].first = -1;
		}
		while (!q.empty())
		{
			q.pop();
		}
		scanf("%d %d", &start, &target);
		parent[start].first = -2;
		bfs(start);
		while (1)
		{
			if (target == start) break;

			vec.push_back(parent[target].second);
			//printf("%c", answer[]);
			target = parent[target].first;
		}

		for (int i = vec.size()-1; i >=0 ; i--)
		{
			printf("%c", answer[vec[i]]);
		}

		printf("\n");
	}

}