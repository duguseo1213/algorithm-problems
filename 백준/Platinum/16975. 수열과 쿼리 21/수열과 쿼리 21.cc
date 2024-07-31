#define P printf
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

long long tree[400000];
long long lazy[400000];
int N, M;

void update(int left, int right, int node, int index, long long value) {
	if (left>index || right<index) {
		return;
	}

	if (left == right) {
		tree[node] = value;
		return;
	}

	int mid = (left + right) / 2;

	update(left, mid, node * 2, index, value);
	update(mid+1, right, node * 2+1, index, value);

	tree[node] = tree[node * 2] + tree[node * 2+1];


}

void lazyupdate(int left, int right, int node) {

	if (lazy[node] == 0) {
		return;
	}
	
	tree[node] += (right - left + 1) * lazy[node];

	if (left != right) {

		lazy[node * 2] += lazy[node];
		lazy[node * 2 + 1] += lazy[node];

	}

	lazy[node] = 0;


}


void update2(int left, int right, int L, int R, int node, long long value) {

	lazyupdate(left, right, node);

	if (left > R || right < L) {

		return;
	}

	if (left >= L && right <= R) {

		tree[node] += (right - left + 1) * value;
		
		if (left != right) {

			lazy[node * 2] += value;
			lazy[node * 2 + 1] += value;

		}

		return;
	}

	int mid = (left + right) / 2;

	update2(left, mid, L, R, node * 2, value);
	update2(mid + 1, right, L, R, node * 2 + 1, value);
	
	tree[node] = tree[node * 2] + tree[node * 2 + 1];

}

long long query(int left, int right, int L, int R, int node) {
	lazyupdate(left, right, node);

	if (left > R || right < L) {

		return 0;
	}

	if (left >= L && right <= R) {

		return tree[node];
	}
	int mid = (left + right) / 2;

	return query(left, mid, L, R, node * 2)+query(mid+1,right,L,R,node*2+1);

}


int main() {
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		long long temp;
		scanf("%lld", &temp);
		update(1, N, 1, i, temp);


	}

	scanf("%d", &M);

	for (int i = 0; i < M; i++) {
		int a;

		scanf("%d", &a);

		if (a == 1) {
			int b, c;
			long long d;
			scanf("%d %d %lld", &b, &c, &d);
			update2(1, N, b, c, 1, d);

		}
		else {
			int b;
			scanf("%d", &b);
			printf("%lld\n", query(1, N, b, b, 1));

		}



	}




}