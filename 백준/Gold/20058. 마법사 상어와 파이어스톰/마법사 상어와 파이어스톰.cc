#define P printf
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int arr[65][65];
int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };
int N, Q;
int maxx = 0;

queue<pair<int, int>> q;

int visit[65][65];


void rotate(int y,int x,int L) {

	if (L == 0) return;

	int temp[65][65] = { 0, };

	for (int i = 0; i < (1 << L); i++) {
		for (int j = 0; j < (1 << L); j++) {
			temp[j][(1 << L) - i - 1] = arr[y + i][x + j]; // 회전시켜서 저장
		}
	}

	for (int i = 0; i < (1 << L); i++) {
		for (int j = 0; j < (1 << L); j++) {
			arr[y + i][x + j] = temp[i][j]; // 저장된 값을 다시 옮기기
		}
	}




}

void melt() {

	int temp[65][65] = { 0, };

	for (int i = 0; i < (1 << N); i++) {
		for (int j = 0; j < (1 << N); j++) {
			int cnt = 0;

			if (arr[i][j] == 0) continue;

			for (int k = 0; k < 4; k++) {

				int ny = dy[k] + i;
				int nx = dx[k] + j;

				if (ny<0 || nx<0 || ny>(1 << N) - 1 || nx>(1 << N) - 1) continue;

				if (arr[ny][nx] > 0) cnt++;

			}

			if (cnt <= 2) {
				temp[i][j] = 1;
			}


		}
	}

	for (int i = 0; i < (1 << N); i++) {
		for (int j = 0; j < (1 << N); j++) {
		
			if (temp[i][j] == 1) {
				arr[i][j]--;
			}

		}
	}



}


void activate(int L) {

	for (int i = 0; i < (1 << N); i=i+(1<<L)) {
		for (int j = 0; j < (1 << N); j = j + (1 << L)) {
			rotate(i, j, L);
			//P("%d %d\n", i, j);
		}
	}

	melt();




	

}

void bfs(int y,int x) {
	visit[y][x] = 1;
	q.push({ y,x });
	int cnt = 0;
	while (!q.empty()) {
		cnt++;
		y = q.front().first;
		x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {

			int ny = dy[i] + y;
			int nx = dx[i] + x;

			if (ny<0 || nx<0 || ny>(1 << N) - 1 || nx>(1 << N) - 1) continue;

			if (visit[ny][nx] == 1) continue;
			if (arr[ny][nx] == 0) continue;

			q.push({ ny,nx });

			visit[ny][nx] = 1;
			
			
		}


	}


	maxx = max(cnt, maxx);

}


int main() {

	scanf("%d %d", &N, &Q);

	for (int i = 0; i < (1 << N); i++) {
		for (int j = 0; j < (1 << N); j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	
	
	int L;

	for (int i = 0; i < Q; i++) {
		scanf("%d", &L);
		activate(L);
	}

	int sum = 0;


	//P("\n");
	for (int i = 0; i < (1 << N); i++) {
		for (int j = 0; j < (1 << N); j++) {

			sum += arr[i][j];

			if (visit[i][j] == 1) continue;

			if (arr[i][j] == 0) continue;

			bfs(i,j);
			//P("%d ", arr[i][j]);
		}
		//P("\n");
	}

	

	



	P("%d\n%d ", sum,maxx);
}