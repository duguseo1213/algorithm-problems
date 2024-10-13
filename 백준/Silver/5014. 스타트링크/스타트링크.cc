#define P printf
#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <iostream>
#include <string>
#include <queue>
using namespace std;

int F, S, G, U, D;

int N, M;

int visit[1000010];

queue<pair<int,int>> q;


int main() {

	scanf("%d %d %d %d %d", &F, &S, &G, &U, &D);


	visit[S] = 1;
	q.push({ S,1 });
	
	while (!q.empty()) {

		pair<int, int> p = q.front();
		q.pop();

		if (p.first+U<=F && visit[p.first + U] == 0) {

			visit[p.first + U] = p.second + 1;
			q.push({ p.first + U,p.second + 1 });
		}

		if (p.first - D > 0 && visit[p.first - D] == 0) {

			visit[p.first - D] = p.second + 1;
			q.push({ p.first - D,p.second + 1 });
		}


	}

	if (visit[G] > 0) {
		printf("%d", visit[G]-1);
	}
	else {
		printf("use the stairs");
	}

	

}