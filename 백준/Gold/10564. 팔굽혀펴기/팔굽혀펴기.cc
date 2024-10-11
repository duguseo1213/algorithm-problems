#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <cstring>
#include <set>
using namespace std;

int T, N, M;


int dp[5001][5001];

int ddp[5001];


int arr[11];

int main()
{
	scanf("%d", &T);

	for (int u = 0; u < T; u++) {


		scanf("%d %d", &N, &M);

		int NN = N;

		memset(dp, -1, sizeof(dp));

		for (int i = 0; i <= 5000; i++) {
			
			ddp[i] = -1;
		}

		for (int i = 0; i < M; i++) {
			scanf("%d", &arr[i]);

			dp[arr[i]][arr[i]] = 1;
			ddp[arr[i]] = arr[i];

		}

		//if (N >= 5000) N = 5000;

		for (int i = 0; i <= 5000; i++) {

			for (int k = 0; k <= 500;k++) {

				if (dp[i][k] == 1) {

					for (int j = 0; j < M; j++) {

						if (i + k + arr[j] > N) continue;



						dp[i + k + arr[j]][k + arr[j]] = 1;

						ddp[i + k + arr[j]] = max(ddp[i + k + arr[j]], k + arr[j]);


					}
				}
			}

		}
		printf("%d\n", ddp[N]);

		

	}


}