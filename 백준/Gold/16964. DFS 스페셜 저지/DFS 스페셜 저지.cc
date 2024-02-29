
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>



using namespace std;
vector<int> graph[100001];
queue<int> q;
int visit[100001];
int N;

int state = 0;
void dfs(int r)
{
	
	
	//cout << r << " ";
	

	for (int i = 0; i < graph[r].size(); i++)
	{
		int temp;
		
		if (q.size() == 0) return;
		if (visit[q.front()] == 1) continue;

		if (graph[r].end() != find(graph[r].begin(), graph[r].end(), q.front()))
		{
			
			
			temp = q.front();

			q.pop();
			
			visit[temp] = 1;
			dfs(temp);
			

		}
		else
		{
			
			return;
		}

	}

}

int main()
{
	int a, b;
	cin >> N;
	for (int i = 0; i < N-1; i++)
	{
		scanf("%d %d", &a, &b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &a);
		q.push(a);
	}
	visit[1] = 1;
	q.pop();
	dfs(1);
	//cout << endl;
	if (q.size()>0) cout << 0;
	else cout << 1;
}
