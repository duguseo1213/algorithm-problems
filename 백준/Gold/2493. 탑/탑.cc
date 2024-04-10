#define _CRT_SECURE_NO_WARNINGS
#define P printf

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<pair<int, int>> vec;

int arr[500001];
int answer[500001];
int N;

int main() 
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}

	vec.push_back({ arr[N - 1],N - 1 });


	for (int i = N - 2; i >= 0; i--)
	{
		while (vec.size()>0 && arr[i] > vec.back().first)
		{
			answer[vec.back().second] = i+1;
			vec.pop_back();
		}

		vec.push_back({ arr[i], i });


	}
	
	while (vec.size() > 0)
	{
		answer[vec.back().second] = 0;
		vec.pop_back();
	}

	for (int i = 0; i < N; i++)
	{
		P("%d ", answer[i]);
	}



}