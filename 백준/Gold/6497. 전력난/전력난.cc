#define P printf
#define _CRT_SECURE_NO_WARNINGS

#include <ctime>
#include <string>
#include <iostream>
#include <unordered_map>
#include <map>
#include <set>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>
using namespace std;

int arr[200001];

struct edge {
	int cost;
	int a;
	int b;


};

struct cmp {

	bool operator()(edge a, edge b) {

		return a.cost > b.cost;
	}

};

bool cmp2(edge a, edge b){

	return a.cost < b.cost;
}

priority_queue<edge, vector<edge>,cmp> pq;


int find(int tar) {

	if (tar == arr[tar]) {
		return arr[tar];
	}

	int root = find(arr[tar]);

	arr[tar] = root;

	return root;


}

int setunion(int a, int b) {

	int t1 = find(a);
	int t2 = find(b);

	if (t1 == t2) {
		return 0;
	}
	else {
		arr[t1] = t2;
		return 1;

	}

}

int N, M;

int main() {
	while (1) {
		vector<edge> vec;
		scanf("%d %d", &N, &M);
		int sum=0;
		if (N == 0 && M == 0) break;

		for (int i = 0; i < M; i++) {
			int a, b, c;
			scanf("%d %d", &a, &b);

			scanf("%d", &c);
			sum += c;
			vec.push_back({ c,a,b });
		}
		sort(vec.begin(), vec.end(), cmp2);

		int minsum = 0;

		for (int i = 0; i <= 200000; i++) {
			arr[i] = i;
		}
		int cnt = 0;
		for (int i = 0; i < vec.size(); i++) {

			if (setunion(vec[i].a, vec[i].b) == 1) {
				cnt++;
				minsum += vec[i].cost;
			}
			else {

			}

			if (cnt == N - 1) break;
		}


		printf("%d\n", sum - minsum);
	}
}

/* 
clock_t start, end;
start = clock();
end = clock();
printf("%f\n", ((double)end - (double)start) / 1000);
start = clock();
end = clock();
printf("%f", ((double)end - (double)start) / 1000);*/