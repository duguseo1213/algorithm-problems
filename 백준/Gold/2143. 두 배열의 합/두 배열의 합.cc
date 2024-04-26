#define _CRT_SECURE_NO_WARNINGS
#define P

#include <iostream>
#include <string>
#include <unordered_map>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int arr1[1010];
int arr2[1010];



vector<int> arrsum1;
vector<int> arrsum2;

int N;
long long answer;
int main()
{
	scanf("%d", &N);

	int A, B;
	scanf("%d", &A);
	int temp;
	for (int i = 0; i < A; i++)
	{
		scanf("%d", &arr1[i]);
		
	}

	for (int i = 0; i < A; i++)
	{
		int sum = 0;
		for (int j = i; j < A; j++)
		{
			sum = sum + arr1[j];
			arrsum1.push_back(sum);
		}

	}



	scanf("%d", &B);

	for (int i = 0; i < B; i++)
	{
		scanf("%d", &arr2[i]);

	}

	for (int i = 0; i < B; i++)
	{
		int sum = 0;
		for (int j = i; j < B; j++)
		{
			sum = sum + arr2[j];
			arrsum2.push_back(sum);
		}

	}

	sort(arrsum1.begin(), arrsum1.end());
	sort(arrsum2.begin(), arrsum2.end());

	for (int i = 0; i < arrsum1.size(); i++)
	{
		P("%d ", arrsum1[i]);
	}
	P("\n");
	for (int i = 0; i < arrsum2.size(); i++)
	{
		P("%d ", arrsum2[i]);
	}
	P("\n");



	for (int i = 0; i < arrsum1.size(); i++)
	{
		int target = N - arrsum1[i];

		int left=0, right=arrsum2.size()-1;
		

		int l=-1;
		int r=-1;
		int mid;
		while (1)
		{
			if (left > right)
			{
				break;
			}

			 mid = (left + right) / 2;

			if (arrsum2[mid] <= target)
			{
				left = mid + 1;
				l = mid;
			}
			else
			{
				right = mid - 1;
			}

		}
		left = 0;
		right = arrsum2.size() - 1;

		while (1)
		{
			if (left > right)
			{
				break;
			}

			mid = (left + right) / 2;

			if (arrsum2[mid] < target)
			{
				left = mid + 1;
			}
			else
			{
				right = mid - 1;
				r = mid;
			}

		}

		P("%d %d\n", r, l);

		if (r != -1 && l != -1)
		{
			answer = answer + l - r+1;
		}


	}

	printf("%lld", answer);






	




}
