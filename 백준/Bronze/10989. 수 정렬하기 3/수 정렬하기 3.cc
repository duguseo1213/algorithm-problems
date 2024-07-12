#define P 
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dat[10001];


vector<int> vec;
int N;
int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		int temp;
		scanf("%d", &temp);

		dat[temp]++;
	}
	
	for (int i = 0; i <= 10000; i++) {

		for (int j = 0; j < dat[i]; j++) {
			printf("%d\n", i);
		}


	}

	

}