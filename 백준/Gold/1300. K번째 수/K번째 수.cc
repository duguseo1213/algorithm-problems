#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
using namespace std;
//15
int N;
int k;
int main() {
	
	scanf("%d", &N);
	scanf("%d", &k);
	int l = 1;
	int r = min((long long)N*N,(long long)1000000000);
	int answer;
	while (1) {

		if (l > r) break;

		int mid = (l + r) / 2;

		int cnt = 0;

		for (int i = 1; i <= N; i++) {

			int temp = mid / i;

			if (mid / i >= N) {
				temp = N;
			}

			cnt += temp;

		}

		if (cnt >= k) {
			r = mid - 1;
			answer = mid;
		}
		else {
			l = mid + 1;
		}





	}
	cout << answer;
}