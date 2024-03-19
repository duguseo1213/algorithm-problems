#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <unordered_map>
#include <cstring>

using namespace std;

unordered_map<int, int> um;

int arr[20];

int N;
vector<int> vec;
int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}
	
	for (int i = 1; i < (1 << N); i++)
	{
		int sum = 0;
		for (int j = 0; j < N; j++)
		{
			if (i&(1 << j))
			{
				sum += arr[j];
			}
		}
		vec.push_back(sum);
	}

	sort(vec.begin(), vec.end());
	int state = 0;
	for (int i = 0; i < vec.size(); i++)
	{
		um[vec[i]] = 1;
		

	}

	

	for (int i = 1; i <= 2000000; i++)
	{
		if (um[i] == 0)
		{
			printf("%d", i);
			break;
		}
	}

}