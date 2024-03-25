#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <unordered_map>
#include <cstring>
#include <string>
#include <set>
#include <ctime>
#include <cstdlib>

using namespace std;
int N;
int arr[501];

vector<int> vec;

vector<int> dp;
int main()
{
	
	scanf("%d", &N);

	for (int i = 0; i < N; i++) //안꼬이는것중 최소 찾기
	{
		int a, b;
		scanf("%d %d", &a, &b);

		arr[a] = b;



	}

	for (int i = 1; i <= 500; i++)
	{
		if (arr[i] != 0)
		{
			vec.push_back(arr[i]);
		}
	}

	//printf("%d\n", vec.size());

	for (int i = 0; i < vec.size(); i++)
	{
		dp.push_back(1);
	}
	for (int i = 1; i < vec.size(); i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (vec[i] > vec[j])
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}
	int maxx = 0;
	for (int i = 0; i < vec.size(); i++)
	{
		//printf("%d ", vec[i]);
	}
	//printf("\n");
	for (int i = 0; i < vec.size(); i++)
	{
		//printf("%d ", dp[i]);
		maxx = max(maxx, dp[i]);
	}
	printf("%d", N - maxx);

}