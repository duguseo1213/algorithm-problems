#define _CRT_SECURE_NO_WARNINGS
#define P printf
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> vec;
pair<int, int> now;

long long sum;
int N;

int main()
{
	scanf("%d", &N);

	int a, b;

	for (int i = 0; i < N; i++)
	{
		scanf("%d %d", &a, &b);
		vec.push_back({ a,b });
	}

	sort(vec.begin(), vec.end());

	now = vec[0];

	for (int i = 1; i < vec.size(); i++)
	{
		//P("%d %d\n", now.first, now.second);

		if (vec[i].first > now.second)
		{
			sum = sum + (now.second - now.first);
			now.first = vec[i].first;
			now.second = vec[i].second;

		}
		else
		{
			if (vec[i].second > now.second)
			{
				now.second = vec[i].second;
			}
			else
			{

			}
		}



	}
	sum = sum + (now.second - now.first);

	printf("%lld", sum);


}