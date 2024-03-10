#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <set>
#include <vector>
#include <queue>
#define P printf 
using namespace std;

vector <pair<int, int>> datas;

priority_queue<pair<int, int>, vector<pair<int, int>>> maxheap;

priority_queue<pair<int, int>, vector<pair<int, int>>,greater<pair<int,int>>> minheap;

int N;
int main()
{
	int T;
	scanf("%d", &T);

	for (int t = 0; t < T; t++)
	{
		datas.clear();
		while (!maxheap.empty())
		{
			maxheap.pop();
		}
		while (!minheap.empty())
		{
			minheap.pop();
		}
		int dc = 0;
		char type;
		int num;
		scanf("%d", &N);
		getchar();
		int cnt = 0;
		for (int i = 0; i < N; i++)
		{
			scanf(" %c %d", &type, &num);
			//printf("%d\n", dc);
			if (type == 'I')
			{

				maxheap.push({ num,cnt });
				minheap.push({ num,cnt });
				datas.push_back({ num,1 });
				cnt++;
				dc++;
			}
			else
			{
				//printf("%d %d\n", maxheap.size(),minheap.size());
				if (dc == 0) continue;
				while (1)
				{
					if (datas[maxheap.top().second].second == 1) break;

					maxheap.pop();
				}
				while (1)
				{
					if (datas[minheap.top().second].second == 1) break;

					minheap.pop();
				}
				//printf("%d %d\n", maxheap.size(), minheap.size());

				if (num == 1)
				{



					datas[maxheap.top().second].second = 0;
					maxheap.pop();
				}
				else
				{

					datas[minheap.top().second].second = 0;
					minheap.pop();

				}
				dc--;
			}



		}



		if (dc == 0)
		{
			printf("EMPTY\n");
		}
		else
		{
			while (1)
			{
				if (datas[maxheap.top().second].second == 1) break;

				maxheap.pop();
			}
			while (1)
			{
				if (datas[minheap.top().second].second == 1) break;

				minheap.pop();
			}
			printf("%d %d\n", maxheap.top().first, minheap.top().first);
		}


	}
}