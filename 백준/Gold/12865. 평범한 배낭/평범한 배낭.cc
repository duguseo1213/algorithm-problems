#define _CRT_SECURE_NO_WARNINGS
#define P printf

#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <string>

using namespace std;

int N, K;

int arr[100][100010];

int value[100];
int weight[100];

int main() 
{
	scanf("%d %d", &N, &K);

	for (int i = 0; i < N; i++)
	{
		scanf("%d %d",&weight[i], &value[i]);
	}

	for (int i = 0; i <= K; i++)
	{
		if (weight[0] > i)
		{
			arr[0][i] = 0;
		}
		else
		{
			arr[0][i] = value[0];
		}
		//P("%d ", arr[0][i]);
	}

	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j <= K; j++)
		{
			int temp;
			if (weight[i] <= j)
			{
				arr[i][j] = max(arr[i - 1][j], value[i]+arr[i - 1][j - weight[i]]);
			}
			else
			{
				arr[i][j] = arr[i - 1][j];
			}


		}
	}
	/*
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j <= K; j++)
		{
			P("%d ", arr[i][j]);

		}
		P("\n");
	}*/

	P("%d", arr[N-1][K]);
}