#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

vector<pair<int,int>> ans;

int arr[1000000];
int parent[1000000];




int N;
int main()
{
	scanf("%d", &N);
	int num;
	scanf("%d", &num);

	ans.push_back({ num,0 });
	arr[0] = num;
	parent[0] = 0;
	for (int k = 1; k < N; k++)
	{
		scanf("%d", &num);
		arr[k] = num;

		if (num > ans.back().first)
		{
			ans.push_back({num,k});
			
			parent[k] = k;
		}
		else
		{

			int i = 0;
			int j = ans.size() - 1;
			int index = -1;
			int flag = 0;
			while (1)
			{
				if (i > j) break;

				int mid = (i + j) / 2;
				if (ans[mid].first < num)
				{
					index = mid;
					i = mid + 1;

				}
				else
				{
					j = mid - 1;
				}

			}
			if (flag == 0)
			{
				ans[i].first = num;
				parent[k] = ans[i].second;
				ans[i].second = k;	
			}
			else
			{

			}

		}

		/*for (int i = 0; i < ans.size(); i++)
		{
			printf("%d ", ans[i]);
		}
		printf("\n");*/

	}
	printf("%d\n", ans.size());
	
	for (int i = ans.size() - 2; i >= 0; i--)
	{

		if (ans[i].second > ans[i + 1].second)
		{

			while (1)
			{
				ans[i].first = arr[parent[ans[i].second]];
				ans[i].second = parent[ans[i].second];

				if (ans[i].second < ans[i + 1].second)
				{
					break;
				}

			}
					   			 
		}

	}

	for (int i = 0; i < ans.size(); i++)
	{
		printf("%d ", ans[i].first);
	}


}
