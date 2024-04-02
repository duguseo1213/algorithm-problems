#define _CRT_SECURE_NO_WARNINGS
#define P 
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int arr[1000];

int find(int tar)
{
	if (tar == arr[tar])
	{
		return tar;
	}

	int ret = find(arr[tar]);

	arr[tar] = ret;

	return ret;

}

int setunion(int a, int b)
{
	int t1 = find(a);
	int t2 = find(b);

	if (t1 == t2)
	{
		return 0;
	}

	arr[t2] = t1;
	return 1;

}

int main()
{
	int T;

	scanf("%d ", &T);

	for (int i = 0; i < T; i++)
	{
		int N, M;
		int cnt = 0;

		scanf("%d %d", &N, &M);

		int a, b;

		

		for (int j = 0; j < M; j++)
		{
			scanf("%d %d", &a, &b);

			



		}

		printf("%d\n", N-1);






	}

}