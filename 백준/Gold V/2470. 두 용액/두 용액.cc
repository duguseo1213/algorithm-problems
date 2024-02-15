#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstdlib>
#define INF 987654321

using namespace std;

int arr[100000];
int N;
int minn = 21e8;
int a, b;
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}


	sort(arr, arr + N);
	int i = 0;
	int j = N - 1;
	while (1)
	{
		if (i >= j)
		{
			break;
		}

		if (minn > abs(arr[i] + arr[j]))
		{
			minn = abs(arr[i] + arr[j]);
			a = arr[i];
			b = arr[j];
		}
		
		if (arr[i] + arr[j] > 0)
		{
			j--;
		}
		else if (arr[i] + arr[j] < 0)
		{
			i++;
		}
		else
		{
			i++;
			j--;
		}

	}

	printf("%d %d", a, b);

}


