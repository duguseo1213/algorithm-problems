#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <unordered_map>
#include <cstring>
#include <string>
#include <set>

using namespace std;

int N,M;

int arr[2][1000000];

int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
	{

		scanf("%d", &arr[0][i]);
	}

	for (int i = 0; i < M; i++)
	{

		scanf("%d", &arr[1][i]);

	}

	int i = 0;
	int j = 0;

	for(int k=0;k<N+M;k++)
	{
		

		//printf("%d %d\n\n", i, j);
		
		if (i == N)
		{
			printf("%d ", arr[1][j]);
			j++;
			continue;
		}
		else if (j == M)
		{
			printf("%d ", arr[0][i]);
			i++;
			continue;
		}

		else if (arr[0][i] >= arr[1][j])
		{
			printf("%d ", arr[1][j]);
			j++;
			continue;
		}
		else
		{
			printf("%d ", arr[0][i]);
			i++;
			continue;
		}
		
	}



	
}