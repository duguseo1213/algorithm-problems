#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;

map<long long, long long> dat;

vector<long long> a;
vector<long long> b;
vector<long long> c;
vector<long long> d;


void dfs1(int dep, long long sum,int s)
{
	
	c.push_back(sum);
	if (dep == a.size())
	{
		return;
	}

	for (int i = s; i < a.size(); i++)
	{
		dfs1(dep + 1, sum + a[i], i + 1);
	}

}

void dfs2(int dep, long long sum, int s)
{
	d.push_back(sum);
	if (dep == b.size())
	{
		return;
	}

	for (int i = s; i < b.size(); i++)
	{
		dfs2(dep + 1, sum + b[i], i + 1);
	}

}




long long N, target;

int main()
{
	cin >> N >> target;

	int temp;

	for (int i = 0; i < N / 2; i++)
	{
		scanf("%d", &temp);
		a.push_back(temp);
	}

	for (int i = N/2; i < N; i++)
	{
		scanf("%d", &temp);
		b.push_back(temp);
	}

	dfs1(0, 0, 0);
	dfs2(0, 0, 0);

	c.erase(c.begin());
	d.erase(d.begin());

	
	for (int i = 0; i < d.size(); i++)
	{
		dat[d[i]]++;
	}
	
	sort(d.begin(), d.begin() + d.size());

	
	long long answer = 0;

	for (int i = 0; i < c.size(); i++)
	{
		if (c[i] == target) answer++;
		int j = 0;
		int k = d.size()-1;

		while (1)
		{
			
			if (j > k)
			{
				break;
			}
			int mid = (j + k) / 2;
			if (d[mid] == target - c[i])
			{
				//cout << c[i] <<d[mid];
				answer += dat[d[mid]];
				//cout << answer;
				break;
			}
			else if (d[mid] > target - c[i])
			{
				k = mid - 1;
			}
			else
			{
				j = mid + 1;
			}
		}

	}
	answer += dat[target];
	cout << answer;
}