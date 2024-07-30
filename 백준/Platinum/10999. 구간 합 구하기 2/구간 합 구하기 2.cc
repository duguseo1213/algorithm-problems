#define _CRT_SECURE_NO_WARNINGS


#include <iostream>
#include <set>
#include <vector>


using namespace std;

long long tree[4000000];
long long lazy[4000000];

int N, M, K;


void lazy_update(int left, int right, int node) {

	if (lazy[node] == 0) {
		return;
	}

	tree[node] += (right - left + 1) * lazy[node];

	if (left != right) {

		lazy[node * 2] += lazy[node];
		lazy[node * 2+1] += lazy[node];
	}

	lazy[node] = 0;


}

void update(int left, int right, int node, int L, int R, long long value) {

	lazy_update(left, right, node);

	if (left > R || right < L) {

		return;
	}

	if (left >= L && right <= R) {

		tree[node] += (right - left + 1) * value;

		if (left != right) {

			lazy[node * 2] += value;
			lazy[node * 2+1] += value;
		}

		return;
	}

	int mid = (left + right) / 2;

	update(left, mid, node * 2, L, R, value);
	update(mid+1, right, node * 2+1, L, R, value);

	tree[node] = tree[node * 2] + tree[node * 2 + 1];


}

void update2(int left, int right, int node, int index, long long value) {


	if (left > index || right < index) {

		return;
	}

	if (left==right) {

		tree[node] = value;
		return;
	}

	int mid = (left + right) / 2;

	update2(left, mid, node * 2, index, value);
	update2(mid + 1, right, node * 2 + 1, index, value);

	tree[node] = tree[node * 2] + tree[node * 2 + 1];


}

long long query(int left, int right, int L, int R, int node) {

	lazy_update(left, right, node);

	if (left > R || right < L) {

		return 0;
	}

	if (left >= L && right <= R) {

		return tree[node];

	}

	int mid = (left + right) / 2;

	return query(left, mid, L, R, node * 2) + query(mid + 1, right, L, R, node * 2+1);

}

int main() {
	scanf("%d %d %d", &N, &M, &K);

	for (int i = 1; i <= N; i++) {
		long long temp;
		scanf("%lld", &temp);

		update2(1, N, 1, i, temp);

	}

	for (int i = 0; i < M + K; i++) {

		int a;
		scanf("%d", &a);

		if (a == 1) {
			long long b, c, d;

			scanf("%lld %lld %lld", &b, &c, &d);
			update(1, N, 1, b, c, d);
		}
		else {
			int b, c;
			scanf("%d %d", &b, &c);
			printf("%lld\n", query(1, N, b, c, 1));
		}

	}



}