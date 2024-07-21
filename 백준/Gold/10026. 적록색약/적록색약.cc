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

int visit1[1001][1001];

int visit2[1001][1001];

vector<string> vec;
queue<pair<int, int>> q;

void bfs1(int y,int x,char color) {

	q.push({ y,x });

	visit1[y][x] = 1;

	while (!q.empty()) {

		y = q.front().first;
		x = q.front().second;

		q.pop();


		for (int i = 0; i < 4; i++) {

			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny<0 || nx<0 || ny> N - 1 || nx> N - 1) continue;

			if (vec[ny][nx] != color) continue;

			if (visit1[ny][nx] != 0) continue;
			visit1[ny][nx] = 1;
			q.push({ ny,nx });

		}
	}


}

void bfs2(int y, int x,char color) {

	q.push({ y,x });

	visit2[y][x] = 1;

	while (!q.empty()) {

		y = q.front().first;
		x = q.front().second;

		q.pop();


		for (int i = 0; i < 4; i++) {

			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny<0 || nx<0 || ny> N - 1 || nx> N - 1) continue;

			if (color == 'R' || color == 'G') {
				if (vec[ny][nx] == 'B') continue;
			}
			else {
				if (vec[ny][nx] != color) continue;;
			}


			if (visit2[ny][nx] != 0) continue;
			visit2[ny][nx] = 1;
			q.push({ ny,nx });

		}
	}


}





int main() {

	string temp;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> temp;
		vec.push_back(temp);


	}
	int cnt1 = 0;
	int cnt2 = 0;
	
	for (int i = 0; i < N; i++) {

		for (int j = 0; j < N; j++) {

			if (visit1[i][j] == 0) {
				bfs1(i, j, vec[i][j]);
				cnt1++;
			}
			if (visit2[i][j] == 0) {

				bfs2(i, j, vec[i][j]);
				cnt2++;
			}
		}
	}
	/*
	for (int i = 0; i < N; i++) {

		for (int j = 0; j < N; j++) {

			printf("%d ", visit1[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for (int i = 0; i < N; i++) {

		for (int j = 0; j < N; j++) {

			printf("%d ", visit2[i][j]);
		}
		printf("\n");
	}*/


	printf("%d %d", cnt1, cnt2);
	
	
}