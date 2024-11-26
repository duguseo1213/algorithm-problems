#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <cstdbool>
#include <cmath>
#include <algorithm>

using namespace std;

int N;

struct grade {

	int S;
	int C;
	int L;
	int num;

};

vector<grade> vec;

bool good(grade a,grade b) {

	if (a.S == b.S) {

		if (a.C == b.C) {

			return a.L < b.L;

		}

		return a.C < b.C;

	}

	return a.S > b.S;

}



int main() {
	
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {

		grade temp;
		scanf("%d %d %d", &temp.S, &temp.C, &temp.L);
		temp.num = i + 1;
		vec.push_back(temp);

	}

	sort(vec.begin(), vec.end(), good);

	printf("%d", vec[0].num);
	


}

