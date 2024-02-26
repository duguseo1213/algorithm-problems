#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <map>
#include <cmath>
using namespace std;

int arr[501];
int dat[501];

int find(int tar)
{
	
	if (tar == arr[tar])
	{
		return tar;
	}

	int root = find(arr[tar]);

	arr[tar] = root;

	return root;

}

void setunion(int a, int b)
{
	int t1 = find(a);
	int t2 = find(b);

	if (t1 == t2)
	{
		dat[t1] = 1; //loop
		return;
	}

	if (dat[t2] == 1)
	{
		dat[t1] = 1;
	}

	arr[t2] = t1;


}

int main()
{
	int N, M;
	int cases = 0;
	while (1)
	{
		cases++;
		scanf("%d %d", &N, &M);

		if (N == 0 && M == 0) break;
		int tree = 0;
		for (int j = 1; j <= N; j++)
		{
			arr[j] = j;
			dat[j] = 0;
		}
		for (int i = 0; i < M; i++)
		{


			int a, b;
			scanf("%d %d", &a, &b);
			setunion(a, b);


		}


		for (int j = 1; j <= N; j++)
		{
			if (find(j) == j && dat[find(j)]==0)
			{
				tree++;
			}
		}

		if (tree == 0)
		{
			printf("Case %d: No trees.\n", cases);
		}
		else if (tree == 1)
		{
			printf("Case %d: There is one tree.\n", cases);
		}
		else
		{
			printf("Case %d: A forest of %d trees.\n", cases, tree);
		}
	}

}