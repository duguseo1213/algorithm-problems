#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int a[500001];
int b[500001];

int result[500001];

int N, M;


void merge(int start,int end) {

	int i, j, k, mid;

	mid = (start + end) >> 1;

	i = start;
	j = mid + 1;
	k = start;
	

	while (i <= mid && j <= end) {

		if (a[i] < a[j]) b[k++] = a[i++];
		else b[k++] = a[j++];

	}

	while (i <= mid) b[k++] = a[i++];

	while (j <= end) b[k++] = a[j++];

	for (i = start; i <= end; i++) {
		a[i] = b[i];
	}

}



void sort(int start, int end) {

	if (start >= end) return;

	int mid = (start + end) >> 1;

	sort(start, mid);
	sort(mid + 1, end);

	merge(start, end);


}

int main()
{

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
	}

	sort(0, N-1);

	for (int i = 0; i < N; i++) {
		//printf("%d ", a[i]);
	}

	//printf("\n");

	scanf("%d", &M);

	for (int i = 0; i < M; i++) {
		scanf("%d", &result[i]);
	}

	

	for (int i = 0; i < M; i++) {

		int left = 0;
		int right = N-1;
		int state = 0;
		while (1) {

			if (left > right) break;

			int mid = (left + right) / 2;

			if (result[i] > a[mid]) {
				left = mid + 1;
			}
			else if (result[i] < a[mid]) {
				right = mid - 1;
			}
			else {
				state = 1;
				printf("1 ");
				break;
			}



		}

		if (state == 0) {
			printf("0 ");
		}

	}


	
}