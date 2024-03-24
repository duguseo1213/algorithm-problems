#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int visit[11];
int arr[10];

int value[11];

int N;
int state = 0;
void dfs(int dep)
{
	int cnt = 0;
	
	

	if (dep > 0)
	{

		for (int j = 0; j < dep; j++)
		{
			if (arr[j] > arr[dep - 1])
			{
				cnt++;
			}
		}

		if (value[arr[dep - 1]] != cnt) return;
	}



	if (dep == N)
	{
		for (int i = 0; i < N; i++)
		{
			printf("%d ", arr[i]);
		}
		return;
	}

	for (int i = 1; i <= N; i++)
	{

		if (visit[i] == 1)
		{
			continue;
		}

		visit[i] = 1;
		arr[dep] = i;
		dfs(dep + 1);
		visit[i] = 0;
	}



}


int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &value[i]);
	}


	dfs(0);
}