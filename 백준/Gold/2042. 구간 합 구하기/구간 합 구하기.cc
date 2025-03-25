#define _CRT_SECURE_NO_WARNINGS
#define P printf
#include <set>
#include <iostream>
using namespace std;

int N, M, K;

long long tree[4000000];

void update(int left, int right, int index, int node, long long value) {

	if (left > index || right < index) {

		return;
	}

	if (left == right) {
		tree[node] = value;
		return;
	}

	int mid = (left + right) / 2;

	update(left, mid, index, node * 2, value);
	update(mid + 1, right, index, node * 2 + 1, value);

	tree[node] = tree[node * 2] + tree[node * 2 + 1];


}

long long query(int left, int right, int L, int R, int node) {

	if (left > R || right < L) {
		return 0;
	}

	if (L <= left && right <= R) {
		return tree[node];
	}

	int mid = (left + right) / 2;

	return query(left, mid, L, R, node * 2) + query(mid + 1, right, L, R, node * 2 + 1);



}


int main() {

	scanf("%d %d %d", &N, &M, &K);

	for (int i = 1; i <= N; i++) {
		long long temp;
		scanf("%lld", &temp);
		update(1, N, i, 1, temp);
	}
	
	for (int i = 0; i < M + K; i++) {

		long long a, b, c;
		scanf("%lld %lld %lld", &a, &b, &c);

		if (a == 1) {

			update(1, N, b, 1, c);
		}
		else {
			printf("%lld\n", query(1, N, b, c, 1));
		}


	}



}