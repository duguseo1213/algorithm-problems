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

unordered_map<int, int> pls;

struct prob {
	//int id;
	int dead;
	int cupra;
};

struct cmp
{
	bool operator()(prob a, prob b)
	{
		if (a.cupra == b.cupra)
		{
			return  a.dead < b.dead;
		}


		return a.cupra < b.cupra;
	}
};

priority_queue<prob, vector<prob>, cmp> pq;

vector<prob> vec;

bool ccmp(prob a, prob b)
{
	return a.dead > b.dead;
}

int N;
long long answer = 0;
int main()
{
	scanf("%d", &N);

	prob p;

	for (int i = 0; i < N; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);

		vec.push_back({ a,b });

	}
	sort(vec.begin(), vec.end(), ccmp);
	int index = 0;
	int today = vec[index].dead;
	while(1)
	{
		

		while (1)
		{
			
			if (index == vec.size() || vec[index].dead<today)
			{
				break;
			}
			pq.push(vec[index]);
			index++;
		}
		if (!pq.empty())
		{

			answer += pq.top().cupra;
			P("%d ", pq.top().cupra);
			pq.pop();
		}
		today--;

		if (today == 0)
		{
			break;
		}


	}
	printf("%lld", answer);
}