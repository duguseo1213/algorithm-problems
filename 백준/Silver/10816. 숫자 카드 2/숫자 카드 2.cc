#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#define INF 987654321
using namespace std;

int N, M;
int a[500000];
int b[500000];
int dat[20000001];
/*
void func(int start,int end,int target)
{
	if (start > end)
	{
		cout << 0;
	}

	int mid = (start + end) / 2;

	if (b[mid] == target)
	{
		cout<<dat[]
	}
}*/

int main()
{
	cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &a[i]);
		dat[a[i]+10000000]++;
	}

	cin >> M;
	int temp;
	for (int i = 0; i < M; i++)
	{
		scanf("%d", &temp);
		cout << dat[temp+10000000] << " ";
	}
	
	
	
	



}





