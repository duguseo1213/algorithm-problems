#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N;
long long d;

struct cmp2
{
	bool operator()(pair<long long, long long> a, pair<long long, long long> b)
	{
		return a.first > b.first;
	}
	
};



bool cmp(pair<long long, long long> a, pair<long long, long long> b)
{
	return a.second < b.second;
}


priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, cmp2> pq;

vector<pair<long long, long long>> vec;



int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		long long a, b;

		scanf("%lld %lld", &a, &b);

		if (a > b)
		{
			vec.push_back({ b,a });
		}
		else
		{
			vec.push_back({ a,b });
		}


	}
	scanf("%lld", &d);

	sort(vec.begin(), vec.end(), cmp);

	for (int i = 0; i < vec.size(); i++)
	{
		//printf("%lld %lld ",vec[i].first, vec[i].second);
	}



	int cnt = 0;
	int flag = 0;
	long long maxx = 0;
	while (flag==0)
	{
		if (!pq.empty())
		{
			pq.pop();
		}

		while (1)
		{
			if (pq.empty())
			{
				if (vec[cnt].second - vec[cnt].first<=d)
				{
					pq.push(vec[cnt]);
				}		
			}
			else
			{
				if (vec[cnt].second <= pq.top().first + d && vec[cnt].second - vec[cnt].first <= d)
				{
					pq.push(vec[cnt]);
				}
				else if(vec[cnt].second > pq.top().first + d)
				{
					break;
				}
			}



			cnt++;
			if (cnt == vec.size())
			{
				flag = 1;
				break;
			}
			
		}

		long long temp = pq.size();
		maxx = max(temp, maxx);
		//printf("%lld\n", temp);


	}
	printf("%lld", maxx);

}