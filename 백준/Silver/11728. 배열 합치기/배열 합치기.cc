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

priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N+M; i++)
	{
		int temp;
		scanf("%d", &temp);
		pq.push(temp);
	}

	while (!pq.empty())
	{
		printf("%d ", pq.top());
		pq.pop();
	}

	
}