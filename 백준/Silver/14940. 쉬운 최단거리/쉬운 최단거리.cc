#define P printf
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <algorithm>
#include <ctime>
#include <set>
using namespace std;

//int arr[1001][1001];
int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };
int N, M;

int arr[1001][1001];

int visit[1001][1001];

queue<pair<int, int>> q;


void bfs() {
	
	while (!q.empty()) {

		int y = q.front().first;

		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {

			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny<0 || nx<0 || ny> N - 1 || nx> M - 1) continue;



			if (arr[ny][nx] == 0) continue;
			if (visit[ny][nx] != 0) continue;
			q.push({ ny,nx });
			visit[ny][nx] = visit[y][x]+1;

		}


	}

}

int main() {

	clock_t start, finish;


	
	
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &arr[i][j]);

			if (arr[i][j] == 2) {
				q.push({ i,j });
				visit[i][j] = 1;
			}

		}
	}


	start = clock();
	
	
	bfs();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {

			if (visit[i][j] > 0) visit[i][j]--;

			if (visit[i][j] == 0 && arr[i][j]==1) visit[i][j] = -1;

			printf("%d ", visit[i][j]);

			

		}
		printf("\n");
	}


	
	finish = clock();
	
	//P("%f ", double(finish - start)/1000);

	
	
}