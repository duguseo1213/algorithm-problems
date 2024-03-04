#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <queue>
#include <cstring>
using namespace std;

int arr[100001];

vector<int> vec;

vector<int> negative;

vector<int> positive;
int N;

bool cmp(int a,int b)
{
	return a > b;
}

int main()
{
	cin >> N;
	int temp;
	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &temp);

		if (temp == 1)
		{
			sum += 1;
		}
		else
		{
			if (temp <= 0)
			{
				negative.push_back(temp);
			}
			else
			{
				positive.push_back(temp);
			}
			
		}
	}

	sort(positive.begin(), positive.end(), cmp);

	sort(negative.begin(), negative.end());

	for (int i = 0; i < positive.size(); i=i+2)
	{
		if (i == positive.size() - 1)
		{
			sum += positive[i];
			break;
		}
		else
		{
			sum += positive[i] * positive[i + 1];
		}
	}

	for (int i = 0; i < negative.size(); i=i+2)
	{
		if (i == negative.size() - 1)
		{
			sum += negative[i];
			break;
		}
		else
		{
			sum += negative[i] * negative[i + 1];
		}
	}
	cout << sum;
	
}