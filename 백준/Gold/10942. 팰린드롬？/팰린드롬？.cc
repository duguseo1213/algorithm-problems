#define P 
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;

int arr[2001];
int dp[2001][2]; //0은 홀수개 // 1은 짝수개
int Q;

int main() {
	scanf("%d", &N);
	
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < N; i++) {
		int l = i;
		int r = i;

		dp[i][0] = 1;
		int cnt = 1;
		while (1) {

			l--;
			r++;

			if (l<0 || r>N - 1) break;

			if (arr[l] != arr[r]) break;

			cnt++;
			
		}

		dp[i][0] = cnt;

		l = i;
		r = i + 1;
		cnt = 0;
		while (1) {

			if (l<0 || r>N - 1) break;

			if (arr[l] != arr[r]) break;

			cnt++;

			l--;
			r++;

		}
		dp[i][1] = cnt;

		//printf("%d %d\n", dp[i][0], dp[i][1]);


	}

	scanf("%d", &Q);
	int a, b;
	for (int i = 0; i < Q; i++) {
		scanf("%d %d", &a, &b);
		a--;
		b--;
		int temp=(a+b)/2;
		if ((b - a) % 2 == 0) { //홀수개
			if (dp[temp][0]-1  >= temp-a) {
				printf("1\n");
			}
			else {
				printf("0\n");
			}
		}
		else {

			if (dp[temp][1] - 1 >= temp - a) {
				printf("1\n");
			}
			else {
				printf("0\n");
			}

		}

	}


}