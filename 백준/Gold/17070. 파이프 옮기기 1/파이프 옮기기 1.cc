#define _CRT_SECURE_NO_WARNINGS
#define P printf
#include <set>
#include <iostream>
#include <string>

using namespace std;

int N;

int arr[20][20];

int dfs(int y,int x,int state) {

	if (y == N - 1 && x == N - 1) {
		return 1;
	}
	int sum = 0;
	if ((state==1|| state==2) && y < N - 1 ) {
		if (arr[y+1][x]==0) {
			sum += dfs(y + 1, x, 1);
		}
	}

	if ((state == 0 || state == 2) && x < N - 1 ) {
		if (arr[y][x + 1] == 0) {
			sum += dfs(y, x + 1, 0);
		}
	}

	if (y < N - 1 && x < N - 1) {
		if (arr[y][x + 1] == 0 && arr[y + 1][x] == 0 && arr[y + 1][x + 1] == 0) {
			sum += dfs(y + 1, x + 1, 2);
		}
	}
	
	return sum;


}


int main() {

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	cout<<dfs(0, 1, 0);


}


