#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <cstring>
#include <set>
#include <queue>
using namespace std;

int T, N, M;


bool dp[5101][5101];

int ddp[5101];

queue<pair<int, int>> q;

int arr[11];

int main()
{
	scanf("%d", &T);

	for (int u = 0; u < T; u++) {


		scanf("%d %d", &N, &M);

		int NN = N;

		for (int i = 0; i <= N; i++) {
			for (int j = 0; j <= N; j++) {
				dp[i][j] = 0;
			}
		}

		for (int i = 0; i <= 5000; i++) {
			
			ddp[i] = -1;
		}

		for (int i = 0; i < M; i++) {
			scanf("%d", &arr[i]);

			q.push({ arr[i],arr[i] });

			dp[arr[i]][arr[i]] = 1;
			ddp[arr[i]] = arr[i];

		}

		while (!q.empty()) {

			pair<int, int> p = q.front();
			q.pop();

			if (p.first == N) {
				ddp[p.first] = max(ddp[p.first], p.second);
			}

			
			

			for (int i = 0; i < M; i++) {
				if (p.first + p.second + arr[i] > N) continue;
				if (dp[p.first + p.second + arr[i]][p.second + arr[i]] == 1) continue;

				
				

				

				

				dp[p.first + p.second + arr[i]][p.second + arr[i]] = 1;

				q.push({ p.first + p.second + arr[i],p.second + arr[i] });


			}


		}
		
		printf("%d\n", ddp[N]);
		

		

	}


}