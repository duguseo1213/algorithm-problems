#define _CRT_SECURE_NO_WARNINGS
#define P printf

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

unordered_map<int, int> um;

int N;
int arr[2001];

int main()
{

	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
		um[arr[i]]++;
	}
	int answer = 0;

	sort(&arr[0], &arr[0] + N);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (i == j) continue;

			int val = arr[i] - arr[j];
			
			if (um.find(val) != um.end())
			{
			//	printf("%d %d %d\n",arr[i],arr[j], val);
				if (val == 0 && arr[i] == 0)
				{
					if (um[val] > 2)
					{
						answer++;
						break;
					}
				}
				else if (val * 2 == arr[i])
				{
					
					if (um[val]>1)
					{
						answer++;
						break;
					}
				}
				else if (val == arr[i])
				{
					if (um[val] > 1)
					{
						answer++;
						break;
					}
				}
				
				else
				{
					answer++;
					break;
				}

			}

		}
	}
	   	 
	printf("%d", answer);

}