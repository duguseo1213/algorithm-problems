#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <unordered_set>
using namespace std;

int P, Q, K;

int sum;

long long merge(long long a)
{
	if (a == 1)
	{
		return 2;
	}

	long long temp = merge(a / 2);
	if (a % 2 == 0)
	{
		
		return (temp*temp)%sum;
	}
	else if (a % 2 == 1)
	{
		return temp * temp * 2 % sum;
	}

}

int main()
{
	int T;
	scanf("%d", &T);

	for (int t = 1; t <= T; t++)
	{

		scanf("%d %d %d", &P, &Q, &K);

		sum = P + Q;

		long long temp = merge(K);

		printf("#%d %lld\n",t, min(P*temp%sum, Q*temp%sum));
	}

}
