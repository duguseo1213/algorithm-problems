#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
#include <vector>
#include <cstring>
#include <unordered_set>

using namespace std;

unordered_set<int> graph[501];

//vector<int> graph[501];
int indegree[501];

int arr[501];

int T;
int N;

int main(void)
{
	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		queue<int> q;
		int state = 0; // 0 정상, 1 ? 2 impossible
		memset(indegree, 0,sizeof(indegree));
		for (int i = 0; i < 501; i++) {
			graph[i].clear();
		}

		scanf("%d", &N);

		for (int j = 0; j < N; j++) {
			scanf("%d", &arr[j]);
		}

		for (int j = 0; j < N; j++) {
			for (int k = j + 1; k < N; k++) {
				graph[arr[j]].insert(arr[k]);
				indegree[arr[k]]++;
			}
		}

		


		int M;
		scanf("%d", &M);

		for (int j = 0; j < M; j++) {
			int a, b;
			scanf("%d %d", &a, &b);

			if (graph[b].find(a) != graph[b].end()) {
				indegree[b]++;
				indegree[a]--;
				graph[a].insert(b);
				graph[b].erase(a);

			}

			else {
				indegree[a]++;
				indegree[b]--;
				graph[b].insert(a);
				graph[a].erase(b);
			}

			


		}

		/*for (int j = 1; j <= N; j++) {
			printf("indegree %d\n", indegree[j]);
			printf("%d\n", j);
			for (auto k = graph[j].begin(); k != graph[j].end(); k++) {
				printf("%d ", *k);
			}
			printf("\n");
		}*/

		


		vector<int> result;
		for (int j = 1; j <= N; j++) {
			if (indegree[j] == 0) {
				//result.push_back(j);
				q.push(j);
			}
		}
		
		for(int i=1;i<=N;i++){

			if (q.empty()) {
				state = 2;
				break;
			}

			if (q.size() > 1) {
				state = 1;
				break;
			}

			int now = q.front();
			result.push_back(now);
			q.pop();

			for (auto j = graph[now].begin(); j != graph[now].end(); j++) {

				//printf("%d ", *j);
				indegree[*j]--;

				if (indegree[*j] == 0) {
					
					q.push(*j);
				}


			}
			//printf("\n");


		}

		if (state == 0) {
			for (int j = 0; j < result.size(); j++) {
				printf("%d ", result[j]);
			}
			printf("\n");
		}
		else if (state == 1) {
			printf("?\n");
		}
		else {
			printf("IMPOSSIBLE\n");
		}








	}



}