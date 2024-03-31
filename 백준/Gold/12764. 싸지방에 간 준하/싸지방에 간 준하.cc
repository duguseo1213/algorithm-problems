#define _CRT_SECURE_NO_WARNINGS
#define P 
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>



using namespace std;

struct PC {
	int start;
	int end;
	int num;
};

struct cmp {

	bool operator()(PC a, PC b)
	{
		return a.end > b.end;

	}

};


priority_queue<PC, vector<PC>, cmp> pq;
priority_queue<int, vector<int>, greater<int>> pqq;
int dat[100000];
int N;
int maxx = 0;
vector<pair<int, int>> vec;


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

	for (int i = 0; i < N; i++)
	{
		P("%d %d\n", vec[i].first, vec[i].second);
		
		if (pq.empty())
		{
			pq.push({ vec[i].first, vec[i].second, 0 });
			dat[0]++;
			maxx = 1;
		}

		else
		{
			if (pq.top().end > vec[i].first)
			{
				if (pqq.empty())
				{
					int temp2 = pq.size();
					dat[temp2]++;
					
					pq.push({ vec[i].first, vec[i].second, temp2 });
					int temp = pq.size();
					maxx = max(maxx, temp);
				}
				else
				{
					dat[pqq.top()]++;
					pq.push({ vec[i].first, vec[i].second, pqq.top() });
					pqq.pop();
				}



			}
			else
			{
				while (1)
				{
					pqq.push(pq.top().num);
					pq.pop();
					if (pq.empty() || pq.top().end > vec[i].first )
					{
						break;
					}

				}

				dat[pqq.top()]++;
				pq.push({ vec[i].first, vec[i].second, pqq.top() });
				pqq.pop();

			}



		}


	}

	printf("%d\n", maxx);
	for (int i = 0; i < maxx; i++)
	{
		printf("%d ", dat[i]);
	}




}