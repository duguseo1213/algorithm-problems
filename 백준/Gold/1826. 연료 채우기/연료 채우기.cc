#define _CRT_SECURE_NO_WARNINGS
#define P

#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
#include <vector>
#include <queue>
#include <cstring>
#include <unordered_map>
#include <map>

using namespace std;

vector<pair<int, int>> vec;

struct cmp {

	bool operator()(pair<int, int> a, pair<int, int> b)
	{
		return a.second < b.second;
	}

};


priority_queue<int, vector<int>> pq;

int L,fuel;

int main()
{
	int N;

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		vec.push_back({ a,b });
	}
	scanf("%d %d", &L, &fuel);

	sort(vec.begin(), vec.end());

	for (int i = 0; i < N; i++)
	{
		P("%d ", vec[i].first);
	}
	P("\n");
	for (int i = 0; i < N; i++)
	{
		P("%d ", vec[i].second);
	}
	int index = 0;
	int invalid=0;
	int answer = 0;
	while (fuel<L)
	{
		while ( index<vec.size() && vec[index].first <= fuel)
		{

			pq.push(vec[index].second);
			index++;
			
		}

		if (pq.empty())
		{
			invalid = 1;
			break;
		}

		fuel += pq.top();
		pq.pop();
		answer++;

	}

	if (invalid == 1)
	{
		printf("-1");
	}
	else
	{
		printf("%d", answer);
	}



}