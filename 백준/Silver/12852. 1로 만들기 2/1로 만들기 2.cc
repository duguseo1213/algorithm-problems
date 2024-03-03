#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <queue>
#include <cstring>
using namespace std;

int dp[1000001];

int parent[1000001];

queue<int> q;

int main()
{
	dp[1] = 1;
	q.push( 1 );
	while (!q.empty())
	{
		int temp = q.front();
		q.pop();

		if (temp*2<=1000000 && dp[temp * 2] == 0)
		{
			q.push(temp * 2);
			dp[temp * 2] = dp[temp] + 1;
			parent[temp * 2] = temp;
		}

		if (temp * 3 <= 1000000 && dp[temp * 3] == 0)
		{
			q.push(temp * 3);
			dp[temp * 3] = dp[temp] + 1;
			parent[temp * 3] = temp;
		}

		if (temp +1 <= 1000000 && dp[temp +1] == 0)
		{
			q.push(temp +1);
			dp[temp+1] = dp[temp] + 1;
			parent[temp +1] = temp;
		}
	}





	
	int N;
	cin >> N;
	cout << dp[N]-1 << endl;

	int a;
	while (1)
	{
		
		cout << N << " ";
		if (N == 1) break;
		N = parent[N];
	}

}