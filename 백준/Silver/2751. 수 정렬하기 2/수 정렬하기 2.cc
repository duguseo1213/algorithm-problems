#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

bool cmp(int a,int b)
{
	return a < b;
}

vector<int> a;
int N;
int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		int temp;
		scanf("%d", &temp);
		a.push_back(temp);
	}

	sort(a.begin(), a.end(),cmp);

	for (int i = 0; i < N; i++)
	{
		printf("%d\n", a[i]);
	}



}
