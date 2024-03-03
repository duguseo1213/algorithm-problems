#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <queue>
#include <cstring>
using namespace std;

int arr[100001];

struct edge 
{
	int y;
	int x;
	int cost;
};

int find(int tar)
{
	if (tar == arr[tar])
	{
		return tar;
	}

	int root = find(arr[tar]);

	arr[tar] = root;

	return root;


}

int setunion(int a,int b)
{
	int t1 = find(a);
	int t2 = find(b);

	if (t1 == t2) return 0;

	arr[t2] = t1;
	return 1;
}

bool cmp(edge a,edge b)
{
	return a.cost < b.cost;
}
vector<edge> e;

int N, M;

int main()
{
	cin >> N >> M;
	edge temp;
	for (int i = 0; i < M; i++)
	{
		scanf("%d %d %d", &temp.y, &temp.x, &temp.cost);
		e.push_back(temp);

	}

	sort(e.begin(), e.end(), cmp);

	for (int i = 1; i <= 100000; i++)
	{
		arr[i] = i;
	}
	int answer = 0;
	int cnt = 0;
	for (int i = 0; i < e.size(); i++)
	{
		
		if (setunion(e[i].x, e[i].y))
		{
			answer += e[i].cost;
			cnt++;
		}


		if (cnt == N - 1) break;
	}

	cout << answer;
	
	
}