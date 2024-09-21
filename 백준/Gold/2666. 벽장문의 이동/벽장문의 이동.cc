#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int N;

int l, r;
int cnt;

int order[21];
int answer=21e8;

void dfs(int left,int right,int depth,int mcnt) {

	if (depth == cnt) {
		answer = min(answer, mcnt);
		return;
	}


	

	dfs(order[depth], right, depth + 1, mcnt + abs(order[depth] - left));

	dfs(left, order[depth], depth + 1, mcnt + abs(order[depth] - right));

	

	


}

int main()
{
	scanf("%d", &N);

	scanf("%d %d", &l, &r);

	scanf("%d", &cnt);

	for (int i = 0; i < cnt; i++) {
		scanf("%d", &order[i]);
	}

	dfs(l, r, 0, 0);

	printf("%d", answer);
   
}