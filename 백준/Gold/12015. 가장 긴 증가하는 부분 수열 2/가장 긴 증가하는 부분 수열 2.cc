
#define _CRT_SECURE_NO_WARNINGS
#define P printf

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <unordered_set>
#include <cmath>
using namespace std;

vector<int> vec;

int arr[1000001];

int N;

int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}

	vec.push_back(arr[0]);

	for (int i = 1; i < N; i++)
	{
		if (arr[i] > vec[vec.size() - 1])
		{
			vec.push_back(arr[i]);
		}
		else
		{
			int left = 0;
			int right = vec.size() - 1;
			int answer=0;
			while (1)
			{
				if (left > right)
				{
					break;
				}

				int mid = (left + right) / 2;

				if (vec[mid]<arr[i])
				{
					
					left = mid + 1;
				}
				else
				{
					answer = mid;
					right = mid - 1;
				}


				
			}

			vec[answer] = arr[i];

		}
		
	}

	for (int i = 0; i < vec.size(); i++)
	{
		//printf("%d ", vec[i]);
	}
	//printf("\n");
	printf("%d", vec.size());

}