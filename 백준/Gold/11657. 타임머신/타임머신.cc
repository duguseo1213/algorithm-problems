#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>//memset
#include <string>
#include <vector>

using namespace std;

struct edge {
	int start;
	int end;
	int cost;
};

vector<edge> edges;

long long dist[501];

int N, M;

int main() {
	
	scanf("%d %d", &N, &M);

	for (int i = 0; i <= 501; i++) {
		dist[i] = 21e8;
	}

	for (int i = 0; i < M; i++) {
		edge temp;

		scanf("%d %d %d", &temp.start, &temp.end, &temp.cost);
		
		edges.push_back(temp);
		
	}

	dist[1] = 0;

	for (int i = 0; i < N - 1; i++) {

		for (int j = 0; j < edges.size(); j++) {

			if(dist[edges[j].start] == 21e8) {
				continue;
			}

			if(dist[edges[j].start] + edges[j].cost < dist[edges[j].end]) {

				dist[edges[j].end] = dist[edges[j].start] + edges[j].cost;

			}

		}

	}

	for (int j = 0; j < edges.size(); j++) {

		if (dist[edges[j].start] == 21e8) {
			continue;
		}

		if (dist[edges[j].start] + edges[j].cost < dist[edges[j].end]) {

			dist[edges[j].end] = dist[edges[j].start] + edges[j].cost;
			printf("-1");
			return 0;
		}

	}

	for (int i = 2; i <= N; i++) {
		if (dist[i] == 21e8) {
			printf("-1\n");
		}
		else {
			printf("%d\n", dist[i]);
		}
	}

	




}