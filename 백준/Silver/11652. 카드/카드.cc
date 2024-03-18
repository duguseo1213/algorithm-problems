#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <unordered_map>


using namespace std;

unordered_map<long long, long long> um;

long long N;
vector<long long> arr;

bool cmp(long long a,long long b)
{
	if (um[a] == um[b])
	{
		return a < b;
	}

	return um[a] > um[b];
}

int main()
{
	scanf("%lld", &N);

	for (int i = 0; i < N; i++)
	{
		long long temp;
		scanf("%lld", &temp);
		um[temp]++;
		//printf("temp: %lld\n", um[temp]);

	}

	for (auto i = um.begin(); i != um.end(); i++)
	{
		arr.push_back(i->first);
	}
	sort(arr.begin(), arr.end(), cmp);


	printf("%lld ", arr[0]);
	


}
