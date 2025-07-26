#define P printf
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>
#include <vector>
#include <unordered_set>

using namespace std;

int N, M;

int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };

int tcnt = 2;


int team[100000];

int arr[1000][1000];

int maxx = 0;

queue<pair<int, int>> q;

void bfs(int a,int b) {
	
	q.push({ a,b });

	arr[a][b] = tcnt;
	int good = 1;

	while (!q.empty()) {

		pair<int, int> temp = q.front();
		q.pop();

		

		for (int i = 0; i < 4; i++) {

			int ny = temp.first + dy[i];
			int nx = temp.second + dx[i];

			if (ny<0 || nx<0 || ny>N-1 || nx > M-1) continue;

			if (arr[ny][nx] != 1) continue;

			good++;

			arr[ny][nx] = tcnt;

			q.push({ ny,nx });


		}


	}

	team[tcnt] = good;
	

	tcnt++;
}

int main() {
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &arr[i][j]);
		}
	}


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] != 1) continue;	
			bfs(i, j);
		}
	}



	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {

			if (arr[i][j] == 0) {

				int hi = 0;

				unordered_set<int> us;
				

				for (int k = 0; k < 4; k++) {

					int ny = i + dy[k];
					int nx = j + dx[k];

					if (ny<0 || nx<0 || ny>N - 1 || nx > M - 1) continue;

					if (arr[ny][nx] == 0) continue;

					if (us.find(arr[ny][nx]) != us.end()) continue;



					us.insert(arr[ny][nx]);


					hi += team[arr[ny][nx]];

				}

				us.clear();

				//printf("\n");

				maxx=max(maxx, hi);

			}
		}
	}

	printf("%d", maxx+1);

}