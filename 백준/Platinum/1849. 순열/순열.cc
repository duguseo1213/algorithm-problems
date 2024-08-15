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
	
	for (int i = 1; i < N; i++) {
		int temp;
		scanf("%d", &temp);

		int l = 1;
		int r = N;

		while (1) {

			if (l > r) break;

			int mid = (l + r) / 2;

			int t = query(1, N, 1, mid-1, 1);

			if (mid -t-1 == temp && answer[mid]==0) {

				//printf("i:%d t: %d mid: %d\n",i, t,mid);
				update(1, N, mid, 1, 1);
				answer[mid] = i;
				break;
			}
			else if ( mid -t-1  > temp) {
				r = mid - 1;
				
			}
			else {
				l = mid + 1;
			}

		}




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