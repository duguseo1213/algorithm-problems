#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <queue>
#include <cstring>
#include <climits>
using namespace std;

struct edge {
	int start;
	int end;
	int weight;
};

vector<edge> edges;
long long dist[510];
int N, M;

void func()
{
	for (int i = 1; i <=N-1; i++)
	{
		for (int j = 0; j < edges.size(); j++)
		{
			if (dist[edges[j].start] == 21e8) continue;

			if (dist[edges[j].start] + edges[j].weight < dist[edges[j].end])
			{
				
				dist[edges[j].end] = dist[edges[j].start] + edges[j].weight;
			}
			


		}
		
	}
}


int main()
{
	cin >> N >> M;

	int state = 0;
	edge temp;
	for (int i = 1; i <= N; i++)
	{
		dist[i] = 21e8;
	}
	dist[1] = 0;

	for (int i = 0; i < M; i++)
	{
		scanf("%d %d %d", &temp.start, &temp.end, &temp.weight);

		edges.push_back(temp);

	}
	
	func();
	for (int j = 0; j < edges.size(); j++)
	{
		if (dist[edges[j].start] == 21e8) continue;

		if (dist[edges[j].start] + edges[j].weight < dist[edges[j].end])
		{
			state = 1;
			break;
		}

	}

	if (state == 1)
	{
		cout << -1;
	}
	else
	{
		for (int i = 2; i <= N; i++)
		{
			if (dist[i] == 21e8)
			{
				printf("-1\n");
			}
			else
			{
				printf("%d\n", dist[i]);
			}
		}
	}

}