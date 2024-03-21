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

int arr1[101];
int arr2[101];

int visit[101];

int N;
int main()
{
	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
	{
		arr1[i] = i;
	}
	for (int i = 1; i <= N; i++)
	{
		int temp;
		scanf("%d", &arr2[i]);
	}

	for (int i = 1; i <= N; i++)
	{


		if (visit[i] == 0)
		{
			int start = i;
			int temp = i;
			int state = 0;
			int cnt = 0;
			while (1)
			{
				temp = arr2[temp];

				if (temp == start)
				{
					state = 1;
					break;
				}

				if (cnt==100)
				{
					break;
				}

				cnt++;
				

			}

			if (state == 1)
			{
				while (1)
				{
					temp = arr2[temp];

					if (temp == start)
					{
						visit[temp] = 1;
						break;
					}
					visit[temp] = 1;

				}
			}


		}
		


	}
	int answer = 0;
	for (int i = 1; i <= N; i++)
	{
		if (visit[i] == 1) answer++;
	}
	printf("%d\n", answer);
	for (int i = 1; i <= N; i++)
	{
		if (visit[i] == 1)
		{
			printf("%d\n", i);
		}
	}
	

}