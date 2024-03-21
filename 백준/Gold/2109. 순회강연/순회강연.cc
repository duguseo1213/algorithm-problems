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

priority_queue<pair<int, int>, vector<pair<int, int>>> pq;

bool cmp(pair<int, int> a, pair<int, int> b)
{
	if (a.second == b.second)
	{
		return a.first > b.first;
	}

	return a.second > b.second;


}


vector<pair<int, int>> vec;

int N;

int main()
{
	scanf("%d", &N);

	if (N == 0)
	{
		printf("0");
		
	}
	else
	{
		int first, second;

		for (int i = 0; i < N; i++)
		{
			scanf("%d %d", &first, &second);

			vec.push_back({ first,second });

		}
		sort(vec.begin(), vec.end(), cmp);
		/*for (int i = 0; i < n; i++)
		{
			printf("%d ", vec[i].second);


		}
		printf("\n");*/



		int now = vec[0].second;

		int sum = 0;

		for (int i = 0; i < N; i++)
		{

			if (now == vec[i].second)
			{
				pq.push(vec[i]);
			}
			else
			{
				
				int temp = now-vec[i].second;
				//printf("%d %d\n", sum,temp);

				while (!pq.empty())
				{
					sum += pq.top().first;
					pq.pop();
					temp--;
					if (temp == 0)
					{
						break;
					}

				}

				now = vec[i].second;
				
				pq.push(vec[i]);
			}

		}
		while (!pq.empty())
		{
			sum += pq.top().first;
			pq.pop();
			now--;
			if (now == 0)
			{
				break;
			}

		}
		

		printf("%d", sum);
	}
	







	
}