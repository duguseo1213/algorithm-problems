#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

vector<int> ans;

int N;
int main()
{
	scanf("%d", &N);
	int num;
	scanf("%d", &num);

	ans.push_back(num);

	for (int k = 1; k < N; k++)
	{
		scanf("%d", &num);

		if (num > ans.back())
		{
			ans.push_back(num);
		}
		else
		{

			int i = 0;
			int j = ans.size() - 1;
			int index=-1;
			int flag = 0;
			while (1)
			{
				if (i > j) break;

				int mid = (i + j) / 2;
				if (ans[mid] < num)
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
				ans[i] = num;
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
	printf("%d", ans.size());


}
