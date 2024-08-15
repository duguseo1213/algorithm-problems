#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int tree[400000];

int arr[100001];

int answer[100001];

int N;

void update(int left, int right, int index, int node, int value) {

	if (left>index || index>right) {

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

int good;
void finds(int left, int right, int value, int node) {

	if (left == right) {

		good = right;
		return;
	}

	

	int mid = (left + right) / 2;
	//printf("%d ", tree[node]);
	if (tree[node*2] > value) {
		finds(left, mid, value, node * 2);
	}
	else {
		finds(mid+1, right, value-tree[node*2], node * 2 + 1);
	}


}

int query(int left, int right, int L, int R, int node) {

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
	scanf("%d", &N);
	
	for (int i = 1; i <= N; i++) {

		update(1, N, i, 1, 1);
	}


	for (int i = 1; i < N; i++) {
		int temp;
		scanf("%d", &temp);

		finds(1, N, temp, 1);

		//printf("i: %d good:%d temp:%d\n", i, good, temp);

		update(1, N, good, 1, 0);
		answer[good] = i;



	}
	int a;
	scanf("%d", &a);



	for (int i = 1; i <= N; i++) {

		if (answer[i] == 0) {
			printf("%d\n",N);
		}
		else {
			printf("%d\n", answer[i]);
		}
	}


}