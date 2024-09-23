#define P printf
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <map>
#include <tuple>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

//map<tuple<int, int, int, int, int>,pair<int,int>> dp;

unordered_map<long long, pair<int, int>> dp;

long long N, M, K;
pair<long long, long long> arr[1001];

pair<long long,long long> dfs(long long depth, long long y1, long long x1, long long y2, long long x2) {

	if (depth == M) {
		return { 0,0 };
	}

	if (dp.find(x2 + y2 * 1000 + x1 * 1000 * 1000 + y1 * 1000 * 1000 * 1000 + depth * 1000 * 1000 * 1000 * 1000)!=dp.end()){

		//printf("%d ", dp[{depth, y1, x1, y2, x2}].first);

		return dp[x2 + y2 * 1000 + x1 * 1000 * 1000 + y1 * 1000 * 1000 * 1000 + depth * 1000 * 1000 * 1000 * 1000];
	}

	long long l = abs(y1 - arr[depth].first) + abs(x1 - arr[depth].second) + dfs(depth + 1, arr[depth].first, arr[depth].second, y2, x2).first;
	long long r = abs(y2 - arr[depth].first) + abs(x2 - arr[depth].second) + dfs(depth + 1, y1, x1, arr[depth].first, arr[depth].second).first;



	if (l<r) {
		dp[x2 + y2 * 1000 + x1 * 1000 * 1000 + y1 * 1000 * 1000 * 1000 + depth * 1000 * 1000 * 1000 * 1000] = { l,1 };
	}
	else {
		dp[x2 + y2 * 1000 + x1 * 1000 * 1000 + y1 * 1000 * 1000 * 1000 + depth * 1000 * 1000 * 1000 * 1000] = { r,2 };
	}


	//printf("%d ", dp[{depth, y1, x1, y2, x2}].first);

	return dp[x2 + y2 * 1000 + x1 * 1000 * 1000 + y1 * 1000 * 1000 * 1000 + depth * 1000 * 1000 * 1000 * 1000];

}


int main() {

	scanf("%lld", &N);
	scanf("%lld", &M);
	for (int i = 0; i < M; i++) {
		long long w, x;

		scanf("%lld %lld", &w, &x);
		w--;
		x--;

		arr[i].first = w;
		arr[i].second = x;

	}
	
	long long qq=dfs(0, 0, 0, N - 1, N - 1).first;

	printf("%lld\n", qq);

	long long a, b, c, d, e;

	b = 0;
	c = 0;
	d = N - 1;
	e = N - 1;
	
	for (long long i = 0; i < M; i++) {

		printf("%lld\n", dp[e + d * 1000 + c * 1000 * 1000 + b * 1000 * 1000 * 1000 + i * 1000 * 1000 * 1000 * 1000].second);

		if (dp[e + d * 1000 + c * 1000 * 1000 + b * 1000 * 1000 * 1000 + i * 1000 * 1000 * 1000 * 1000].second == 1) {
			
			//depth + 1, arr[depth].first, arr[depth].second, y2, x2

			b = arr[i].first;
			c = arr[i].second;


		}
		else {
			d = arr[i].first;
			e = arr[i].second;
		}

	}
	



}
