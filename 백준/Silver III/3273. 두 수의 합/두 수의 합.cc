#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#define INF 987654321


using namespace std;


int arr[100000];

int main()
{
	int cnt = 0;
	int N;
	int target;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}
	cin >> target;
	sort(arr, arr + N);
	int i = 0;
	int j = N - 1;
	int temp;
	while (1)
	{
		if (i >= j)
		{
			break;
		}
		temp = arr[i] + arr[j];
		if (temp > target)
		{
			j--;
		}
		else if (temp < target)
		{
			i++;
		}
		else
		{
			cnt++;
			if ((arr[i + 1] - arr[i]) > (arr[j] - arr[j - 1]))
			{
				j--;
			}
			else if ((arr[i + 1] - arr[i]) < (arr[j] - arr[j - 1]))
			{
				i++;
			}
			else
			{
				i++;
				j--;
			}
		}

	}
	cout << cnt;
}



