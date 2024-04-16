#define _CRT_SECURE_NO_WARNINGS
#define P //printf
#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
#include <vector>
#include <queue>
using namespace std;


int N, L;

priority_queue<pair<int, int>, vector<pair<int, int>>,greater<pair<int,int>>> pq;
int answer;
int main()
{
	scanf("%d %d", &N, &L);

	int a, b;

	for (int i = 0; i < N; i++)
	{
		scanf("%d %d", &a, &b);
		pq.push({ a,b });
	}
	int start = pq.top().first;

	while (!pq.empty())
	{

		if ((pq.top().second - start) % L == 0)
		{
			answer = answer + (pq.top().second - start) / L;
			start = pq.top().second ;
			
			P("1 ");
		}
		else
		{
			answer = answer + (pq.top().second - start) / L + 1;
			start += ((pq.top().second - start) / L +1)* L;
			P("2 ");
		}

		
		
		P("%d:%d\n ", start,answer);
		
		
		while (1)
		{
			if (pq.empty()) break;
			if (pq.top().second > start) break;

			pq.pop();
		}

		if (pq.empty()) break;

		if (start < pq.top().first)
		{
			start = pq.top().first;
		}
		
		



	}


	printf("%d", answer);




}