#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <unordered_set>
using namespace std;
unordered_set<int> graph[100001];
queue<int> q;
int N;

void dfs(int v)
{
	q.pop();

	//cout << v << " ";
	while (1)
	{
		if (q.size() == 0) return;
		if (graph[v].end() != graph[v].find(q.front()))
		{
			dfs(q.front());
		}
		else {
			return;
		}
	}
}

int main()
{
	cin >> N;
	int a, b;
	for (int i = 0; i < N - 1; i++)
	{
		scanf("%d %d", &a, &b);

		//graph.push_back(unordered_set<int>());

		graph[a].insert(b);
		graph[b].insert(a);
	}

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &a);
		q.push(a);
	}
	dfs(1);
	if (q.size() > 0) cout << 0;
	else cout << 1;

}
