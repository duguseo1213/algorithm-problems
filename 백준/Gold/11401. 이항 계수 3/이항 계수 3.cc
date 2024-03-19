#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <unordered_map>
#include <cstring>

using namespace std;


int N, K;

long long dq(long long num,long long a)
{
	//printf("%lld", a);
	if (a == 1)
	{
		return num % 1000000007;
	}
	else if (a % 2 == 0)
	{
		long long temp = dq(num, a / 2);

		return temp*temp % 1000000007;
	}
	else
	{
		long long temp = dq(num, a / 2);
		return (temp*temp % 1000000007 *num) % 1000000007;
	}

}




int main()
{
	int N;
	scanf("%d %d", &N,&K);

	long long a=1;

	if (N - K > K) K = N - K;

	for (int i = 0; i < N-K; i++)
	{
		a =( a * (N-i)) % 1000000007;
	}

	long long b = 1;

	for (int i = 0; i < N - K; i++)
	{
		b=b*(N-K-i) % 1000000007;
	}

	//printf("%lld %lld\n", a, b);
	
	b = dq(b, 1000000005);

	printf("%lld", a*b % 1000000007);

}