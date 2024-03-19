#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <unordered_map>
#include <cstring>

using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
	int N;
	scanf("%d", &N);

	for (int j = 0; j < N; j++)
	{
		int temp;
		scanf("%d", &temp);
		pq.push(temp);

	}



	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int temp;
			scanf("%d", &temp);

			if (temp > pq.top())
			{
				pq.pop();
				pq.push(temp);
			}
			else
			{

			}

		}
	}
	printf("%d",pq.top());
	

}