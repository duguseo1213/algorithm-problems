#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
#include <tuple>
#include <set>
using namespace std;

int A, B, C;

queue<int> q;

set<int> answer;

unordered_set<int> us;

void bfs(int a,int b, int c) {

	answer.insert(c);
	us.insert(a * 1000000 + b * 1000 + c);
	q.push(a*10000+b*100+c);

	while (!q.empty()) {

		int temp = q.front();
		q.pop();

		int a = temp / 1000000;
		int b = (temp / 1000 )% 1000;;
		int c = temp % 1000;

		int tmp1, tmp2, tmp3;

		if (a != 0) {
			if (B - b > a) {
				tmp2 = b + a;
				tmp1 = 0;
				tmp3 = c;

				int num = tmp1 * 1000000 + tmp2 * 1000 + tmp3;

				if (us.find(num) == us.end()) {
					if (tmp1 == 0) {
						answer.insert(tmp3);
					}
					us.insert(num);
					q.push(num);
				}
			}
			else {
				tmp2 = B;
				tmp1 = a + b - B;
				tmp3 = c;

				int num = tmp1 * 1000000 + tmp2 * 1000 + tmp3;

				if (us.find(num) == us.end()) {
					if (tmp1 == 0) {
						answer.insert(tmp3);
					}
					us.insert(num);
					q.push(num);
				}

			}

			if (C - c > a) {
				tmp3 = c + a;
				tmp1 = 0;
				tmp2 = b;

				int num = tmp1 * 1000000 + tmp2 * 1000 + tmp3;

				if (us.find(num) == us.end()) {
					if (tmp1 == 0) {
						answer.insert(tmp3);
					}
					us.insert(num);
					q.push(num);
				}
			}
			else {
				tmp2 = b;
				tmp1 = a + c - C;
				tmp3 = C;

				int num = tmp1 * 1000000 + tmp2 * 1000 + tmp3;

				if (us.find(num) == us.end()) {
					if (tmp1 == 0) {
						answer.insert(tmp3);
					}
					us.insert(num);
					q.push(num);
				}

			}

		}

		if (b != 0) {

			if (A - a > b) {
				tmp2 = 0;
				tmp1 = a+b;
				tmp3 = c;

				int num = tmp1 * 1000000 + tmp2 * 1000 + tmp3;

				if (us.find(num) == us.end()) {
					if (tmp1 == 0) {
						answer.insert(tmp3);
					}
					us.insert(num);
					q.push(num);
				}
			}
			else {
				tmp2 = b+a-A;
				tmp1 = A;
				tmp3 = c;

				int num = tmp1 * 1000000 + tmp2 * 1000 + tmp3;

				if (us.find(num) == us.end()) {
					if (tmp1 == 0) {
						answer.insert(tmp3);
					}
					us.insert(num);
					q.push(num);
				}

			}

			if (C - c > b) {
				tmp3 = c + b;
				tmp1 = a;
				tmp2 = 0;

				int num = tmp1 * 1000000 + tmp2 * 1000 + tmp3;

				if (us.find(num) == us.end()) {
					if (tmp1 == 0) {
						answer.insert(tmp3);
					}
					us.insert(num);
					q.push(num);
				}
			}
			else {
				tmp2 = b+c-C;
				tmp1 = a;
				tmp3 = C;

				int num = tmp1 * 1000000 + tmp2 * 1000 + tmp3;

				if (us.find(num) == us.end()) {
					if (tmp1 == 0) {
						answer.insert(tmp3);
					}
					us.insert(num);
					q.push(num);
				}

			}

		}

		if (c != 0) {

			if (A - a > c) {
				tmp2 = b;
				tmp1 = a + c;
				tmp3 = 0;

				int num = tmp1 * 1000000 + tmp2 * 1000 + tmp3;

				if (us.find(num) == us.end()) {
					if (tmp1 == 0) {
						answer.insert(tmp3);
					}
					us.insert(num);
					q.push(num);
				}
			}
			else {
				tmp2 = b;
				tmp1 = A;
				tmp3 = c+a-A;

				int num = tmp1 * 1000000 + tmp2 * 1000 + tmp3;

				if (us.find(num) == us.end()) {
					if (tmp1 == 0) {
						answer.insert(tmp3);
					}
					us.insert(num);
					q.push(num);
				}

			}

			if (B - b > c) {
				tmp3 = 0;
				tmp1 = a;
				tmp2 = b+c;

				int num = tmp1 * 1000000 + tmp2 * 1000 + tmp3;

				if (us.find(num) == us.end()) {
					if (tmp1 == 0) {
						answer.insert(tmp3);
					}
					us.insert(num);
					q.push(num);
				}
			}
			else {
				tmp3 = b + c - B;
				tmp1 = a;
				tmp2 = B;

				int num = tmp1 * 1000000 + tmp2 * 1000 + tmp3;

				if (us.find(num) == us.end()) {
					if (tmp1 == 0) {
						answer.insert(tmp3);
					}
					us.insert(num);
					q.push(num);
				}

			}

		}







	}


}

int main() {

	scanf("%d %d %d", &A, &B, &C);


	bfs(0, 0, C);

	for (auto i = answer.begin(); i != answer.end(); i++) {
		cout << *i << " ";
	}


}