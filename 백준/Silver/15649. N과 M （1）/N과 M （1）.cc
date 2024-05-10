#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <queue>
#include <map>
using namespace std;

int N, M;

int visit[10];
int dat[10];
void dfs(int dep)
{
	if (dep == M)
	{
		for (int i = 0; i < M; i++)
		{
			printf("%d ", visit[i]);
		}
		printf("\n");
		return;
	}

	for (int i = 1; i <= N; i++)
	{
		if (dat[i] == 0)
		{
			dat[i] = 1;
			visit[dep] = i;
			dfs(dep + 1);
			dat[i] = 0;
		}
	}

}



int main()
{
	scanf("%d %d", &N, &M);

	dfs(0);



}
