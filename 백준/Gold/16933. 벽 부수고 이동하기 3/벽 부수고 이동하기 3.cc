#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<string> vec;

int arr[1000][1000][11][2];

int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };

int N, M, K;

struct Node {

	int y;
	int x;

	int k;
	int state; //0 naz // 1 bam

};

queue<Node> q;

void bfs() {

	Node nd;
	nd.x = 0;
	nd.y = 0;
	nd.k = K;
	nd.state = 0;

	arr[0][0][K][0] = 1;

	q.push(nd);

	while (!q.empty()) {

		Node now = q.front();

		q.pop();
			
		if (now.state == 1) {
			if (arr[now.y][now.x][now.k][0] == 0) {

				q.push({ now.y,now.x,now.k,0 });
				arr[now.y][now.x][now.k][0] = arr[now.y][now.x][now.k][1] + 1;

			}
		}
		
		for (int i = 0; i < 4; i++) {
				
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];

			if (ny<0 || nx<0 || ny>N - 1 || nx>M - 1) continue;
			if (now.state == 0) {
				if (vec[ny][nx] == '0') {
					if (arr[ny][nx][now.k][1] == 0) {
						q.push({ ny,nx,now.k,1 });
						arr[ny][nx][now.k][1] = arr[now.y][now.x][now.k][0] + 1;

					}
				}

				if (vec[ny][nx] == '1' && now.k>0) {
					if (arr[ny][nx][now.k -1][1] == 0) {
						q.push({ ny,nx,now.k -1,1 });
						arr[ny][nx][now.k -1][1] = arr[now.y][now.x][now.k][0] + 1;

					}
				}
			}

			if (now.state == 1) {

				if (vec[ny][nx] == '0') {
					if (arr[ny][nx][now.k][0] == 0) {

						q.push({ ny,nx,now.k,0});

						arr[ny][nx][now.k][0] = arr[now.y][now.x][now.k][1] + 1;

					}
				}


			}


		}

		


	}



}

int main(){

	scanf("%d %d %d", &N, &M, &K);

	for (int i = 0; i < N; i++) {
		string temp;
		cin >> temp;
		vec.push_back(temp);

	}

	bfs();
	/*
	for (int l = 0; l < 2; l++) {


		for (int k = 0; k <= N; k++) {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {

					printf("%d", arr[i][j][k][l]);

				}
				printf("\n");
			}
			printf("\n");
		}
		printf("\n");
	}*/


	int answer = 21e8;

	for (int i = 0; i <= K; i++) {
		if (arr[N - 1][M - 1][i][0] != 0) {
			answer = min(answer, arr[N - 1][M - 1][i][0]);
		}

		
		if (arr[N - 1][M - 1][i][1] != 0) {
			answer = min(answer, arr[N - 1][M - 1][i][1]);
		}
		
	}
	if (answer == 21e8) {
		printf("-1");
		return 0;
	}

	printf("%d\n", answer);

}