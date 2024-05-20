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

long long N;


int main()
{
	int T;
	scanf("%d", &T);

	for (int t = 1; t <= T; t++)
	{

		scanf("%lld", &N);
		long long left = 0;
		long long right = 2100000000;
		int state = 0;
		while (1)
		{
			if (right < left)
			{
				break;
			}

			long long mid = (left + right) / 2;

			if (mid*(mid + 1) / 2 == N)
			{
				state = 1;
				printf("#%lld %lld\n", t, mid);
				break;
			}
			else if (mid*(mid + 1) / 2 > N)
			{
				right = mid - 1;
			}
			else if (mid*(mid + 1) / 2 < N)
			{
				left = mid + 1;
			}
			//P("%lld\n", mid);
		}

		if (state == 0)
		{
			printf("#%lld -1\n", t);

		}
	}
}
