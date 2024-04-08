#define _CRT_SECURE_NO_WARNINGS
#define P printf

#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

int N;
vector<int> vec;
long long minn = 9876543212345;

int q, w, e;


int main()
{
	scanf("%d", &N);
	int a;
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &a);
		vec.push_back(a);
	}

	sort(vec.begin(), vec.end());

	for (int i = 0; i < N - 2; i++)
	{
		for (int j = i + 2; j < N; j++)
		{
			long long sum = -(vec[i] + vec[j]);

			long long start = i+1;
			long long end = j - 1;
			long long mid;
			long long tempmin= 9876543212345;
			int idx;
			while (1)
			{
				if (end < start)
				{
					break;
				}
				mid = (start + end) / 2;
				
				if (tempmin > abs(vec[mid] - sum))
				{
					tempmin = abs(vec[mid] - sum);
					idx = mid;
				}


				if (vec[mid] > sum)
				{
					end = mid - 1;
				}
				else if(vec[mid]<sum)
				{
					start = mid + 1;
				}
				else
				{
					break;
				}
			}
			//P("%lld\n", tempmin);

			if (tempmin < minn)
			{

				minn=tempmin;

				q = i;
				w = idx;
				e = j;


			}
			




		}
	}
	//printf("%d\n", minn);
	printf("%d %d %d", vec[q],vec[w],vec[e]);
}