#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

vector<int> vec;


int gcd(int a, int b) {

	int q;

	if (b > a) {
		q = b;
		b = a;
		a = q;
	}

	while (1) {
		int temp = a % b;
		if (temp == 0) {
			return b;
		}
		a = b;
		b = temp;

	}
}

int N;

long long func() {
	
	long long temp = 0;
	for (int i = 0; i < vec.size(); i++) {
		for (int j = i + 1; j < vec.size(); j++) {
			temp += gcd(vec[i], vec[j]);
		}
	}
	return temp;

}

int main() {
	scanf("%d", &N);

	//printf("%d\n", gcd(4, 6));
	
	for (int i = 0; i < N; i++) {
		vec.clear();
		long long answer = 0;
		int a;
		scanf("%d", &a);
		for (int j = 0; j < a; j++) {
			int temp;
			scanf("%d", &temp);
			vec.push_back(temp);
		}
		answer = func();
		printf("%lld\n", answer);
	}

	
}

