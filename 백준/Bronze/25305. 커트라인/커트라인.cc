#define _CRT_SECURE_NO_WARNINGS
#define P printf
#include <set>
#include <iostream>
using namespace std;

int a[1001];
int b[1001];


int N, M;

void merge(int start, int end) {

	int i, j, k, mid;

	mid = (start + end) >> 1;

	i = start;
	j = mid + 1;
	k = start;

	while (i <= mid && j <= end) {

		if (a[i] > a[j]) b[k++] = a[i++];

		else b[k++] = a[j++];

	}

	while (i <= mid) {
		b[k++] = a[i++];
	}

	while (j <= end) {
		b[k++] = a[j++];
	}

	for (int i = start; i <= end; i++) {
		a[i] = b[i];
	}


}


void sort(int start, int end) {

	if (start >= end) {
		return;
	}

	int mid = (start + end) / 2;

	sort(start, mid);
	sort(mid + 1, end);

	merge(start, end);


}


int main() {

	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
	}

	sort(0, N-1);

	for (int i = 0; i < N; i++) {
		//printf("%d ", a[i]);
	}

	printf("%d", a[M - 1]);

}