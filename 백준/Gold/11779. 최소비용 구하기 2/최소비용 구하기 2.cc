#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

int N, M;

vector<pair<int, int>> edge[1001];

priority_queue<pair<long long, long long>,vector<pair<long long, long long>>,greater<pair<long long, long long>>> pq;
//앞에가 값 뒤에가 현재위치
long long dist[1001];

int parent[1001];
int start;
int endd;
void dijk() {

	for (int i = 0; i < 1001; i++) {
		dist[i] = 21e12;
	}

	dist[start] = 0;

	pq.push({ 0,start });

	while (!pq.empty()) {

		
		pair<long long,long long> now = pq.top();
		pq.pop();

		if (dist[now.second] < now.first ) {
			continue;
		}

		for (int i = 0; i < edge[now.second].size(); i++) {

			long long sum = now.first + edge[now.second][i].second;

			if (sum < dist[edge[now.second][i].first]) {

				dist[edge[now.second][i].first] = sum;
				pq.push({ sum,edge[now.second][i].first });
				parent[edge[now.second][i].first] = now.second;
			}
		}

	}



}



int main(void)
{
	
	scanf("%d %d", &N, &M);

	for (int i = 0; i < M; i++) {
		int a, b, c;

		scanf("%d %d %d", &a, &b, &c);

		edge[a].push_back({b,c});


	}
	
	scanf("%d %d", &start, &endd);

	dijk();
	vector<int> path;
	printf("%lld\n", dist[endd]);


	int temp=endd;

	while (1) {


		path.push_back({ temp });
		temp = parent[temp];
		
		if (temp == start) {
			path.push_back({ temp });
			break;
		}
	}

	printf("%d\n", path.size());

	while (1) {

		if (path.size() == 0) break;

		printf("%d ", path[path.size() - 1]);

		path.pop_back();

	}


	return 0;
}