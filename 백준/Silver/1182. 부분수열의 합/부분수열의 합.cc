#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <set>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

int arr[20];

int main()
{
	int N, tar;

	cin >> N >> tar;

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}
	int cnt = 0;
	for (int i = 1; i < (1 << N); i++)
	{
		int sum = 0;

		for (int j = 0; j <N; j++)
		{
			if (i & (1 << j))
			{
				sum = sum + arr[j];
			}
		}

		if (tar == sum) cnt++;


	}
	cout << cnt;

}