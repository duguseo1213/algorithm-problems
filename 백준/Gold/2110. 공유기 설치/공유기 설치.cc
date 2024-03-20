#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <unordered_map>

using namespace std;


int N, C;

vector<int> arr;

int main()
{
	scanf("%d %d", &N, &C);
	
	for (int i = 0; i < N; i++)
	{
		int temp;
		scanf("%d", &temp);
		arr.push_back(temp);



	}
	int i = 1;
	int j = 1000000000;

	int loc = arr[0];
	int cnt = 1;
	int mid = 10;

	sort(arr.begin(), arr.end());

	int dist=1;
	while (1)
	{
		if (j < i) break;
		int mid = (i + j) / 2;

		int loc = arr[0];
		int cnt = 1;

		for (int i = 1; i < arr.size(); i++)
		{
			if (arr[i] >= loc + mid)
			{
				cnt++;
				loc = arr[i];
			}
		}

		if (cnt < C)
		{
			j = mid - 1;
			
		}
		else if (cnt == C)
		{
			dist=mid;
			//printf("1");
			i = mid + 1;
		}
		else
		{
			dist =  mid;
			i = mid + 1;
		}



	}
	printf("%d", dist);

}
