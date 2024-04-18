#define _CRT_SECURE_NO_WARNINGS
#define P printf

#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
#include <vector>
#include <queue>
#include <cstring>
#include <unordered_map>
#include <map>

using namespace std;

long long ey, ex;
long long  a;
long long  b;

int main()
{
	scanf("%lld %lld %lld %lld", &ey, &ex, &a, &b);

	//가로세로 <= 대각

	if (a * 2 <= b)
	{
		printf("%lld", (ey + ex)*a);
	}
	else if (b > a)
	{
		long long  temp = min(ey, ex);
		long long  temp2 = max(ey, ex);
		long long  sum = temp * b + (temp2 - temp) * a;
		printf("%lld", sum);
	}
	else
	{
		
		long long  temp = min(ey, ex);
		long long  temp2 = max(ey, ex);
		long long  sum;
		if ((temp2 - temp) % 2 == 0)
		{
			sum = temp2 * b;
		}
		else
		{
			
			sum = temp * b + (temp2 - temp-1)* b + a;

		}
		printf("%lld", sum);

	}




}