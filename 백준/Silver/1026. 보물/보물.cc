#define _CRT_SECURE_NO_WARNINGS
#define P printf
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <unordered_set>
#include <cmath>
using namespace std;

int N, M, X;

bool cmp(int a,int b)
{
	return a > b;
};

int a[100];
int b[100];

int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &b[i]);
	}

	sort(&a[0], &a[0] + N);

	sort(&b[0], &b[0] + N,cmp);


	int sum=0;

	for (int i = 0; i < N; i++)
	{
		sum += a[i] * b[i];

		//printf("%d %d\n", a[i], b[i]);

	}

	printf("%d", sum);

}
