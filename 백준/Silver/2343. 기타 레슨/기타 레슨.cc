#define P printf
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <climits>

using namespace std;

int N, M;

int arr[100001];

int main() {
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);


	}
	int answer;
	int l = 1;
	int r = 1000000000;

	while (1) {

		if (l > r) {

			break;
		}

		int mid = (l + r) / 2;
		
		int cnt = 1;
		int sum = 0;
		int state = 0;
		for (int i = 0; i < N; i++) {

			if (arr[i] > mid) {
				state = 1;
			}

			if (sum + arr[i] > mid) {

				sum = arr[i];
				cnt++;
			}
			else {
				sum += arr[i];
			}
		}

		if (cnt > M || state==1) {
			l = mid + 1;
		}
		else {
			answer = mid;
			r = mid - 1;
		}



	}

	cout << answer;

}
