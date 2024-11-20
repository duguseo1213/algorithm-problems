#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <cstdbool>
#include <cmath>

using namespace std;
int N, M;

bool check[1000001];

int main() {
	scanf("%d %d", &M,&N);
	check[0] = 1;
	check[1] = 1;
	check[2] = 0;

	for (int i = 2; i <= sqrt(1000000); i++) {
		
		if (!check[i]) {
			
			for (int j = i + i; j <= 1000000; j += i) {
				check[j] = 1;
			}
		}
		
	}

	for (int i = M; i <= N; i++) {
		if (!check[i]) {
			printf("%d\n", i);
		}
	}
	



	
}

