#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
using namespace std;

int N;
int arr[1000000];
long long answer;

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
		


	}

	int b, c;
	cin >> b >> c;

	for (int i = 0; i < N; i++)
	{
		arr[i] = arr[i] - b;
		answer++;
		if (arr[i] <= 0);
		else
		{
			answer += (arr[i] - 1) / c+1;
		}

	}

	
	cout << answer;
}