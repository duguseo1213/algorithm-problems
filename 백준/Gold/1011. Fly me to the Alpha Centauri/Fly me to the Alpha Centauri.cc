#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <cstdbool>
#include <cmath>

using namespace std;

vector<long long> vec;

int T,N,M;
long long answer = 1;
int main() {
	long long aaaa = 1;
	scanf("%d", &T);
	long long gongbae = 2;
	while (1) {

		vec.push_back(answer);

		answer += aaaa;
		aaaa += 1;

		if (answer > 22e8) {
			break;
		}


		vec.push_back(answer);

		answer += gongbae;
		gongbae += 1;

		if (answer > 22e8) {
			break;
		}
	}




	for (int i = 0; i < T; i++) {
		scanf("%d %d", &N, &M);
		int distance = M - N;

		for (int j = 0; j < vec.size(); j++) {

			if (distance <= vec[j]) {
				printf("%d\n", j+1);
				break;
			}

		}


	}

}

